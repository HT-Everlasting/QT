#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include<mypushbutton.h>
#include<qdebug>
#include<QTimer>


MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    this->setWindowTitle("翻金币主场景");

    this->setFixedSize(320,588);

    this->setWindowIcon(QIcon(":/new/prefix1/res/Coin0001.png"));

    connect(ui->action,&QAction::triggered,[=](){
        this->close();


    });



    levelscene =new chooselevelscene;
    MyPushButton * btn=new MyPushButton(":/new/prefix1/res/MenuSceneStartButton.png");
    btn->move(this->width()*0.5-btn->width()*0.5,this->height()*0.7);
    qDebug() << "按钮坐标：" << btn->pos();

    btn->setParent(this);

    connect(levelscene,&chooselevelscene::chooseSceneback,[=](){
        levelscene->hide();
        this->setGeometry(levelscene->geometry());
        this->show();
    });

    connect(btn,&MyPushButton::clicked,[=](){



        btn->zoom1();
        btn->zoom2();

        QTimer::singleShot(500,this,[=](){
            this->hide();

            //选择关卡场景位置
            levelscene->setGeometry(this->geometry());
            levelscene->show();
        });
    });


}
//绘图事件  绘制背景
void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix(":/new/prefix1/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/new/prefix1/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}

MainScene::~MainScene()
{
    delete ui;
}
