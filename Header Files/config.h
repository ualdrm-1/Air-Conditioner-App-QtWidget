#ifndef CONFIG_H
#define CONFIG_H

#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>
class ConfigManager{
public:
    static void WriteConfig(int temp, int humid, int press, bool theme);
    static void ReadConfig(bool &theme, int &temp, int &press, int &hum);
};


#endif // CONFIG_H
