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


#include "SWGSamplingDevice.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGSamplingDevice::SWGSamplingDevice(QString* json) {
    init();
    this->fromJson(*json);
}

SWGSamplingDevice::SWGSamplingDevice() {
    index = 0;
    m_index_isSet = false;
    hw_type = nullptr;
    m_hw_type_isSet = false;
    direction = 0;
    m_direction_isSet = false;
    device_nb_streams = 0;
    m_device_nb_streams_isSet = false;
    device_stream_index = 0;
    m_device_stream_index_isSet = false;
    sequence = 0;
    m_sequence_isSet = false;
    serial = nullptr;
    m_serial_isSet = false;
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    bandwidth = 0;
    m_bandwidth_isSet = false;
    state = nullptr;
    m_state_isSet = false;
    state_rx = nullptr;
    m_state_rx_isSet = false;
    state_tx = nullptr;
    m_state_tx_isSet = false;
}

SWGSamplingDevice::~SWGSamplingDevice() {
    this->cleanup();
}

void
SWGSamplingDevice::init() {
    index = 0;
    m_index_isSet = false;
    hw_type = new QString("");
    m_hw_type_isSet = false;
    direction = 0;
    m_direction_isSet = false;
    device_nb_streams = 0;
    m_device_nb_streams_isSet = false;
    device_stream_index = 0;
    m_device_stream_index_isSet = false;
    sequence = 0;
    m_sequence_isSet = false;
    serial = new QString("");
    m_serial_isSet = false;
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    bandwidth = 0;
    m_bandwidth_isSet = false;
    state = new QString("");
    m_state_isSet = false;
    state_rx = new QString("");
    m_state_rx_isSet = false;
    state_tx = new QString("");
    m_state_tx_isSet = false;
}

void
SWGSamplingDevice::cleanup() {

    if(hw_type != nullptr) { 
        delete hw_type;
    }




    if(serial != nullptr) { 
        delete serial;
    }


    if(state != nullptr) { 
        delete state;
    }
    if(state_rx != nullptr) { 
        delete state_rx;
    }
    if(state_tx != nullptr) { 
        delete state_tx;
    }
}

