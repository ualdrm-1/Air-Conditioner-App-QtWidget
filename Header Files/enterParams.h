#ifndef ENTERPARAMS_H
#define ENTERPARAMS_H

#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QLayout>

class enterParams: public QWidget{
    Q_OBJECT
private:
    QLabel* m_text;
    QSpinBox* m_spinBox;

    QHBoxLayout* m_layout;

    void setSpinBox();
    void setLayout();
public:
    enterParams(QString text, QString textName, QString spinBoxName, QWidget* parent = nullptr);
    ~enterParams();

    int getValue();
    void setValue(int value);
};

#endif // ENTERPARAMS_H
