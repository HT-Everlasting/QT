#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include"playscene.h"
class chooselevelscene : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooselevelscene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

    playscene * Playscene;
signals:
    void chooseSceneback();
};

#endif // CHOOSELEVELSCENE_H
