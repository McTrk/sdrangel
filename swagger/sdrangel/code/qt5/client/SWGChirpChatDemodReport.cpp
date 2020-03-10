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


#include "SWGChirpChatDemodReport.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGChirpChatDemodReport::SWGChirpChatDemodReport(QString* json) {
    init();
    this->fromJson(*json);
}

SWGChirpChatDemodReport::SWGChirpChatDemodReport() {
    channel_power_db = 0.0f;
    m_channel_power_db_isSet = false;
    noise_power_db = 0.0f;
    m_noise_power_db_isSet = false;
    signal_power_db = 0.0f;
    m_signal_power_db_isSet = false;
    snr_power_db = 0.0f;
    m_snr_power_db_isSet = false;
    channel_sample_rate = 0;
    m_channel_sample_rate_isSet = false;
    sync_word = 0;
    m_sync_word_isSet = false;
    has_crc = 0;
    m_has_crc_isSet = false;
    nb_parity_bits = 0;
    m_nb_parity_bits_isSet = false;
    packet_length = 0;
    m_packet_length_isSet = false;
    nb_symbols = 0;
    m_nb_symbols_isSet = false;
    nb_codewords = 0;
    m_nb_codewords_isSet = false;
    header_parity_status = 0;
    m_header_parity_status_isSet = false;
    header_crc_status = 0;
    m_header_crc_status_isSet = false;
    payload_parity_status = 0;
    m_payload_parity_status_isSet = false;
    payload_crc_status = 0;
    m_payload_crc_status_isSet = false;
    message_timestamp = nullptr;
    m_message_timestamp_isSet = false;
    message_string = nullptr;
    m_message_string_isSet = false;
    message_bytes = nullptr;
    m_message_bytes_isSet = false;
}

SWGChirpChatDemodReport::~SWGChirpChatDemodReport() {
    this->cleanup();
}

void
SWGChirpChatDemodReport::init() {
    channel_power_db = 0.0f;
    m_channel_power_db_isSet = false;
    noise_power_db = 0.0f;
    m_noise_power_db_isSet = false;
    signal_power_db = 0.0f;
    m_signal_power_db_isSet = false;
    snr_power_db = 0.0f;
    m_snr_power_db_isSet = false;
    channel_sample_rate = 0;
    m_channel_sample_rate_isSet = false;
    sync_word = 0;
    m_sync_word_isSet = false;
    has_crc = 0;
    m_has_crc_isSet = false;
    nb_parity_bits = 0;
    m_nb_parity_bits_isSet = false;
    packet_length = 0;
    m_packet_length_isSet = false;
    nb_symbols = 0;
    m_nb_symbols_isSet = false;
    nb_codewords = 0;
    m_nb_codewords_isSet = false;
    header_parity_status = 0;
    m_header_parity_status_isSet = false;
    header_crc_status = 0;
    m_header_crc_status_isSet = false;
    payload_parity_status = 0;
    m_payload_parity_status_isSet = false;
    payload_crc_status = 0;
    m_payload_crc_status_isSet = false;
    message_timestamp = new QString("");
    m_message_timestamp_isSet = false;
    message_string = new QString("");
    m_message_string_isSet = false;
    message_bytes = new QList<QString*>();
    m_message_bytes_isSet = false;
}

void
SWGChirpChatDemodReport::cleanup() {















    if(message_timestamp != nullptr) { 
        delete message_timestamp;
    }
    if(message_string != nullptr) { 
        delete message_string;
    }
    if(message_bytes != nullptr) { 
        auto arr = message_bytes;
        for(auto o: *arr) { 
            delete o;
        }
        delete message_bytes;
    }
}

SWGChirpChatDemodReport*
SWGChirpChatDemodReport::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGChirpChatDemodReport::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&channel_power_db, pJson["channelPowerDB"], "float", "");
    
    ::SWGSDRangel::setValue(&noise_power_db, pJson["noisePowerDB"], "float", "");
    
    ::SWGSDRangel::setValue(&signal_power_db, pJson["signalPowerDB"], "float", "");
    
    ::SWGSDRangel::setValue(&snr_power_db, pJson["snrPowerDB"], "float", "");
    
    ::SWGSDRangel::setValue(&channel_sample_rate, pJson["channelSampleRate"], "qint32", "");
    
    ::SWGSDRangel::setValue(&sync_word, pJson["syncWord"], "qint32", "");
    
    ::SWGSDRangel::setValue(&has_crc, pJson["hasCRC"], "qint32", "");
    
    ::SWGSDRangel::setValue(&nb_parity_bits, pJson["nbParityBits"], "qint32", "");
    
    ::SWGSDRangel::setValue(&packet_length, pJson["packetLength"], "qint32", "");
    
    ::SWGSDRangel::setValue(&nb_symbols, pJson["nbSymbols"], "qint32", "");
    
    ::SWGSDRangel::setValue(&nb_codewords, pJson["nbCodewords"], "qint32", "");
    
    ::SWGSDRangel::setValue(&header_parity_status, pJson["headerParityStatus"], "qint32", "");
    
    ::SWGSDRangel::setValue(&header_crc_status, pJson["headerCRCStatus"], "qint32", "");
    
    ::SWGSDRangel::setValue(&payload_parity_status, pJson["payloadParityStatus"], "qint32", "");
    
    ::SWGSDRangel::setValue(&payload_crc_status, pJson["payloadCRCStatus"], "qint32", "");
    
    ::SWGSDRangel::setValue(&message_timestamp, pJson["messageTimestamp"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&message_string, pJson["messageString"], "QString", "QString");
    
    
    ::SWGSDRangel::setValue(&message_bytes, pJson["messageBytes"], "QList", "QString");
}

