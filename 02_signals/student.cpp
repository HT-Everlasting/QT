#include "student.h"
#include<QDebug>
student::student(QObject *parent)
    : QObject{parent}
{}

void student::treat()
{
    qDebug()<<"请老师吃饭";
}
void student::treat(QString foodname)
{
    qDebug()<<"请老师吃饭,食物有："<<foodname.toUtf8().data();
}
