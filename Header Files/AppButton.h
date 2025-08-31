#ifndef APPBUTTON_H
#define APPBUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

class AppButton: public QPushButton{
    Q_OBJECT
private:
    int m_width;
    int m_height;
public:
    AppButton(int width, int height, QString Name, QWidget *parent = nullptr);
    ~AppButton();

    void changeIcon(QString Url);
    void animateClick();
};

#endif // APPBUTTON_H
