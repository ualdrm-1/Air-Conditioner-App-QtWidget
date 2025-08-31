#include "AppButton.h"

AppButton::AppButton(int width, int height, QString Name, QWidget *parent)
    :QPushButton(parent),
    m_width(width),
    m_height(height)
{
    this->setFixedSize(m_width, m_height);
    this->setIconSize(this->size()*0.8);
    setToolTip(Name);
}

AppButton::~AppButton(){}

void AppButton::changeIcon(QString Url){
    QPixmap pixmap = QPixmap(Url);
    this->setIcon(pixmap);
}

void AppButton::animateClick(){
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(200);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(), this->y() + 5,
                                 this->width(), this->height()));
    animation->setEasingCurve(QEasingCurve::OutQuad);

    QPropertyAnimation *reverse = new QPropertyAnimation(this, "geometry");
    reverse->setDuration(200);
    reverse->setStartValue(QRect(this->x(), this->y() + 5,
                                 this->width(), this->height()));
    reverse->setEndValue(this->geometry());

    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;
    group->addAnimation(animation);
    group->addAnimation(reverse);
    group->start(QAbstractAnimation::DeleteWhenStopped);
}
