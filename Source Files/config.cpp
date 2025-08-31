#include "config.h"

void ConfigManager::WriteConfig(int temp, int humid, int press, bool theme){
    QFile file("config.xml");
    if(!file.open(QIODevice::WriteOnly)) return;

    QXmlStreamWriter xml(&file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement("config");

    xml.writeTextElement("temperature", QString::number(temp));

    xml.writeTextElement("humidity", QString::number(humid));

    xml.writeTextElement("pressue", QString::number(press));

    xml.writeTextElement("theme", theme?"true":"false");

    xml.writeEndElement();
    xml.writeEndDocument();

    file.close();
}

void ConfigManager::ReadConfig(bool &theme, int &temp, int &press, int &hum){
    QFile file("config.xml");
    if(!file.open(QIODevice::ReadOnly)) return;

    QXmlStreamReader xml(&file);
    if(xml.readNextStartElement() && xml.name() == "config"){
    while(xml.readNextStartElement()){
            if(xml.name()=="temperature"){
                temp = xml.readElementText().toInt();
                qDebug()<<"temp = "<<temp;
            }
            else if(xml.name()=="humidity"){
                hum = xml.readElementText().toInt();
                qDebug()<<"humid = "<<hum;
            }
            else if(xml.name()=="pressue"){
                press = xml.readElementText().toInt();
                qDebug()<<"press = "<<press;
            }
            else if(xml.name()=="theme"){
                theme=QString::compare(xml.readElementText(), "true")==0? true:false;
                qDebug()<<"theme = "<<theme;
            }else{
                xml.skipCurrentElement();
            }
        }
    }

    file.close();
}
