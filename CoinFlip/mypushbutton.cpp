#include "mypushbutton.h"
#include<qDebug>
#include<QPropertyAnimation>

// mypushbutton::mypushbutton(QWidget *parent)
//     : QWidget{parent}
// {}


MyPushButton::MyPushButton(QString normalImg,QString pressImg)
{
    this->normalImgpath=normalImg;
    this->pressImgpath=pressImg;

    QPixmap pix;
    bool ret=pix.load(normalImgpath);

    if(!ret)
    {
        QString str=QString("图片加载失败 %1").arg(normalImg);
        qDebug() <<str;
        return;
    }

    this->setFixedSize(pix.width(),pix.height());

    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(pix);

    this->setIconSize(QSize(pix.width(),pix.height()));
}

void MyPushButton::zoom1()
{
    QPropertyAnimation * anim=new QPropertyAnimation(this,"geometry");

    //时间间隔
    anim->setDuration(200);
    //起始位置
    anim->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    anim->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //弹起效果
    anim->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::zoom2()
{
    QPropertyAnimation * anim=new QPropertyAnimation(this,"geometry");

    //时间间隔
    anim->setDuration(200);
    //起始位置
    anim->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //结束位置
    anim->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //弹起效果
    anim->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImgpath!="")
    {
        QPixmap pix;
        bool ret=pix.load(pressImgpath);

        if(!ret)
        {
            QString str=QString("图片加载失败 %1").arg(normalImgpath);
            qDebug() <<str;
            return;
        }

        this->setFixedSize(pix.width(),pix.height());

        this->setStyleSheet("QPushButton{border:0px;}");

        this->setIcon(pix);

        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //点击响应抛给父类
    QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressImgpath!="")
    {
        QPixmap pix;
        bool ret=pix.load(normalImgpath);

        if(!ret)
        {
            QString str=QString("图片加载失败 %1").arg(normalImgpath);
            qDebug() <<str;
            return;
        }

        this->setFixedSize(pix.width(),pix.height());

        this->setStyleSheet("QPushButton{border:0px;}");

        this->setIcon(pix);

        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //点击响应抛给父类
    QPushButton::mouseReleaseEvent(e);
}
