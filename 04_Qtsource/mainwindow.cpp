#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include<QMessageBox>
#include<QDebug>
#include<QColorDialog>
#include<QFileDialog>
#include<Qstring>
#include<QFontDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //资源文件添加
    ui->actionaaa->setIcon(QIcon(":/Image/Luffy.png"));
    ui->actionbbb->setIcon(QIcon(":/Image/LuffyQ.png"));

    //创建对话框
    connect(ui->actionaaa,&QAction::triggered,this,[=](){

        //模态对话框
        // QDialog dlg(this);
        // dlg.resize(120,40);
        // dlg.exec();

        //非模态
        // QDialog * dlg2= new QDialog(this);
        // dlg2->show();
        // //55号属性
        // dlg2->setAttribute(Qt::WA_DeleteOnClose);

        //错误提示框
        // QMessageBox::critical(this,"错误提示","critical");

        //信息提示
        // QMessageBox::information(this,"提示","sss");

        //
        //父窗口 参数1  标题  提示信息  关联按键类型  默认回车按键
        // if(QMessageBox::Save == QMessageBox::question(this,"提示","question",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel))
        // {
        //     qDebug()<<"保存";
        // }
        // else
        // {
        //     qDebug()<<"取消";
        // }

        //警告
        // QMessageBox::warning(this,"警告","warning");

        //颜色对话框
        // QColor color=QColorDialog::getColor(Qt::red);
        // qDebug() <<color.red()<<color.green()<<color.blue();


        // QString filename=QFileDialog::getOpenFileName(this,"打开文件","D:\BaiduNetdiskDownload","(*.doc)");
        // qDebug()<<filename;

        //字体对话框
        bool flag;
        QFont font = QFontDialog::getFont(&flag,QFont("华文彩云",36));
        qDebug() << "字体" << font.family().toUtf8().data() << "字号"<< font.pointSize()
                 << "是否加粗"<<font.bold() << "是否倾斜" << font.italic();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