QString
SWGChirpChatDemodReport::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGChirpChatDemodReport::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_channel_power_db_isSet){
        obj->insert("channelPowerDB", QJsonValue(channel_power_db));
    }
    if(m_noise_power_db_isSet){
        obj->insert("noisePowerDB", QJsonValue(noise_power_db));
    }
    if(m_signal_power_db_isSet){
        obj->insert("signalPowerDB", QJsonValue(signal_power_db));
    }
    if(m_snr_power_db_isSet){
        obj->insert("snrPowerDB", QJsonValue(snr_power_db));
    }
    if(m_channel_sample_rate_isSet){
        obj->insert("channelSampleRate", QJsonValue(channel_sample_rate));
    }
    if(m_sync_word_isSet){
        obj->insert("syncWord", QJsonValue(sync_word));
    }
    if(m_has_crc_isSet){
        obj->insert("hasCRC", QJsonValue(has_crc));
    }
    if(m_nb_parity_bits_isSet){
        obj->insert("nbParityBits", QJsonValue(nb_parity_bits));
    }
    if(m_packet_length_isSet){
        obj->insert("packetLength", QJsonValue(packet_length));
    }
    if(m_nb_symbols_isSet){
        obj->insert("nbSymbols", QJsonValue(nb_symbols));
    }
    if(m_nb_codewords_isSet){
        obj->insert("nbCodewords", QJsonValue(nb_codewords));
    }
    if(m_header_parity_status_isSet){
        obj->insert("headerParityStatus", QJsonValue(header_parity_status));
    }
    if(m_header_crc_status_isSet){
        obj->insert("headerCRCStatus", QJsonValue(header_crc_status));
    }
    if(m_payload_parity_status_isSet){
        obj->insert("payloadParityStatus", QJsonValue(payload_parity_status));
    }
    if(m_payload_crc_status_isSet){
        obj->insert("payloadCRCStatus", QJsonValue(payload_crc_status));
    }
    if(message_timestamp != nullptr && *message_timestamp != QString("")){
        toJsonValue(QString("messageTimestamp"), message_timestamp, obj, QString("QString"));
    }
    if(message_string != nullptr && *message_string != QString("")){
        toJsonValue(QString("messageString"), message_string, obj, QString("QString"));
    }
    if(message_bytes && message_bytes->size() > 0){
        toJsonArray((QList<void*>*)message_bytes, obj, "messageBytes", "QString");
    }

    return obj;
}

float
SWGChirpChatDemodReport::getChannelPowerDb() {
    return channel_power_db;
}
void
SWGChirpChatDemodReport::setChannelPowerDb(float channel_power_db) {
    this->channel_power_db = channel_power_db;
    this->m_channel_power_db_isSet = true;
}

float
SWGChirpChatDemodReport::getNoisePowerDb() {
    return noise_power_db;
}
void
SWGChirpChatDemodReport::setNoisePowerDb(float noise_power_db) {
    this->noise_power_db = noise_power_db;
    this->m_noise_power_db_isSet = true;
}

float
SWGChirpChatDemodReport::getSignalPowerDb() {
    return signal_power_db;
}
void
SWGChirpChatDemodReport::setSignalPowerDb(float signal_power_db) {
    this->signal_power_db = signal_power_db;
    this->m_signal_power_db_isSet = true;
}

float
SWGChirpChatDemodReport::getSnrPowerDb() {
    return snr_power_db;
}
void
SWGChirpChatDemodReport::setSnrPowerDb(float snr_power_db) {
    this->snr_power_db = snr_power_db;
    this->m_snr_power_db_isSet = true;
}

qint32
SWGChirpChatDemodReport::getChannelSampleRate() {
    return channel_sample_rate;
}
void
SWGChirpChatDemodReport::setChannelSampleRate(qint32 channel_sample_rate) {
    this->channel_sample_rate = channel_sample_rate;
    this->m_channel_sample_rate_isSet = true;
}

qint32
SWGChirpChatDemodReport::getSyncWord() {
    return sync_word;
}
void
SWGChirpChatDemodReport::setSyncWord(qint32 sync_word) {
    this->sync_word = sync_word;
    this->m_sync_word_isSet = true;
}

