#include "setParameters.h"

ParamsWindow::ParamsWindow(QWidget* parent):QDialog(parent)
{
    setWindowTitle("Set Parameters");
    setFixedSize(300,200);

    setEnter();
    setButtons();
    setLayout();

    connect(m_close, &QPushButton::clicked, this, &ParamsWindow::onCloseClick);
    connect(m_apply, &QPushButton::clicked, this, &ParamsWindow::AcceptClicked);
}

ParamsWindow::~ParamsWindow(){}

void ParamsWindow::setEnter(){
    m_tempEnter = new enterParams("Temperature", "textParams", "valueParam", this);
    m_pressEnter = new enterParams("Pressue", "textParams", "valueParam", this);
    m_humidEnter = new enterParams("Humidity", "textParams", "valueParam", this);
}

void ParamsWindow::setButtons(){
    m_apply = new QPushButton("Apply", this);
    m_close = new QPushButton("Close", this);

    m_apply->setObjectName("ApplyButton");
    m_close->setObjectName("CloseButton");
}

void ParamsWindow::setLayout(){
    m_VertLayout = new QVBoxLayout(this);

    m_VertLayout->addWidget(m_tempEnter);
    m_VertLayout->addWidget(m_pressEnter);
    m_VertLayout->addWidget(m_humidEnter);

    QHBoxLayout* bLayout = new QHBoxLayout;
    bLayout->addWidget(m_apply);
    bLayout->addWidget(m_close);

    m_VertLayout->addLayout(bLayout);
}

void ParamsWindow::onCloseClick(){
    close();
}

void ParamsWindow::onSetTemperatureValue(int value){
    m_tempEnter->setValue(value);
}

void ParamsWindow::onSetHumidityValue(int value){
    m_pressEnter->setValue(value);
}

void ParamsWindow::onSetPressueValue(int value){
    m_humidEnter->setValue(value);
}

void ParamsWindow::onSetTheme(bool flag){
    if(flag){
        setBlackTheme();
    }else{
        setWhiteTheme();
    }
}

void ParamsWindow::AcceptClicked(){
    emit appliedValues(m_tempEnter->getValue(),
                       m_pressEnter->getValue(),
                       m_humidEnter->getValue());
    close();
}

void ParamsWindow::setBlackTheme(){
    this->setStyleSheet(R"(
        #ApplyButton{
            background-color:#2a2a2a;
            border-radius: 10px;
            color:white;
                    }
        #CloseButton{
            background-color:#2a2a2a;
            border-radius: 10px;
            color:white;
                    }
        #textParams{color:white;
                    font-size:30px;
                    font-weight:400;
                   }
        #valueParam{color:white;}
        QDialog{background-color:rgb(32,32,32);}
    )");
}

void ParamsWindow::setWhiteTheme(){
    this->setStyleSheet(R"(
        #ApplyButton{
            background-color:rgb(225,225,225);
            border-radius: 10px;
            color:black;
                    }
        #CloseButton{
            background-color:rgb(225,225,225);
            border-radius: 10px;
            color:black;
                    }
        #textParams{color:black;
                    font-size:30px;
                    font-weight:400;
                   }
        #valueParam{color:black;}
        QDialog{background-color:rgb(225,225,225);}
    )");
}
