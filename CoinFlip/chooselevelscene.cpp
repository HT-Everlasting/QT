#include "chooselevelscene.h"
#include<QAction>
#include<QMenuBar>
#include<QPainter>
#include<mypushbutton.h>
#include<QTimer>
#include<QDebug>
#include<QLabel>
#include<QString>

chooselevelscene::chooselevelscene(QWidget *parent)
    : QMainWindow{parent}
{
    QMenuBar * bar=menuBar();

    QMenu * stratmenu= bar->addMenu("开始");

    QAction * quit=stratmenu->addAction("退出");

    connect(quit,&QAction::triggered,[=](){
        this->close();
    });

    this->setWindowTitle("选择关卡场景");

    this->setFixedSize(320,588);

    this->setWindowIcon(QIcon(":/new/prefix1/res/Coin0001.png"));

    //返回按钮
    MyPushButton * backbtn = new MyPushButton(":/new/prefix1/res/BackButton.png",":/new/prefix1/res/BackButtonSelected.png");

    backbtn->setParent(this);

    backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());

    connect(backbtn,&MyPushButton::clicked,[=](){
        QTimer::singleShot(500,this,[=](){
            emit this->chooseSceneback();
        });
    });

    Playscene =NULL;
    //创建20个选择关卡的小按钮
    for(int i=0;i<20;i++)
    {
        MyPushButton * menubtn = new MyPushButton(":/new/prefix1/res/LevelIcon.png");
        menubtn->setParent(this);

        menubtn->move(25+(i%4)*70,130+(i/4)*70);

        connect(menubtn,&MyPushButton::clicked,[=](){
            //qDebug()<<"您选择的是"<<i+1<<"关";
            Playscene=new playscene(i+1);
            this->hide();
            this->Playscene->setGeometry(this->geometry());

            this->Playscene->show();

            //监听游戏场景点击返回按钮 发送的自定义信号
            connect(this->Playscene,&playscene::chooseSceneback,[=](){
                this->setGeometry(this->Playscene->geometry());

                delete this->Playscene;
                this->Playscene=NULL;
                this->show();
            });
        });

        QLabel * label = new QLabel;

        label->setParent(this);
        label->setFixedSize(menubtn->width(),menubtn->height());
        label->setText(QString::number(i+1));
        label->move(25+(i%4)*70,130+(i/4)*70);

        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

}

void chooselevelscene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/new/prefix1/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/new/prefix1/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);

}
