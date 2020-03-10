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


#include "SWGCWKeyerSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGCWKeyerSettings::SWGCWKeyerSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGCWKeyerSettings::SWGCWKeyerSettings() {
    sample_rate = 0;
    m_sample_rate_isSet = false;
    wpm = 0;
    m_wpm_isSet = false;
    mode = 0;
    m_mode_isSet = false;
    text = nullptr;
    m_text_isSet = false;
    loop = 0;
    m_loop_isSet = false;
    keyboard_iambic = 0;
    m_keyboard_iambic_isSet = false;
    dot_key = 0;
    m_dot_key_isSet = false;
    dot_key_modifiers = 0;
    m_dot_key_modifiers_isSet = false;
    dash_key = 0;
    m_dash_key_isSet = false;
    dash_key_modifiers = 0;
    m_dash_key_modifiers_isSet = false;
}

SWGCWKeyerSettings::~SWGCWKeyerSettings() {
    this->cleanup();
}

void
SWGCWKeyerSettings::init() {
    sample_rate = 0;
    m_sample_rate_isSet = false;
    wpm = 0;
    m_wpm_isSet = false;
    mode = 0;
    m_mode_isSet = false;
    text = new QString("");
    m_text_isSet = false;
    loop = 0;
    m_loop_isSet = false;
    keyboard_iambic = 0;
    m_keyboard_iambic_isSet = false;
    dot_key = 0;
    m_dot_key_isSet = false;
    dot_key_modifiers = 0;
    m_dot_key_modifiers_isSet = false;
    dash_key = 0;
    m_dash_key_isSet = false;
    dash_key_modifiers = 0;
    m_dash_key_modifiers_isSet = false;
}

void
SWGCWKeyerSettings::cleanup() {



    if(text != nullptr) { 
        delete text;
    }






}

SWGCWKeyerSettings*
SWGCWKeyerSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGCWKeyerSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&sample_rate, pJson["sampleRate"], "qint32", "");
    
    ::SWGSDRangel::setValue(&wpm, pJson["wpm"], "qint32", "");
    
    ::SWGSDRangel::setValue(&mode, pJson["mode"], "qint32", "");
    
    ::SWGSDRangel::setValue(&text, pJson["text"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&loop, pJson["loop"], "qint32", "");
    
    ::SWGSDRangel::setValue(&keyboard_iambic, pJson["keyboardIambic"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dot_key, pJson["dotKey"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dot_key_modifiers, pJson["dotKeyModifiers"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dash_key, pJson["dashKey"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dash_key_modifiers, pJson["dashKeyModifiers"], "qint32", "");
    
}

QString
SWGCWKeyerSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGCWKeyerSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_sample_rate_isSet){
        obj->insert("sampleRate", QJsonValue(sample_rate));
    }
    if(m_wpm_isSet){
        obj->insert("wpm", QJsonValue(wpm));
    }
    if(m_mode_isSet){
        obj->insert("mode", QJsonValue(mode));
    }
    if(text != nullptr && *text != QString("")){
        toJsonValue(QString("text"), text, obj, QString("QString"));
    }
    if(m_loop_isSet){
        obj->insert("loop", QJsonValue(loop));
    }
    if(m_keyboard_iambic_isSet){
        obj->insert("keyboardIambic", QJsonValue(keyboard_iambic));
    }
    if(m_dot_key_isSet){
        obj->insert("dotKey", QJsonValue(dot_key));
    }
    if(m_dot_key_modifiers_isSet){
        obj->insert("dotKeyModifiers", QJsonValue(dot_key_modifiers));
    }
    if(m_dash_key_isSet){
        obj->insert("dashKey", QJsonValue(dash_key));
    }
    if(m_dash_key_modifiers_isSet){
        obj->insert("dashKeyModifiers", QJsonValue(dash_key_modifiers));
    }

    return obj;
}

qint32
SWGCWKeyerSettings::getSampleRate() {
    return sample_rate;
}
void
SWGCWKeyerSettings::setSampleRate(qint32 sample_rate) {
    this->sample_rate = sample_rate;
    this->m_sample_rate_isSet = true;
}

qint32
SWGCWKeyerSettings::getWpm() {
    return wpm;
}
void
SWGCWKeyerSettings::setWpm(qint32 wpm) {
    this->wpm = wpm;
    this->m_wpm_isSet = true;
}

qint32
SWGCWKeyerSettings::getMode() {
    return mode;
}
void
SWGCWKeyerSettings::setMode(qint32 mode) {
    this->mode = mode;
    this->m_mode_isSet = true;
}

QString*
SWGCWKeyerSettings::getText() {
    return text;
}
void
SWGCWKeyerSettings::setText(QString* text) {
    this->text = text;
    this->m_text_isSet = true;
}

qint32
SWGCWKeyerSettings::getLoop() {
    return loop;
}
void
SWGCWKeyerSettings::setLoop(qint32 loop) {
    this->loop = loop;
    this->m_loop_isSet = true;
}

qint32
SWGCWKeyerSettings::getKeyboardIambic() {
    return keyboard_iambic;
}
void
SWGCWKeyerSettings::setKeyboardIambic(qint32 keyboard_iambic) {
    this->keyboard_iambic = keyboard_iambic;
    this->m_keyboard_iambic_isSet = true;
}

qint32
SWGCWKeyerSettings::getDotKey() {
    return dot_key;
}
void
SWGCWKeyerSettings::setDotKey(qint32 dot_key) {
    this->dot_key = dot_key;
    this->m_dot_key_isSet = true;
}

qint32
SWGCWKeyerSettings::getDotKeyModifiers() {
    return dot_key_modifiers;
}
void
SWGCWKeyerSettings::setDotKeyModifiers(qint32 dot_key_modifiers) {
    this->dot_key_modifiers = dot_key_modifiers;
    this->m_dot_key_modifiers_isSet = true;
}

qint32
SWGCWKeyerSettings::getDashKey() {
    return dash_key;
}
void
SWGCWKeyerSettings::setDashKey(qint32 dash_key) {
    this->dash_key = dash_key;
    this->m_dash_key_isSet = true;
}

qint32
SWGCWKeyerSettings::getDashKeyModifiers() {
    return dash_key_modifiers;
}
void
SWGCWKeyerSettings::setDashKeyModifiers(qint32 dash_key_modifiers) {
    this->dash_key_modifiers = dash_key_modifiers;
    this->m_dash_key_modifiers_isSet = true;
}


bool
SWGCWKeyerSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_sample_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_wpm_isSet){
            isObjectUpdated = true; break;
        }
        if(m_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(text && *text != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_loop_isSet){
            isObjectUpdated = true; break;
        }
        if(m_keyboard_iambic_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dot_key_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dot_key_modifiers_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dash_key_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dash_key_modifiers_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

