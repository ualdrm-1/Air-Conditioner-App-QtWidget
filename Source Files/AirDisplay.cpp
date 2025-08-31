#include "AirDisplay.h"

/*private*/
void AirDisplay::setObjects(){
    m_headerLayout = new QGridLayout(this);

    SetHeader();
    SetParams();
    SetButtons();
}

void AirDisplay::SetHeader(){
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(m_headerText, 0, Qt::AlignLeft);
    hLayout->addWidget(m_themeButton, 0, Qt::AlignRight);
    hLayout->setContentsMargins(30,0,30,0);

    m_headerLayout->addLayout(hLayout, 0,0,1,3);
}

void AirDisplay::SetParams(){
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(m_tempDial, 0);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(m_pressure,0,Qt::AlignLeft);
    hLayout->addWidget(m_humidity,0,Qt::AlignRight);

    vLayout->addLayout(hLayout);

    m_headerLayout->addLayout(vLayout,1,0,1,3);
}

void AirDisplay::SetButtons(){
    m_headerLayout->addWidget(m_firstAirButton,2,0,Qt::AlignCenter);
    m_headerLayout->addWidget(m_secondAirButton,2,1,Qt::AlignCenter);
    m_headerLayout->addWidget(m_thirdAirButton,2,2,Qt::AlignCenter);
    m_headerLayout->addWidget(m_graphButton,3,0,Qt::AlignCenter);
    m_headerLayout->addWidget(m_setButton,3,1,Qt::AlignCenter);
    m_headerLayout->addWidget(m_powerButton,3,2,Qt::AlignCenter);
}

void AirDisplay::sendSignals(){
    emit SendTempSignal(getTempValue());
    emit SendHumidSignal(getPressValue());
    emit SendPressSignal(getHumidValue());
    emit SendThemeSignal(m_isThemeBlack);
}

void AirDisplay::connectSlots(){
    connect(m_themeButton, &QPushButton::clicked, this, &AirDisplay::onThemeClicked);
    connect(m_powerButton, &QPushButton::clicked, this, &AirDisplay::onCloseApp);
    connect(m_setButton, &QPushButton::clicked, this, &AirDisplay::onParamSet);

    connect(m_firstAirButton, &QPushButton::clicked, [this]{
        m_firstAirButton->animateClick();
    });
    connect(m_secondAirButton, &QPushButton::clicked, [this]{
        m_secondAirButton->animateClick();
    });
    connect(m_thirdAirButton, &QPushButton::clicked, [this]{
        m_thirdAirButton->animateClick();
    });
    connect(m_setButton, &QPushButton::clicked, [this]{
        m_setButton->animateClick();
    });
    connect(m_graphButton, &QPushButton::clicked, [this]{
        m_graphButton->animateClick();
    });
    connect(m_themeButton, &QPushButton::clicked, [this]{
        m_themeButton->animateClick();
    });

    connect(m_firstAirButton, &QPushButton::clicked, this, &AirDisplay::FirstAirMode);
    connect(m_secondAirButton, &QPushButton::clicked, this, &AirDisplay::SecondAirMode);
    connect(m_thirdAirButton, &QPushButton::clicked, this, &AirDisplay::ThirdAirMode);
}

void AirDisplay::setButtons(){
    m_firstAirButton = new AppButton(120, 100, "FAir", this);
    m_secondAirButton = new AppButton(120, 100, "SAir", this);
    m_thirdAirButton = new AppButton(120, 100, "TAir", this);
    m_setButton = new AppButton(120, 100, "SetParams", this);
    m_graphButton = new AppButton(120, 100, "Graph", this);
    m_powerButton = new AppButton(120, 100, "Power", this);
}

void AirDisplay::whatsTheTheme(bool flag){
    flag? setBlackTheme(): setWhiteTheme();
}
/*public*/
AirDisplay::AirDisplay(QWidget* parent): QWidget(parent){
    int temperature, pressue, humidity;

    ConfigManager::ReadConfig(m_isThemeBlack, temperature, pressue, humidity);

    m_headerText = new AppText("Air Conditioner", "headerText",this);

    AppText* pressureText = new AppText("Pressure", "pressureText",this);
    AppText* humidityText = new AppText("Humidity", "humidityText",this);

    m_pressure = new ParamsText(pressureText, pressue, " hPa", this);
    m_humidity = new ParamsText(humidityText, humidity, "%",this);

    m_themeButton = new AppButton(70, 70, "Theme", this);

    setButtons();

    m_tempDial = new AppDial(this);
    m_tempDial->setDialValue(temperature);

    whatsTheTheme(m_isThemeBlack);

    setObjects();

    connectSlots();
}

AirDisplay::~AirDisplay(){
    ConfigManager::WriteConfig(m_tempDial->getDialValue(),
                                m_humidity->getValue(),
                                m_pressure->getValue(),
                                m_isThemeBlack);
}