qint32
SWGChirpChatDemodReport::getHasCrc() {
    return has_crc;
}
void
SWGChirpChatDemodReport::setHasCrc(qint32 has_crc) {
    this->has_crc = has_crc;
    this->m_has_crc_isSet = true;
}

qint32
SWGChirpChatDemodReport::getNbParityBits() {
    return nb_parity_bits;
}
void
SWGChirpChatDemodReport::setNbParityBits(qint32 nb_parity_bits) {
    this->nb_parity_bits = nb_parity_bits;
    this->m_nb_parity_bits_isSet = true;
}

qint32
SWGChirpChatDemodReport::getPacketLength() {
    return packet_length;
}
void
SWGChirpChatDemodReport::setPacketLength(qint32 packet_length) {
    this->packet_length = packet_length;
    this->m_packet_length_isSet = true;
}

qint32
SWGChirpChatDemodReport::getNbSymbols() {
    return nb_symbols;
}
void
SWGChirpChatDemodReport::setNbSymbols(qint32 nb_symbols) {
    this->nb_symbols = nb_symbols;
    this->m_nb_symbols_isSet = true;
}

qint32
SWGChirpChatDemodReport::getNbCodewords() {
    return nb_codewords;
}
void
SWGChirpChatDemodReport::setNbCodewords(qint32 nb_codewords) {
    this->nb_codewords = nb_codewords;
    this->m_nb_codewords_isSet = true;
}

qint32
SWGChirpChatDemodReport::getHeaderParityStatus() {
    return header_parity_status;
}
void
SWGChirpChatDemodReport::setHeaderParityStatus(qint32 header_parity_status) {
    this->header_parity_status = header_parity_status;
    this->m_header_parity_status_isSet = true;
}

qint32
SWGChirpChatDemodReport::getHeaderCrcStatus() {
    return header_crc_status;
}
void
SWGChirpChatDemodReport::setHeaderCrcStatus(qint32 header_crc_status) {
    this->header_crc_status = header_crc_status;
    this->m_header_crc_status_isSet = true;
}

qint32
SWGChirpChatDemodReport::getPayloadParityStatus() {
    return payload_parity_status;
}
void
SWGChirpChatDemodReport::setPayloadParityStatus(qint32 payload_parity_status) {
    this->payload_parity_status = payload_parity_status;
    this->m_payload_parity_status_isSet = true;
}

qint32
SWGChirpChatDemodReport::getPayloadCrcStatus() {
    return payload_crc_status;
}
void
SWGChirpChatDemodReport::setPayloadCrcStatus(qint32 payload_crc_status) {
    this->payload_crc_status = payload_crc_status;
    this->m_payload_crc_status_isSet = true;
}

QString*
SWGChirpChatDemodReport::getMessageTimestamp() {
    return message_timestamp;
}
void
SWGChirpChatDemodReport::setMessageTimestamp(QString* message_timestamp) {
    this->message_timestamp = message_timestamp;
    this->m_message_timestamp_isSet = true;
}

QString*
SWGChirpChatDemodReport::getMessageString() {
    return message_string;
}
void
SWGChirpChatDemodReport::setMessageString(QString* message_string) {
    this->message_string = message_string;
    this->m_message_string_isSet = true;
}

QList<QString*>*
SWGChirpChatDemodReport::getMessageBytes() {
    return message_bytes;
}
void
SWGChirpChatDemodReport::setMessageBytes(QList<QString*>* message_bytes) {
    this->message_bytes = message_bytes;
    this->m_message_bytes_isSet = true;
}


bool
SWGChirpChatDemodReport::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_channel_power_db_isSet){
            isObjectUpdated = true; break;
        }
        if(m_noise_power_db_isSet){
            isObjectUpdated = true; break;
        }
        if(m_signal_power_db_isSet){
            isObjectUpdated = true; break;
        }
        if(m_snr_power_db_isSet){
            isObjectUpdated = true; break;
        }
        if(m_channel_sample_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_sync_word_isSet){
            isObjectUpdated = true; break;
        }
        if(m_has_crc_isSet){
            isObjectUpdated = true; break;
        }
        if(m_nb_parity_bits_isSet){
            isObjectUpdated = true; break;
        }
        if(m_packet_length_isSet){
            isObjectUpdated = true; break;
        }
        if(m_nb_symbols_isSet){
            isObjectUpdated = true; break;
        }
        if(m_nb_codewords_isSet){
            isObjectUpdated = true; break;
        }
        if(m_header_parity_status_isSet){
            isObjectUpdated = true; break;
        }
        if(m_header_crc_status_isSet){
            isObjectUpdated = true; break;
        }
        if(m_payload_parity_status_isSet){
            isObjectUpdated = true; break;
        }
        if(m_payload_crc_status_isSet){
            isObjectUpdated = true; break;
        }
        if(message_timestamp && *message_timestamp != QString("")){
            isObjectUpdated = true; break;
        }
        if(message_string && *message_string != QString("")){
            isObjectUpdated = true; break;
        }
        if(message_bytes && (message_bytes->size() > 0)){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

