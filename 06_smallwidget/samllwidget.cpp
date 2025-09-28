#include "samllwidget.h"
#include "ui_samllwidget.h"

samllwidget::samllwidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::samllwidget)
{
    ui->setupUi(this);


    connect(ui->spinBox,&QSpinBox::valueChanged,[=](int val){
        ui->horizontalSlider->setValue(val);
    });

    connect(ui->horizontalSlider,&QSlider::valueChanged,[=](int val){
        ui->spinBox->setValue(val);
    });
}

void samllwidget::setval(int val)
{
    ui->horizontalSlider->setValue(val);
}

int samllwidget::getval()
{
    return ui->horizontalSlider->value();
}

samllwidget::~samllwidget()
{
    delete ui;
}
