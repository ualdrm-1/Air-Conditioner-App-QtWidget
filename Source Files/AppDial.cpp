#include "AppDial.h"

/*private*/
double AppDial::convertToScale(int cels){
    switch(m_scale){
    case CELS: return cels;
    case K: return cels+273;
    case F: return cels*9.0/5.0+32;
    }
    return cels;
}

QString AppDial::scaleSuffix(){
    switch(m_scale){
    case CELS: return "°C";
    case K: return "K";
    case F: return "°F";
    }
    return "";
}

void AppDial::updateTextTemp(){
    int value = convertToScale(m_dial->value());
    m_text->setText(QString::number(value)+scaleSuffix());
}

void AppDial::setLayout(){
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_dial,0, Qt::AlignLeft);
    layout->addWidget(m_text,0, Qt::AlignRight);
    layout->setContentsMargins(0,0,0,0);
}

void AppDial::setText(){
    m_text = new QPushButton(this);
    m_text->setObjectName("tempValue");
    m_text->setMinimumSize(230,150);
}

void AppDial::setDial(){
    m_dial = new QDial(this);
    m_dial->setRange(16,30);
    m_dial->setMinimumSize(370,370);
    m_dial->setValue(22);
}
/*public*/
AppDial::AppDial(QWidget *parent):QWidget(parent), m_scale(CELS){
    setDial();
    setText();
    updateTextTemp();
    setLayout();

    connect(m_dial, &QDial::valueChanged, this, &AppDial::updateTextTemp);
    connect(m_text, &QPushButton::clicked, this, &AppDial::toggledTemp);
}

int AppDial::getDialValue(){
    return m_dial->value();
}

void AppDial::setDialValue(int& val){
    m_dial->setValue(val);
}
/*private slots*/
void AppDial::toggledTemp(){
    m_scale=static_cast<Scale>((m_scale+1)%3);
    updateTextTemp();
}
