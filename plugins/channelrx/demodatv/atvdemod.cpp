///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 F4HKW                                                      //
// for F4EXB / SDRAngel                                                          //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include "atvdemod.h"

#include <QTime>
#include <QDebug>
#include <stdio.h>
#include <complex.h>
#include "audio/audiooutput.h"
#include "dsp/dspengine.h"
#include "dsp/pidcontroller.h"

MESSAGE_CLASS_DEFINITION(ATVDemod::MsgConfigureATVDemod, Message)
MESSAGE_CLASS_DEFINITION(ATVDemod::MsgConfigureRFATVDemod, Message)

const float ATVDemod::m_fltSecondToUs = 1000000.0f;
const int ATVDemod::m_ssbFftLen = 1024;

ATVDemod::ATVDemod() :
    m_objSettingsMutex(QMutex::NonRecursive),
    m_objRegisteredATVScreen(NULL),
    m_intImageIndex(0),
    m_intColIndex(0),
    m_intRowIndex(0),
    m_intSynchroPoints(0),
    m_blnSynchroDetected(false),
    m_blnLineSynchronized(false),
    m_blnVerticalSynchroDetected(false),
    m_intRowsLimit(0),
    m_blnImageDetecting(false),
    m_fltEffMin(2000000000.0f),
    m_fltEffMax(-2000000000.0f),
    m_fltAmpMin(-2000000000.0f),
    m_fltAmpMax(2000000000.0f),
    m_fltAmpDelta(1.0),
    m_fltAmpLineAverage(0.0f),
    m_intNumberSamplePerTop(0),
    m_interpolatorDistanceRemain(0.0f),
    m_interpolatorDistance(1.0f),
    m_DSBFilter(0),
    m_DSBFilterBuffer(0),
    m_DSBFilterBufferIndex(0)
{
    setObjectName("ATVDemod");

    //*************** ATV PARAMETERS  ***************
    m_intNumberSamplePerLine=0;
    m_intSynchroPoints=0;
    m_intNumberOfLines=0;
    m_intNumberOfRowsToDisplay=0;
    m_intTVSampleRate = 0;

    m_objMagSqAverage.resize(32, 1.0);

    m_DSBFilter = new fftfilt((2.0f * m_objRFConfig.m_fltRFBandwidth) / 1000000, 2 * m_ssbFftLen); // arbitrary 1 MS/s sample rate
    m_DSBFilterBuffer = new Complex[m_ssbFftLen];
    memset(m_DSBFilterBuffer, 0, sizeof(Complex)*(m_ssbFftLen));

    memset((void*)m_fltBufferI,0,6*sizeof(float));
    memset((void*)m_fltBufferQ,0,6*sizeof(float));
}

ATVDemod::~ATVDemod()
{
}

bool ATVDemod::setATVScreen(ATVScreen *objScreen)
{
    m_objRegisteredATVScreen = objScreen;
}

void ATVDemod::configure(
        MessageQueue* objMessageQueue,
        float fltLineDurationUs,
        float fltTopDurationUs,
        float fltFramePerS,
        float fltRatioOfRowsToDisplay,
        float fltVoltLevelSynchroTop,
        float fltVoltLevelSynchroBlack,
        bool blnHSync,
        bool blnVSync)
{
    Message* msgCmd = MsgConfigureATVDemod::create(
            fltLineDurationUs,
            fltTopDurationUs,
            fltFramePerS,
            fltRatioOfRowsToDisplay,
            fltVoltLevelSynchroTop,
            fltVoltLevelSynchroBlack,
            blnHSync,
            blnVSync);
    objMessageQueue->push(msgCmd);
}

void ATVDemod::configureRF(
        MessageQueue* objMessageQueue,
        ATVModulation enmModulation,
        float fltRFBandwidth,
        float fltRFOppBandwidth,
        bool blnFFTFiltering,
        bool blnDecimatorEnable)
{
    Message* msgCmd = MsgConfigureRFATVDemod::create(
            enmModulation,
            fltRFBandwidth,
            fltRFOppBandwidth,
            blnFFTFiltering,
            blnDecimatorEnable);
    objMessageQueue->push(msgCmd);
}

