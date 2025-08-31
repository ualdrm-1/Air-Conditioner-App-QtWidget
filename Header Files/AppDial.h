#ifndef APPDIAL_H
#define APPDIAL_H

#include <QDial>
#include <QPushButton>
#include <QHBoxLayout>

class AppDial: public QWidget{
    Q_OBJECT
private:
    QDial *m_dial;
    QPushButton *m_text;
    enum Scale {CELS, K, F};
    Scale m_scale;

    double convertToScale(int cels);
    QString scaleSuffix();

    void updateTextTemp();
    void setLayout();
    void setText();
    void setDial();
public:
    AppDial(QWidget *parent=nullptr);

    int getDialValue();
    void setDialValue(int& val);
private slots:
    void toggledTemp();
};

#endif // APPDIAL_H
