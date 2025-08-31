#ifndef SETPARAMETERS_H
#define SETPARAMETERS_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include "enterParams.h"

class ParamsWindow: public QDialog{
    Q_OBJECT
private:
    enterParams* m_tempEnter;
    enterParams* m_pressEnter;
    enterParams* m_humidEnter;

    QPushButton* m_apply;
    QPushButton* m_close;

    QVBoxLayout* m_VertLayout;

    void AcceptClicked();
public:
    explicit ParamsWindow(QWidget* parent=nullptr);
    ~ParamsWindow();

    void setWhiteTheme();
    void setBlackTheme();
private:
    void setEnter();
    void setButtons();
    void setLayout();
    void onParamSet();
private slots:
    void onCloseClick();
public slots:
    void onSetTemperatureValue(int value);
    void onSetPressueValue(int value);
    void onSetHumidityValue(int value);
    void onSetTheme(bool flag);
signals:
    void appliedValues(int temp, int press, int humid);
};

#endif // SETPARAMETERS_H
