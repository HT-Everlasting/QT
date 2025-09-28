#include "mywidget.h"
#include "ui_mywidget.h"
#include<QPushButton>

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    ui->setupUi(this);
    QPushButton *btn =new QPushButton;
    btn->setParent(this);
    btn->setText("德玛西亚");

    QPushButton *btn2 =new QPushButton("第二个",this);
    btn2->move(100,100);
    resize(600,400);

    setWindowTitle("丫丫");

    setFixedSize(500,500);

    connect(btn2,&QPushButton::clicked,this,&myWidget::close);
}

myWidget::~myWidget()
{
    delete ui;
}
