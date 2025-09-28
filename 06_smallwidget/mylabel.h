#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class mylabel : public QLabel
{
    Q_OBJECT
public:
    explicit mylabel(QWidget *parent = nullptr);

    void enterEvent(QEnterEvent *event);

    void leaveEvent(QEvent *event);

signals:
};

#endif // MYLABEL_H
