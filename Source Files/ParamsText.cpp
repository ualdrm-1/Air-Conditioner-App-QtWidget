#include "ParamsText.h"

void ParamsText::setLayout(){
    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(m_title,0, Qt::AlignCenter);
    vLayout->addWidget(m_valueText,0, Qt::AlignCenter);
    vLayout->setContentsMargins(40,0,40,10);
}

ParamsText::ParamsText(AppText* title, int value,
                       QString Sys, QWidget* parent):
                       QWidget(parent), m_title(title),
                       m_value(value), m_sys(Sys)
{
    m_valueText = new AppText(QString::number(m_value)+m_sys, "tempText", this);
    m_title->setParent(this);
    setLayout();
}

int ParamsText::getValue(){
    return m_value;
}

void ParamsText::setValue(int val){
    m_value=val;
    m_valueText->setText(QString::number(m_value)+m_sys);
}
