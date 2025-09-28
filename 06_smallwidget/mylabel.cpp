#include "mylabel.h"
#include<qDebug>
mylabel::mylabel(QWidget *parent)
    : QLabel{parent}
{}


void mylabel::enterEvent(QEnterEvent *event)
{
    qDebug()<<"进入";
}

void mylabel::leaveEvent(QEvent *event)
{
    qDebug()<<"离开";
}
