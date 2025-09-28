#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄简介");

    QTreeWidgetItem * item1=new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem * item2=new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem * item3=new QTreeWidgetItem(QStringList()<<"智力");

    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);
    ui->treeWidget->addTopLevelItem(item3);

    QStringList herol1;
    herol1<<"泰坦"<<"前排坦克，能在吸收伤害同时造成客观地范围输出";

    QTreeWidgetItem * l1=new QTreeWidgetItem(herol1);
    item1->addChild(l1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
