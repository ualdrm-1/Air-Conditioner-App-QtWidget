#ifndef AIRDISPLAY_H
#define AIRDISPLAY_H

#include "AppText.h"
#include "ParamsText.h"
#include "AppDial.h"
#include "AppButton.h"
#include "setParameters.h"
#include "config.h"

class AirDisplay: public QWidget{
    Q_OBJECT
private:
    AppText* m_headerText;
    ParamsText* m_pressure;
    ParamsText* m_humidity;

    AppDial *m_tempDial;

    AppButton* m_themeButton;
    AppButton* m_setButton;
    AppButton* m_firstAirButton;
    AppButton* m_secondAirButton;
    AppButton* m_thirdAirButton;
    AppButton* m_powerButton;
    AppButton* m_graphButton;

    QGridLayout *m_headerLayout;

    ParamsWindow* m_pWindow;

    bool m_isThemeBlack=true;

    void setObjects();
    void SetHeader();
    void SetParams();
    void SetButtons();
    void sendSignals();
    void connectSlots();
    void setButtons();
    void whatsTheTheme(bool flag);
public:
    AirDisplay(QWidget* parent=nullptr);
    ~AirDisplay();

    void setBlackTheme();
    void setWhiteTheme();
    int getTempValue();
    void setTempValue(int& val);
    int getPressValue();
    void setPressValue(int val);
    int getHumidValue();
    void setHumidValue(int val);
private slots:
    void onThemeClicked();
    void onCloseApp();
    void onParamSet();
    void FirstAirMode();
    void SecondAirMode();
    void ThirdAirMode();
public slots:
    void AcceptValues(int t, int p, int h);
signals:
    void SendTempSignal(int val);
    void SendPressSignal(int val);
    void SendHumidSignal(int val);
    void SendThemeSignal(bool flag);
};

#endif // AIRDISPLAY_H
