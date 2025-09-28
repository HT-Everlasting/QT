#include "playscene.h"
#include<QDebug>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QPainter>
#include<QTimer>
#include<QLabel>
#include"mycoin.h"
#include"mypushbutton.h"
#include"dataconfig.h"
#include<QPropertyAnimation>
// playscene::playscene(QWidget *parent)
//     : QMainWindow{parent}
// {}

playscene::playscene(int leavalindex)
{
    this->levalindex=leavalindex;
    qDebug()<<"您选择的是"<<this->levalindex<<"关";


    this->setFixedSize(320,588);

    this->setWindowIcon(QPixmap(":/new/prefix1/res/Coin0001.png"));

    this->setWindowTitle("翻金币的游戏场景");

    QMenuBar *bar =this->menuBar();
    this->setMenuBar(bar);

    QMenu * startMenu = bar->addMenu("开始");

    QAction * quitAction = startMenu->addAction("退出");

    connect(quitAction,&QAction::triggered,[=](){this->close();});


    //返回按钮
    MyPushButton * backbtn = new MyPushButton(":/new/prefix1/res/BackButton.png",":/new/prefix1/res/BackButtonSelected.png");

    backbtn->setParent(this);

    backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());

    connect(backbtn,&MyPushButton::clicked,[=](){
        QTimer::singleShot(500,this,[=](){
            emit this->chooseSceneback();
        });
    });

    //创建具体选择关卡
    QLabel * label=new QLabel;
    label->setParent(this);

    QString str= QString("leavel:%1").arg(this->levalindex);
    label->setText(str);

    QFont font;
    font.setFamily("华文新魏");
    font.setPixelSize(30);
    label->setFont(font);

    label->setGeometry(QRect(30,this->height()-50,120,50));

    //初始化二位数组
    dataConfig config;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            this->gamaArray[i][j]=config.mData[this->levalindex][i][j];
        }
    }

    //胜利图片
    QLabel * winlabel=new QLabel;
    QPixmap tmppix;
    tmppix.load(":/new/prefix1/res/LevelCompletedDialogBg.png");
    winlabel->setGeometry(0,0,tmppix.width(),tmppix.height());
    winlabel->setPixmap(tmppix);
    winlabel->setParent(this);
    winlabel->move((this->width()-tmppix.width())*0.5,  -tmppix.height());

    //创建金币背景图片
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            QLabel * label=new QLabel;
            QPixmap pix;
            pix.load(":/new/prefix1/res/BoardNode.png");

            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(57+i*pix.width(),200+j*pix.height());

            QString str;
            if(this->gamaArray[i][j] == 1)
            {
                str=":/new/prefix1/res/Coin0001.png";
            }
            else
            {
                str=":/new/prefix1/res/Coin0008.png";
            }

            //创建金币
            MyCoin * coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(59+i*pix.width(),204+j*pix.height());

            coin->posx=i;
            coin->posy=j;
            coin->flag=gamaArray[i][j];


            coinBtn[i][j]=coin;
            //监听点击按钮信号
            connect(coin,&MyCoin::clicked,[=](){
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        coinBtn[i][j]->iswin = true;
                    }
                }

                coin->changeFlag();
                this->gamaArray[i][j] = this->gamaArray[i][j] == 1 ? 0 : 1;

                //延时翻转
                QTimer::singleShot(300,this,[=](){
                    if(coin->posx+1<=3)
                    {   //右侧
                        coinBtn[coin->posx+1][coin->posy]->changeFlag();
                        this->gamaArray[coin->posx+1][coin->posy] = this->gamaArray[coin->posx+1][coin->posy]  ==1?0:1;
                    }
                    if(coin->posx-1>=0)
                    {
                        //左侧
                        coinBtn[coin->posx-1][coin->posy]->changeFlag();
                        this->gamaArray[coin->posx-1][coin->posy] = this->gamaArray[coin->posx-1][coin->posy]  ==1?0:1;
                    }
                    if(coin->posy+1<=3)
                    {
                        //下侧
                        coinBtn[coin->posx][coin->posy+1]->changeFlag();
                        this->gamaArray[coin->posx][coin->posy+1] = this->gamaArray[coin->posx][coin->posy+1]  ==1?0:1;
                    }
                    if(coin->posy-1>=0)
                    {
                        //上侧
                        coinBtn[coin->posx][coin->posy-1]->changeFlag();
                        this->gamaArray[coin->posx][coin->posy-1] = this->gamaArray[coin->posx][coin->posy-1]  ==1?0:1;
                    }

                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            coinBtn[i][j]->iswin = false;
                        }
                    }

                    //检测是否胜利
                    iswin = true;
                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            if(coinBtn[i][j]->flag==false)
                            {
                                iswin=false;
                                break;
                            }
                        }
                    }
                    if(iswin)
                    {
                        qDebug()<<"胜利";
                        for(int i=0;i<4;i++)
                        {
                            for(int j=0;j<4;j++)
                            {
                                coinBtn[i][j]->iswin = true;
                            }
                        }
                        //胜利图片动画
                        QPropertyAnimation * animation = new QPropertyAnimation(winlabel,"geometry");
                        animation->setDuration(1000);
                        animation->setStartValue(QRect(winlabel->x(),winlabel->y(),winlabel->width(),winlabel->height()));
                        animation->setEndValue(QRect(winlabel->x(),winlabel->y()+180,winlabel->width(),winlabel->height()));
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start(QAbstractAnimation::DeleteWhenStopped);
                    }
                });
            });
        }
    }
}

//绘图事件  绘制背景
void playscene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix(":/new/prefix1/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/new/prefix1/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}
