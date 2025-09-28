#include "widget.h"
#include "ui_widget.h"
#include<qDebug>
#include<QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        ui->widget->setval(50);
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        qDebug()<< ui->widget->getval();
    });

    id1=startTimer(1000);

    id2=startTimer(2000);
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==id1)
    {
        static int num=1;
        ui->label_2->setText(QString::number(num++));
    }

    if(event->timerId()==id2)
    {
        static int num=1;
        ui->label_3->setText(QString::number(num++));
    }

    QTimer * time1=new QTimer(this);
    time1->start(500);
    connect(time1,&QTimer::timeout,[=](){
        static int num=1;
        ui->label_4->setText(QString::number(num++));
    });

    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        time1->stop();
    });

}

Widget::~Widget()
{
    delete ui;
}
