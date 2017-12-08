/**
 * SDRangel
 * This is the web API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube
 *
 * OpenAPI spec version: 4.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

#ifndef _SWG_SWGDeviceSetApi_H_
#define _SWG_SWGDeviceSetApi_H_

#include "SWGHttpRequest.h"

#include "SWGDeviceListItem.h"
#include "SWGDeviceSet.h"
#include "SWGDeviceSettings.h"
#include "SWGDeviceState.h"
#include "SWGErrorResponse.h"

#include <QObject>

namespace SWGSDRangel {

class SWGDeviceSetApi: public QObject {
    Q_OBJECT

public:
    SWGDeviceSetApi();
    SWGDeviceSetApi(QString host, QString basePath);
    ~SWGDeviceSetApi();

    QString host;
    QString basePath;
    QMap<QString, QString> defaultHeaders;

    void devicesetDevicePut(qint32 device_set_index, SWGDeviceListItem body);
    void devicesetDeviceRunDelete(qint32 device_set_index);
    void devicesetDeviceRunPost(qint32 device_set_index);
    void devicesetDeviceSettingsGet(qint32 device_set_index);
    void devicesetDeviceSettingsPatch(qint32 device_set_index, SWGDeviceSettings body);
    void devicesetDeviceSettingsPut(qint32 device_set_index, SWGDeviceSettings body);
    void devicesetGet(qint32 device_set_index);
    
private:
    void devicesetDevicePutCallback (HttpRequestWorker * worker);
    void devicesetDeviceRunDeleteCallback (HttpRequestWorker * worker);
    void devicesetDeviceRunPostCallback (HttpRequestWorker * worker);
    void devicesetDeviceSettingsGetCallback (HttpRequestWorker * worker);
    void devicesetDeviceSettingsPatchCallback (HttpRequestWorker * worker);
    void devicesetDeviceSettingsPutCallback (HttpRequestWorker * worker);
    void devicesetGetCallback (HttpRequestWorker * worker);
    
signals:
    void devicesetDevicePutSignal(SWGDeviceListItem* summary);
    void devicesetDeviceRunDeleteSignal(SWGDeviceState* summary);
    void devicesetDeviceRunPostSignal(SWGDeviceState* summary);
    void devicesetDeviceSettingsGetSignal(SWGDeviceSettings* summary);
    void devicesetDeviceSettingsPatchSignal(SWGDeviceSettings* summary);
    void devicesetDeviceSettingsPutSignal(SWGDeviceSettings* summary);
    void devicesetGetSignal(SWGDeviceSet* summary);
    
    void devicesetDevicePutSignalE(SWGDeviceListItem* summary, QNetworkReply::NetworkError error_type, QString& error_str);
    void devicesetDeviceRunDeleteSignalE(SWGDeviceState* summary, QNetworkReply::NetworkError error_type, QString& error_str);
    void devicesetDeviceRunPostSignalE(SWGDeviceState* summary, QNetworkReply::NetworkError error_type, QString& error_str);
    void devicesetDeviceSettingsGetSignalE(SWGDeviceSettings* summary, QNetworkReply::NetworkError error_type, QString& error_str);
    void devicesetDeviceSettingsPatchSignalE(SWGDeviceSettings* summary, QNetworkReply::NetworkError error_type, QString& error_str);
    void devicesetDeviceSettingsPutSignalE(SWGDeviceSettings* summary, QNetworkReply::NetworkError error_type, QString& error_str);
    void devicesetGetSignalE(SWGDeviceSet* summary, QNetworkReply::NetworkError error_type, QString& error_str);
    
};

}
#endif