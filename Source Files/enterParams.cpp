#include "enterParams.h"

enterParams::enterParams(QString text, QString textName,
                         QString spinBoxName, QWidget* parent): QWidget(parent)
{
    m_text = new QLabel(text, this);
    m_spinBox = new QSpinBox(this);

    m_spinBox->setObjectName(spinBoxName);
    m_text->setObjectName(textName);

    setSpinBox();
    setLayout();
}

enterParams::~enterParams(){

}

void enterParams::setSpinBox(){
    m_spinBox->setFixedSize(60,30);

}

void enterParams::setLayout(){
    m_layout = new QHBoxLayout(this);

    m_layout->addWidget(m_text, 0,Qt::AlignLeft);
    m_layout->addWidget(m_spinBox, 1, Qt::AlignRight);
}

void enterParams::setValue(int value){
    m_spinBox->setValue(value);
}

int enterParams::getValue(){
    return m_spinBox->value();
}
