#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include<QTimer>
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString imgpath);

    int posx;

    int posy;

    bool flag;

    void changeFlag();
    QTimer *timer1;
    QTimer *timer2;

    int min=1;
    int max=8;

    bool isAnimation=false;

    //重写鼠标按下事件
    void mousePressEvent(QMouseEvent *e);

    bool iswin = false;
signals:
};

#endif // MYCOIN_H
