/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 5.3.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGSSBDemodReport.h
 *
 * SSBDemod
 */

#ifndef SWGSSBDemodReport_H_
#define SWGSSBDemodReport_H_

#include <QJsonObject>



#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGSSBDemodReport: public SWGObject {
public:
    SWGSSBDemodReport();
    SWGSSBDemodReport(QString* json);
    virtual ~SWGSSBDemodReport();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGSSBDemodReport* fromJson(QString &jsonString) override;

    float getChannelPowerDb();
    void setChannelPowerDb(float channel_power_db);

    qint32 getSquelch();
    void setSquelch(qint32 squelch);

    qint32 getAudioSampleRate();
    void setAudioSampleRate(qint32 audio_sample_rate);

    qint32 getChannelSampleRate();
    void setChannelSampleRate(qint32 channel_sample_rate);


    virtual bool isSet() override;

private:
    float channel_power_db;
    bool m_channel_power_db_isSet;

    qint32 squelch;
    bool m_squelch_isSet;

    qint32 audio_sample_rate;
    bool m_audio_sample_rate_isSet;

    qint32 channel_sample_rate;
    bool m_channel_sample_rate_isSet;

};

}

#endif /* SWGSSBDemodReport_H_ */
