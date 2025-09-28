#include "widget.h"
#include<QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->zt=new teacher(this);
    this->st=new student(this);

    // connect(zt,&teacher::hungry,st,&student::treat);

    // classover();

    // void(teacher:: * teachersignal)(QString)= &teacher::hungry;
    // void(student:: * studentslot)(QString)= &student::treat;

    // connect(zt,teachersignal,st,studentslot);
    // classover();

    QPushButton * btn = new QPushButton("下课",this);
    resize(600,400);

    void(teacher:: * teachersignal2)()= &teacher::hungry;
    void(student:: * studentslot2)()= &student::treat;

    connect(zt,teachersignal2,st,studentslot2);

    connect(btn,QPushButton::clicked,zt,teachersignal2);

    disconnect(zt,teachersignal2,st,studentslot2);

    QPushButton * btn4=new QPushButton("aaa",this);
    btn4->move(200,0);

    connect(btn4,&QPushButton::clicked,this,[=](){
        btn4->setText("bbb");
    });

    // connect(btn4,&QPushButton::clicked,this,&Widget::close);
    connect(btn4,&QPushButton::clicked,this,[=](){
        // this->close();
        st->treat("小蛋糕");
    });

    int num = [=]()->int{
        return 100;
    }();
    qDebug()<<num;
}

void Widget::classover()
{
    // emit this->zt->hungry();
    emit this->zt->hungry("披萨");
}

Widget::~Widget() {}