void AirDisplay::setBlackTheme() {
    this->setStyleSheet(R"(
    #headerText {
        color: white;
        font-size:44px;
        font-weight:800;
    }

    #pressureText, #humidityText{
        color: white;
        font-size:36px;
        font-weight:400;
    }

    #tempText{
        color:white;
        font-size:40px;
        font-weight:900;
    }

    #tempValue{
        border:none;
        background: transparent;
        color:white;
        font-size:70px;
        font-weight:800;
    }

    QPushButton {
        background: transparent;
        color: black;
        border: 2px solid #555555;
        border-radius: 15px;
    }

    QDial {
        background-color: white;
        border: 2px solid #333333;
        border-radius: 50px;
    }
)");
    parentWidget()->setStyleSheet("background-color:rgb(32,32,32)");
    m_themeButton->changeIcon("/home/ualdrm/Загрузки/themes.png");
    m_firstAirButton->changeIcon("/home/ualdrm/Загрузки/air1White.png");
    m_secondAirButton->changeIcon("/home/ualdrm/Загрузки/air2White.png");
    m_thirdAirButton->changeIcon("/home/ualdrm/Загрузки/air3White.png");
    m_powerButton->changeIcon("/home/ualdrm/Загрузки/onWhite.png");
    m_setButton->changeIcon("/home/ualdrm/Загрузки/settingsWhite.png");
    m_graphButton->changeIcon("/home/ualdrm/Загрузки/paramsWhite.png");
}

void AirDisplay::setWhiteTheme() {
    this->setStyleSheet(R"(
    #headerText {
        color: black;
        font-size:44px;
        font-weight:800;
    }

    #pressureText, #humidityText{
        color: black;
        font-size:36px;
        font-weight:400;
    }

    #tempText{
        color:black;
        font-size:40px;
        font-weight:900;
    }

    #tempValue{
        border:none;
        background: transparent;
        color:black;
        font-size:70px;
        font-weight:800;
    }

    QPushButton {
        background:transparent;
        color: white;
        border: 2px solid #555555;
        border-radius: 15px;
    }

    QDial {
        background-color: #003366;
        border: 2px solid #333333;
        border-radius: 50px;
    }
)");
    parentWidget()->setStyleSheet("background-color:rgb(225,225,225)");
    m_themeButton->changeIcon("/home/ualdrm/Загрузки/theme.png");
    m_firstAirButton->changeIcon("/home/ualdrm/Загрузки/air1.png");
    m_secondAirButton->changeIcon("/home/ualdrm/Загрузки/air2.png");
    m_thirdAirButton->changeIcon("/home/ualdrm/Загрузки/air3.png");
    m_powerButton->changeIcon("/home/ualdrm/Загрузки/on.png");
    m_setButton->changeIcon("/home/ualdrm/Загрузки/settings.png");
    m_graphButton->changeIcon("/home/ualdrm/Загрузки/graph.png");
}

int AirDisplay::getTempValue(){
    return m_tempDial->getDialValue();
}

void AirDisplay::setTempValue(int& val){
    m_tempDial->setDialValue(val);
}

int AirDisplay::getPressValue(){
    return m_pressure->getValue();
}

void AirDisplay::setPressValue(int val){
    m_pressure->setValue(val);
}

int AirDisplay::getHumidValue(){
    return m_humidity->getValue();
}

void AirDisplay::setHumidValue(int val){
    m_humidity->setValue(val);
}
/*private slots*/
void AirDisplay::onThemeClicked(){
    if(m_isThemeBlack){
        setWhiteTheme();
        m_isThemeBlack=!m_isThemeBlack;
        qDebug()<<"Theme is white";
    }else{
        setBlackTheme();
        m_isThemeBlack=!m_isThemeBlack;

        qDebug()<<"Theme is black";
    }
}

void AirDisplay::onCloseApp(){
    parentWidget()->close();
}

void AirDisplay::onParamSet(){
    m_pWindow = new ParamsWindow(this);
    m_pWindow->setAttribute(Qt::WA_DeleteOnClose);
    m_pWindow->setWindowModality(Qt::WindowModal);

    connect(this, &AirDisplay::SendTempSignal, m_pWindow, &ParamsWindow::onSetTemperatureValue);
    connect(this, &AirDisplay::SendPressSignal, m_pWindow, &ParamsWindow::onSetPressueValue);
    connect(this, &AirDisplay::SendHumidSignal, m_pWindow, &ParamsWindow::onSetHumidityValue);
    connect(this, &AirDisplay::SendThemeSignal, m_pWindow, &ParamsWindow::onSetTheme);

    connect(m_pWindow, &ParamsWindow::appliedValues, this, &AirDisplay::AcceptValues);

    sendSignals();
    m_pWindow->exec();
}

void AirDisplay::FirstAirMode(){
    int temp = 10, press = 22, humid = 30;
    m_tempDial->setDialValue(temp);
    m_humidity->setValue(humid);
    m_pressure->setValue(press);

    qDebug()<<"First Air Mode had turned on";
}

void AirDisplay::SecondAirMode(){
    int temp = 28, press = 53, humid = 18;
    m_tempDial->setDialValue(temp);
    m_humidity->setValue(humid);
    m_pressure->setValue(press);

    qDebug()<<"Second Air Mode had turned on";
}

void AirDisplay::ThirdAirMode(){
    int temp = 22, press = 11, humid = 50;
    m_tempDial->setDialValue(temp);
    m_humidity->setValue(humid);
    m_pressure->setValue(press);

    qDebug()<<"Third Air Mode had turned on";
}
/*public slots*/
void AirDisplay::AcceptValues(int t, int p, int h){
    setPressValue(p);
    setHumidValue(h);
    setTempValue(t);
}
