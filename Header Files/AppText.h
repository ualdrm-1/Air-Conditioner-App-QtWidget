#ifndef APPTEXT_H
#define APPTEXT_H

#include <QLabel>

class AppText: public QLabel
{
    Q_OBJECT
public:
    AppText(QWidget* parent = nullptr);
    AppText(QString Text, QString Name, QWidget *parent = nullptr);

    ~AppText();
};

#endif // APPTEXT_H
