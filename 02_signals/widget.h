#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include"teacher.h"
#include"student.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

   teacher * zt;
   student * st;

   void classover();
};
#endif // WIDGET_H