void ATVDemod::feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end, bool firstOfBurst)
{
    float fltDivSynchroBlack = 1.0f - m_objRunning.m_fltVoltLevelSynchroBlack;
    float fltI;
    float fltQ;
    float fltNormI;
    float fltNormQ;

    float fltNorm=0.00f;
    float fltVal;
    int intVal;

    qint16 * ptrBufferToRelease=NULL;

    bool blnComputeImage=false;

    int intSynchroTimeSamples= (3*m_intNumberSamplePerLine)/4;
    float fltSynchroTrameLevel =  0.5f*((float)intSynchroTimeSamples) * m_objRunning.m_fltVoltLevelSynchroBlack;

    //********** Let's rock and roll buddy ! **********

    m_objSettingsMutex.lock();


    //********** Accessing ATV Screen context **********

    if(m_intImageIndex==0)
    {
        if(m_intNumberOfLines%2==1)
        {
            m_intRowsLimit = m_intNumberOfLines;
        }
        else
        {
            m_intRowsLimit = m_intNumberOfLines-2;
        }
    }

#ifdef EXTENDED_DIRECT_SAMPLE

    qint16 * ptrBuffer;
    qint32 intLen;

    //********** Reading direct samples **********

    SampleVector::const_iterator it = begin;
    intLen = it->intLen;
    ptrBuffer = it->ptrBuffer;
    ptrBufferToRelease = ptrBuffer;
    ++it;

    for(qint32 intInd=0; intInd<intLen-1; intInd +=2)
    {

        fltI= ((qint32) (*ptrBuffer)) << 4;
        ptrBuffer ++;
        fltQ= ((qint32) (*ptrBuffer)) << 4;
        ptrBuffer ++;

#else

    for (SampleVector::const_iterator it = begin; it != end; ++it /* ++it **/)
    {

        fltI = it->real();
        fltQ = it->imag();
#endif
        if (m_objRFRunning.m_intFrequencyOffset != 0)
        {
            m_nco.nextIQMul(fltI, fltQ);
        }

        //********** demodulation **********

        double magSq = fltI*fltI + fltQ*fltQ;
        m_objMagSqAverage.feed(magSq);

        fltNorm = sqrt(magSq);

        if ((m_objRFRunning.m_enmModulation == ATV_FM1) || (m_objRFRunning.m_enmModulation == ATV_FM2))
        {
            //Amplitude FM

            fltNormI= fltI/fltNorm;
            fltNormQ= fltQ/fltNorm;

            //-2 > 2 : 0 -> 1 volt
            //0->0.3 synchro  0.3->1 image

            if (m_objRFRunning.m_enmModulation == ATV_FM1)
            {
                //YDiff Cd
                fltVal = m_fltBufferI[0]*(fltNormQ - m_fltBufferQ[1]);
                fltVal -= m_fltBufferQ[0]*(fltNormI - m_fltBufferI[1]);

                fltVal += 2.0f;
                fltVal /=4.0f;

            }
            else
            {
                //YDiff Folded
                fltVal =  m_fltBufferI[2]*((m_fltBufferQ[5]-fltNormQ)/16.0f + m_fltBufferQ[1] - m_fltBufferQ[3]);
                fltVal -= m_fltBufferQ[2]*((m_fltBufferI[5]-fltNormI)/16.0f + m_fltBufferI[1] - m_fltBufferI[3]);

                fltVal += 2.125f;
                fltVal /=4.25f;

                m_fltBufferI[5]=m_fltBufferI[4];
                m_fltBufferQ[5]=m_fltBufferQ[4];

                m_fltBufferI[4]=m_fltBufferI[3];
                m_fltBufferQ[4]=m_fltBufferQ[3];

                m_fltBufferI[3]=m_fltBufferI[2];
                m_fltBufferQ[3]=m_fltBufferQ[2];

                m_fltBufferI[2]=m_fltBufferI[1];
                m_fltBufferQ[2]=m_fltBufferQ[1];
            }

            m_fltBufferI[1]=m_fltBufferI[0];
            m_fltBufferQ[1]=m_fltBufferQ[0];

            m_fltBufferI[0]=fltNormI;
            m_fltBufferQ[0]=fltNormQ;

        }
        else if ((m_objRFRunning.m_enmModulation == ATV_AM) || (m_objRFRunning.m_enmModulation == ATV_VAMU) || (m_objRFRunning.m_enmModulation == ATV_VAML))
        {
            //Amplitude AM
            fltVal = fltNorm;

            //********** Mini and Maxi Amplitude tracking **********

            if(fltVal<m_fltEffMin)
            {
                m_fltEffMin=fltVal;
            }

            if(fltVal>m_fltEffMax)
            {
                m_fltEffMax=fltVal;
            }

            //Normalisation
            fltVal -= m_fltAmpMin;
            fltVal /=m_fltAmpDelta;
        }
        else
        {
            fltVal = 0.0f;
        }

        m_fltAmpLineAverage += fltVal;

        //********** gray level **********
        //-0.3 -> 0.7
        intVal = (int) 255.0*(fltVal - m_objRunning.m_fltVoltLevelSynchroBlack) / fltDivSynchroBlack;

        //0 -> 255
        if(intVal<0)
        {
            intVal=0;
        }
        else if(intVal>255)
        {
            intVal=255;
        }

        //********** Filling pixels **********

        blnComputeImage = (m_objRunning.m_fltRatioOfRowsToDisplay != 0.5f);

        if (!blnComputeImage)
        {
            blnComputeImage = ((m_intImageIndex/2) % 2 == 0);
        }

        if (blnComputeImage)
        {
            m_objRegisteredATVScreen->setDataColor(m_intColIndex,intVal, intVal, intVal);
        }

        m_intColIndex++;

        //////////////////////

        m_blnSynchroDetected=false;
        if((m_objRunning.m_blnHSync) && (m_intRowIndex>1))
        {
            //********** Line Synchro  0-0-0 -> 0.3-0.3 0.3 **********
            if(m_blnImageDetecting==false)
            {
                //Floor Detection 0
                if (fltVal <= m_objRunning.m_fltVoltLevelSynchroTop)
                {
                    m_intSynchroPoints ++;
                }
                else
                {
                    m_intSynchroPoints=0;
                }

                if(m_intSynchroPoints>=m_intNumberSamplePerTop)
                {
                    m_blnSynchroDetected=true;
                    m_blnImageDetecting=true;
                    m_intSynchroPoints=0;
                }
            }
            else
            {
                //Image detection Sub Black 0.3
                if (fltVal >= m_objRunning.m_fltVoltLevelSynchroBlack)
                {
                    m_intSynchroPoints ++;
                }
                else
                {
                    m_intSynchroPoints=0;
                }

                if(m_intSynchroPoints>=m_intNumberSamplePerTop)
                {
                    m_blnSynchroDetected=false;
                    m_blnImageDetecting=false;
                    m_intSynchroPoints=0;
                }
            }
        }

        //********** Rendering if necessary **********

        // Vertical Synchro : 3/4 a line necessary
        if(!m_blnVerticalSynchroDetected && m_objRunning.m_blnVSync)
        {
           if(m_intColIndex>=intSynchroTimeSamples)
           {
                if(m_fltAmpLineAverage<=fltSynchroTrameLevel) //(m_fltLevelSynchroBlack*(float)(m_intColIndex-((m_intNumberSamplePerLine*12)/64)))) //75
                {
                    m_blnVerticalSynchroDetected=true;

                    m_intRowIndex=m_intImageIndex%2;

                    if(blnComputeImage)
                    {
                        m_objRegisteredATVScreen->selectRow(m_intRowIndex);
                    }
                }
            }
        }


        //Horizontal Synchro
        if((m_intColIndex>=m_intNumberSamplePerLine)
           || (m_blnSynchroDetected==true))
        {
            m_blnSynchroDetected=false;
            m_blnImageDetecting=true;

            m_intColIndex=0;

            if((m_blnSynchroDetected==false) || (m_blnLineSynchronized==true))
            {
                //New line + Interleaving
                m_intRowIndex ++;
                m_intRowIndex ++;

                if(m_intRowIndex<m_intNumberOfLines)
                {
                    m_objRegisteredATVScreen->selectRow(m_intRowIndex);
                }

                m_blnLineSynchronized=false;
            }
            else
            {
                m_blnLineSynchronized=m_blnSynchroDetected;
            }

            m_fltAmpLineAverage=0.0f;

        }

        //////////////////////

        if(m_intRowIndex>=m_intRowsLimit)
        {

             m_blnVerticalSynchroDetected=false;

             m_fltAmpLineAverage=0.0f;

            //Interleave Odd/Even images
            m_intRowIndex=m_intImageIndex%2;
            m_intColIndex=0;

            if(blnComputeImage)
            {
                m_objRegisteredATVScreen->selectRow(m_intRowIndex);
            }

            //Rendering when odd image processed
            if(m_intImageIndex%2==1)
            {
                //interleave
                if(blnComputeImage)
                {
                    m_objRegisteredATVScreen->renderImage(NULL);
                }

                m_intRowsLimit = m_intNumberOfLines-1;

                if (m_objRFRunning.m_enmModulation == ATV_AM)
                {
                    m_fltAmpMin=m_fltEffMin;
                    m_fltAmpMax=m_fltEffMax;
                    m_fltAmpDelta=m_fltEffMax-m_fltEffMin;

                    if(m_fltAmpDelta<=0.0)
                    {
                        m_fltAmpDelta=1.0f;
                    }

                    //Reset extrema
                    m_fltEffMin=2000000.0f;
                    m_fltEffMax=-2000000.0f;
                }
            }
            else
            {
                if(m_intNumberOfLines%2==1)
                {
                    m_intRowsLimit = m_intNumberOfLines;
                }
                else
                {
                    m_intRowsLimit = m_intNumberOfLines-2;
                }
            }

            m_intImageIndex ++;
        }

        //////////////////////
    }

    if(ptrBufferToRelease!=NULL)
    {
        delete ptrBufferToRelease;
    }

    m_objSettingsMutex.unlock();

}

void ATVDemod::start()
{
    //m_objTimer.start();
}

void ATVDemod::stop()
{
}

bool ATVDemod::handleMessage(const Message& cmd)
{
    qDebug() << "ATVDemod::handleMessage";

    if (DownChannelizer::MsgChannelizerNotification::match(cmd))
    {
        DownChannelizer::MsgChannelizerNotification& objNotif = (DownChannelizer::MsgChannelizerNotification&) cmd;
        m_objConfig.m_intSampleRate = objNotif.getSampleRate();
        m_objRFConfig.m_intFrequencyOffset = objNotif.getFrequencyOffset();

        qDebug() << "ATVDemod::handleMessage: MsgChannelizerNotification:"
                << " m_intSampleRate: " << m_objConfig.m_intSampleRate
                << " m_intFrequencyOffset: " << m_objRFConfig.m_intFrequencyOffset;

        applySettings();

        return true;
    }
    else if (MsgConfigureATVDemod::match(cmd))
    {
        MsgConfigureATVDemod& objCfg = (MsgConfigureATVDemod&) cmd;

        m_objConfig = objCfg.m_objMsgConfig;

        qDebug()  << "ATVDemod::handleMessage: MsgConfigureATVDemod:"
                << " m_fltVoltLevelSynchroBlack" << m_objConfig.m_fltVoltLevelSynchroBlack
                << " m_fltVoltLevelSynchroTop" << m_objConfig.m_fltVoltLevelSynchroTop
                << " m_fltFramePerS" << m_objConfig.m_fltFramePerS
                << " m_fltLineDurationUs" << m_objConfig.m_fltLineDurationUs
                << " m_fltRatioOfRowsToDisplay" << m_objConfig.m_fltRatioOfRowsToDisplay
                << " m_fltTopDurationUs" << m_objConfig.m_fltTopDurationUs
                << " m_blnHSync" << m_objConfig.m_blnHSync
                << " m_blnVSync" << m_objConfig.m_blnVSync;

        applySettings();

        return true;
    }
    else if (MsgConfigureRFATVDemod::match(cmd))
    {
        MsgConfigureRFATVDemod& objCfg = (MsgConfigureRFATVDemod&) cmd;

        m_objRFConfig = objCfg.m_objMsgConfig;

        qDebug()  << "ATVDemod::handleMessage: MsgConfigureRFATVDemod:"
                << " m_enmModulation" << m_objRFConfig.m_enmModulation
                << " m_fltRFBandwidth" << m_objRFConfig.m_fltRFBandwidth
                << " m_fltRFOppBandwidth" << m_objRFConfig.m_fltRFOppBandwidth
                << " m_blnFFTFiltering" << m_objRFConfig.m_blnFFTFiltering
                << " m_blnDecimatorEnable" << m_objRFConfig.m_blndecimatorEnable;

        applySettings();

        return true;
    }
    else
    {
        return false;
    }
}

void ATVDemod::applySettings()
{

    if (m_objConfig.m_intSampleRate == 0)
    {
        return;
    }

    if((m_objRFConfig.m_intFrequencyOffset != m_objRFRunning.m_intFrequencyOffset) ||
        (m_objConfig.m_intSampleRate != m_objRunning.m_intSampleRate))
    {
        m_nco.setFreq(-m_objRFConfig.m_intFrequencyOffset, m_objConfig.m_intSampleRate);
    }

    if ((m_objConfig.m_intSampleRate != m_objRunning.m_intSampleRate)
        || (m_objRFConfig.m_fltRFBandwidth != m_objRFRunning.m_fltRFBandwidth))
    {
        m_intTVSampleRate = (m_objConfig.m_intSampleRate / 1000000) * 1000000; // make sure working sample rate is a multiple of rate units

        if (m_intTVSampleRate > 0)
        {
            m_interpolatorDistance = (Real) m_intTVSampleRate / (Real) m_objConfig.m_intSampleRate;
        }
        else
        {
            m_intTVSampleRate = m_objConfig.m_intSampleRate;
            m_interpolatorDistanceRemain = 0;
            m_interpolatorDistance = 1.0f;
        }

        m_interpolatorDistanceRemain = 0;
        m_interpolator.create(48, m_intTVSampleRate, m_objRFConfig.m_fltRFBandwidth / 2.2, 3.0);
    }

    if((m_objConfig.m_fltFramePerS != m_objRunning.m_fltFramePerS)
       || (m_objConfig.m_fltLineDurationUs != m_objRunning.m_fltLineDurationUs)
       || (m_objConfig.m_intSampleRate != m_objRunning.m_intSampleRate)
       || (m_objConfig.m_fltTopDurationUs != m_objRunning.m_fltTopDurationUs)
       || (m_objConfig.m_fltRatioOfRowsToDisplay != m_objRunning.m_fltRatioOfRowsToDisplay))
    {
        m_objSettingsMutex.lock();

        m_intNumberSamplePerLine = (int) ((m_objConfig.m_fltLineDurationUs * m_objConfig.m_intSampleRate) / m_fltSecondToUs);
        m_intNumberOfLines = (int) ((m_fltSecondToUs / m_objConfig.m_fltFramePerS) /round(m_objConfig.m_fltLineDurationUs));
        m_objRegisteredATVScreen->resizeATVScreen(m_intNumberSamplePerLine, m_intNumberOfLines);
        m_intNumberSamplePerTop = (int) ((m_objConfig.m_fltTopDurationUs * m_objConfig.m_intSampleRate) / m_fltSecondToUs);
        m_intNumberOfRowsToDisplay = (int) ((m_objConfig.m_fltRatioOfRowsToDisplay * m_objConfig.m_fltLineDurationUs * m_objConfig.m_intSampleRate) / m_fltSecondToUs);

        m_intRowsLimit = m_intNumberOfLines-1;
        m_intImageIndex = 0;
        m_intColIndex=0;
        m_intRowIndex=0;
        m_intRowsLimit=0;

        m_objSettingsMutex.unlock();
    }

    m_objRunning = m_objConfig;
    m_objRFRunning = m_objRFConfig;
}

int ATVDemod::getSampleRate()
{
    return m_objRunning.m_intSampleRate;
}

