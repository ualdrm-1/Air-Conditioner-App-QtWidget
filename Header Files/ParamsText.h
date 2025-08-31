#ifndef PARAMSTEXT_H
#define PARAMSTEXT_H

#include <QWidget>
#include <QVBoxLayout>
#include "AppText.h"

class ParamsText: public QWidget
{
    Q_OBJECT
private:
    AppText* m_title;
    AppText* m_valueText;
    int m_value;
    QString m_sys;

    void setLayout();
public:
    ParamsText(AppText* title, int value,
               QString Sys, QWidget* parent=nullptr);

    int getValue();
    void setValue(int val);
};

#endif // PARAMSTEXT_H
