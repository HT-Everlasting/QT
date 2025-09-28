#include "mycoin.h"
#include<QDebug>
// MyCoin::MyCoin(QWidget *parent)
//     : QWidget{parent}
// {}

MyCoin::MyCoin(QString imgpath)
{
    QPixmap pix;
    bool ret = pix.load(imgpath);
    if(!ret)
    {
        qDebug()<<"图片加载失败"<<imgpath;
        return;
    }

    this->setFixedSize(pix.width(),pix.height());

    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(pix);

    this->setIconSize(QSize(pix.width(),pix.height()));

    //创建两个定时器
    timer1= new QTimer(this);
    timer2= new QTimer(this);
    //金币翻银币
    connect(timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/new/prefix1/res/Coin000%1").arg(this->min++);
        bool ret = pix.load(str);
        if(!ret)
        {
            qDebug()<<"图片加载失败"<<imgpath;
            return;
        }

        this->setFixedSize(pix.width(),pix.height());

        this->setStyleSheet("QPushButton{border:0px;}");

        this->setIcon(pix);

        this->setIconSize(QSize(pix.width(),pix.height()));

        if(this->min>this->max)
        {
            this->min=1;
            this->isAnimation=false;
            timer1->stop();
        }
    });

    //银币翻金币
    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/new/prefix1/res/Coin000%1").arg(this->max--);
        bool ret = pix.load(str);
        if(!ret)
        {
            qDebug()<<"图片加载失败"<<imgpath;
            return;
        }

        this->setFixedSize(pix.width(),pix.height());

        this->setStyleSheet("QPushButton{border:0px;}");

        this->setIcon(pix);

        this->setIconSize(QSize(pix.width(),pix.height()));

        if(this->max<this->min)
        {
            this->max=8;
            this->isAnimation=false;
            timer2->stop();
        }
    });
}

void MyCoin::changeFlag()
{
    if(this->flag)
    {
        timer1->start(30);
        //动画中，值为true
        this->isAnimation=true;
        this->flag=false;
    }
    else
    {
        timer2->start(30);
        this->isAnimation=true;
        this->flag=true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation||this->iswin)
    {
        return;
    }
    else
    {
        QPushButton::mousePressEvent(e);
    }
}
