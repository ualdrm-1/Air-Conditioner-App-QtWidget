#include "AppText.h"

AppText::AppText(QWidget* parent): QLabel(parent){}

AppText::AppText(QString Text, QString Name, QWidget *parent)
    :QLabel(Text, parent)
{
    setObjectName(Name);
}

AppText::~AppText(){}
