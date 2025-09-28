#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include"mycoin.h"
class playscene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit playscene(QWidget *parent = nullptr);
    playscene(int levalindex);

    int levalindex;

    void paintEvent(QPaintEvent *event);

    //记录当前关卡的二位数组
    int gamaArray[4][4];

    MyCoin * coinBtn[4][4];

    bool iswin = true;

// MyCoin
signals:
    void chooseSceneback();
};

#endif // PLAYSCENE_H