SWGSamplingDevice*
SWGSamplingDevice::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGSamplingDevice::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&index, pJson["index"], "qint32", "");
    
    ::SWGSDRangel::setValue(&hw_type, pJson["hwType"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&direction, pJson["direction"], "qint32", "");
    
    ::SWGSDRangel::setValue(&device_nb_streams, pJson["deviceNbStreams"], "qint32", "");
    
    ::SWGSDRangel::setValue(&device_stream_index, pJson["deviceStreamIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&sequence, pJson["sequence"], "qint32", "");
    
    ::SWGSDRangel::setValue(&serial, pJson["serial"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&center_frequency, pJson["centerFrequency"], "qint64", "");
    
    ::SWGSDRangel::setValue(&bandwidth, pJson["bandwidth"], "qint32", "");
    
    ::SWGSDRangel::setValue(&state, pJson["state"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&state_rx, pJson["stateRx"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&state_tx, pJson["stateTx"], "QString", "QString");
    
}

QString
SWGSamplingDevice::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGSamplingDevice::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_index_isSet){
        obj->insert("index", QJsonValue(index));
    }
    if(hw_type != nullptr && *hw_type != QString("")){
        toJsonValue(QString("hwType"), hw_type, obj, QString("QString"));
    }
    if(m_direction_isSet){
        obj->insert("direction", QJsonValue(direction));
    }
    if(m_device_nb_streams_isSet){
        obj->insert("deviceNbStreams", QJsonValue(device_nb_streams));
    }
    if(m_device_stream_index_isSet){
        obj->insert("deviceStreamIndex", QJsonValue(device_stream_index));
    }
    if(m_sequence_isSet){
        obj->insert("sequence", QJsonValue(sequence));
    }
    if(serial != nullptr && *serial != QString("")){
        toJsonValue(QString("serial"), serial, obj, QString("QString"));
    }
    if(m_center_frequency_isSet){
        obj->insert("centerFrequency", QJsonValue(center_frequency));
    }
    if(m_bandwidth_isSet){
        obj->insert("bandwidth", QJsonValue(bandwidth));
    }
    if(state != nullptr && *state != QString("")){
        toJsonValue(QString("state"), state, obj, QString("QString"));
    }
    if(state_rx != nullptr && *state_rx != QString("")){
        toJsonValue(QString("stateRx"), state_rx, obj, QString("QString"));
    }
    if(state_tx != nullptr && *state_tx != QString("")){
        toJsonValue(QString("stateTx"), state_tx, obj, QString("QString"));
    }

    return obj;
}

qint32
SWGSamplingDevice::getIndex() {
    return index;
}
void
SWGSamplingDevice::setIndex(qint32 index) {
    this->index = index;
    this->m_index_isSet = true;
}

QString*
SWGSamplingDevice::getHwType() {
    return hw_type;
}
void
SWGSamplingDevice::setHwType(QString* hw_type) {
    this->hw_type = hw_type;
    this->m_hw_type_isSet = true;
}

qint32
SWGSamplingDevice::getDirection() {
    return direction;
}
void
SWGSamplingDevice::setDirection(qint32 direction) {
    this->direction = direction;
    this->m_direction_isSet = true;
}

qint32
SWGSamplingDevice::getDeviceNbStreams() {
    return device_nb_streams;
}
void
SWGSamplingDevice::setDeviceNbStreams(qint32 device_nb_streams) {
    this->device_nb_streams = device_nb_streams;
    this->m_device_nb_streams_isSet = true;
}

qint32
SWGSamplingDevice::getDeviceStreamIndex() {
    return device_stream_index;
}
void
SWGSamplingDevice::setDeviceStreamIndex(qint32 device_stream_index) {
    this->device_stream_index = device_stream_index;
    this->m_device_stream_index_isSet = true;
}

qint32
SWGSamplingDevice::getSequence() {
    return sequence;
}
void
SWGSamplingDevice::setSequence(qint32 sequence) {
    this->sequence = sequence;
    this->m_sequence_isSet = true;
}

QString*
SWGSamplingDevice::getSerial() {
    return serial;
}
void
SWGSamplingDevice::setSerial(QString* serial) {
    this->serial = serial;
    this->m_serial_isSet = true;
}

qint64
SWGSamplingDevice::getCenterFrequency() {
    return center_frequency;
}
void
SWGSamplingDevice::setCenterFrequency(qint64 center_frequency) {
    this->center_frequency = center_frequency;
    this->m_center_frequency_isSet = true;
}

qint32
SWGSamplingDevice::getBandwidth() {
    return bandwidth;
}
void
SWGSamplingDevice::setBandwidth(qint32 bandwidth) {
    this->bandwidth = bandwidth;
    this->m_bandwidth_isSet = true;
}

QString*
SWGSamplingDevice::getState() {
    return state;
}
void
SWGSamplingDevice::setState(QString* state) {
    this->state = state;
    this->m_state_isSet = true;
}

QString*
SWGSamplingDevice::getStateRx() {
    return state_rx;
}
void
SWGSamplingDevice::setStateRx(QString* state_rx) {
    this->state_rx = state_rx;
    this->m_state_rx_isSet = true;
}

QString*
SWGSamplingDevice::getStateTx() {
    return state_tx;
}
void
SWGSamplingDevice::setStateTx(QString* state_tx) {
    this->state_tx = state_tx;
    this->m_state_tx_isSet = true;
}


bool
SWGSamplingDevice::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_index_isSet){
            isObjectUpdated = true; break;
        }
        if(hw_type && *hw_type != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_direction_isSet){
            isObjectUpdated = true; break;
        }
        if(m_device_nb_streams_isSet){
            isObjectUpdated = true; break;
        }
        if(m_device_stream_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_sequence_isSet){
            isObjectUpdated = true; break;
        }
        if(serial && *serial != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_center_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_bandwidth_isSet){
            isObjectUpdated = true; break;
        }
        if(state && *state != QString("")){
            isObjectUpdated = true; break;
        }
        if(state_rx && *state_rx != QString("")){
            isObjectUpdated = true; break;
        }
        if(state_tx && *state_tx != QString("")){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

