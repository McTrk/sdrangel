///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2020 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#ifndef PLUGINS_CHANNELTX_MODLORA_LORAMODGUI_H_
#define PLUGINS_CHANNELTX_MODLORA_LORAMODGUI_H_

#include <plugin/plugininstancegui.h>
#include "gui/rollupwidget.h"
#include "dsp/channelmarker.h"
#include "util/movingaverage.h"
#include "util/messagequeue.h"

#include "loramod.h"
#include "loramodsettings.h"

class PluginAPI;
class DeviceUISet;
class BasebandSampleSource;

namespace Ui {
    class LoRaModGUI;
}

class LoRaModGUI : public RollupWidget, public PluginInstanceGUI {
    Q_OBJECT

public:
    static LoRaModGUI* create(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSource *channelTx);
    virtual void destroy();

    void setName(const QString& name);
    QString getName() const;
    virtual qint64 getCenterFrequency() const;
    virtual void setCenterFrequency(qint64 centerFrequency);

    void resetToDefaults();
    QByteArray serialize() const;
    bool deserialize(const QByteArray& data);
    virtual MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; }
    virtual bool handleMessage(const Message& message);

public slots:
    void channelMarkerChangedByCursor();

private:
    Ui::LoRaModGUI* ui;
    PluginAPI* m_pluginAPI;
    DeviceUISet* m_deviceUISet;
    ChannelMarker m_channelMarker;
    LoRaModSettings m_settings;
    int m_basebandSampleRate;
    bool m_doApplySettings;

    LoRaMod* m_loRaMod;
    MovingAverageUtil<double, double, 20> m_channelPowerDbAvg;

    std::size_t m_tickCount;
    MessageQueue m_inputMessageQueue;

    explicit LoRaModGUI(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSource *channelTx, QWidget* parent = nullptr);
    virtual ~LoRaModGUI();

    void blockApplySettings(bool block);
    void applySettings(bool force = false);
    void displaySettings();
    void displayStreamIndex();
    void setBandwidths();

    void leaveEvent(QEvent*);
    void enterEvent(QEvent*);

private slots:
    void handleSourceMessages();
    void on_deltaFrequency_changed(qint64 value);
    void on_bw_valueChanged(int value);
	void on_spread_valueChanged(int value);
    void on_deBits_valueChanged(int value);
    void on_preambleChirps_valueChanged(int value);
    void on_idleTime_valueChanged(int value);
    void on_syncWord_editingFinished();
    void on_channelMute_toggled(bool checked);
    void onWidgetRolled(QWidget* widget, bool rollDown);
    void onMenuDialogCalled(const QPoint& p);
    void tick();
};

#endif /* PLUGINS_CHANNELTX_MODLORA_LORAMODGUI_H_ */
