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


#include "SWGLimeRFEPower.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGLimeRFEPower::SWGLimeRFEPower(QString* json) {
    init();
    this->fromJson(*json);
}

SWGLimeRFEPower::SWGLimeRFEPower() {
    forward = 0;
    m_forward_isSet = false;
    reflected = 0;
    m_reflected_isSet = false;
}

SWGLimeRFEPower::~SWGLimeRFEPower() {
    this->cleanup();
}

void
SWGLimeRFEPower::init() {
    forward = 0;
    m_forward_isSet = false;
    reflected = 0;
    m_reflected_isSet = false;
}

void
SWGLimeRFEPower::cleanup() {


}

SWGLimeRFEPower*
SWGLimeRFEPower::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGLimeRFEPower::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&forward, pJson["forward"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reflected, pJson["reflected"], "qint32", "");
    
}

QString
SWGLimeRFEPower::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGLimeRFEPower::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_forward_isSet){
        obj->insert("forward", QJsonValue(forward));
    }
    if(m_reflected_isSet){
        obj->insert("reflected", QJsonValue(reflected));
    }

    return obj;
}

qint32
SWGLimeRFEPower::getForward() {
    return forward;
}
void
SWGLimeRFEPower::setForward(qint32 forward) {
    this->forward = forward;
    this->m_forward_isSet = true;
}

qint32
SWGLimeRFEPower::getReflected() {
    return reflected;
}
void
SWGLimeRFEPower::setReflected(qint32 reflected) {
    this->reflected = reflected;
    this->m_reflected_isSet = true;
}


bool
SWGLimeRFEPower::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_forward_isSet){
            isObjectUpdated = true; break;
        }
        if(m_reflected_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

