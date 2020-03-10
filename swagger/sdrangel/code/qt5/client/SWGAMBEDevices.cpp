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


#include "SWGAMBEDevices.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGAMBEDevices::SWGAMBEDevices(QString* json) {
    init();
    this->fromJson(*json);
}

SWGAMBEDevices::SWGAMBEDevices() {
    nb_devices = 0;
    m_nb_devices_isSet = false;
    ambe_devices = nullptr;
    m_ambe_devices_isSet = false;
}

SWGAMBEDevices::~SWGAMBEDevices() {
    this->cleanup();
}

void
SWGAMBEDevices::init() {
    nb_devices = 0;
    m_nb_devices_isSet = false;
    ambe_devices = new QList<SWGAMBEDevice*>();
    m_ambe_devices_isSet = false;
}

void
SWGAMBEDevices::cleanup() {

    if(ambe_devices != nullptr) { 
        auto arr = ambe_devices;
        for(auto o: *arr) { 
            delete o;
        }
        delete ambe_devices;
    }
}

SWGAMBEDevices*
SWGAMBEDevices::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGAMBEDevices::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&nb_devices, pJson["nbDevices"], "qint32", "");
    
    
    ::SWGSDRangel::setValue(&ambe_devices, pJson["ambeDevices"], "QList", "SWGAMBEDevice");
}

QString
SWGAMBEDevices::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGAMBEDevices::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_nb_devices_isSet){
        obj->insert("nbDevices", QJsonValue(nb_devices));
    }
    if(ambe_devices && ambe_devices->size() > 0){
        toJsonArray((QList<void*>*)ambe_devices, obj, "ambeDevices", "SWGAMBEDevice");
    }

    return obj;
}

qint32
SWGAMBEDevices::getNbDevices() {
    return nb_devices;
}
void
SWGAMBEDevices::setNbDevices(qint32 nb_devices) {
    this->nb_devices = nb_devices;
    this->m_nb_devices_isSet = true;
}

QList<SWGAMBEDevice*>*
SWGAMBEDevices::getAmbeDevices() {
    return ambe_devices;
}
void
SWGAMBEDevices::setAmbeDevices(QList<SWGAMBEDevice*>* ambe_devices) {
    this->ambe_devices = ambe_devices;
    this->m_ambe_devices_isSet = true;
}


bool
SWGAMBEDevices::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_nb_devices_isSet){
            isObjectUpdated = true; break;
        }
        if(ambe_devices && (ambe_devices->size() > 0)){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

