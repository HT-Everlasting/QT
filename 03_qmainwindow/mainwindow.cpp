#include "mainwindow.h"
#include<QMenuBar>
#include<QToolBar>
#include<QLabel>
#include<QStatusBar>
#include<QDockWidget>
#include<QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600,400);
    //菜单栏
    QMenuBar *bar =menuBar();
    setMenuBar(bar);

    QMenu * filemenu = bar->addMenu("文件");
    QMenu * editmenu = bar->addMenu("编辑");

    QAction* newaction=filemenu->addAction("新建");
    filemenu->addSeparator();
    QAction* newaction2=filemenu->addAction("打开");

    QAction* newaction3=editmenu->addAction("1");
    editmenu->addSeparator();
    QAction* newaction4=editmenu->addAction("2");
    //工具栏
    QToolBar * toolbar=new QToolBar(this);
    addToolBar(toolbar);
    addToolBar(Qt::LeftToolBarArea,toolbar);

    toolbar->addAction(newaction);
    toolbar->addSeparator();
    toolbar->addAction(newaction2);

    //状态栏
    QStatusBar * stbar=statusBar();
    setStatusBar(stbar);

    //提示信息
    QLabel * label1=new QLabel("左侧提示信息",this);
    stbar->addWidget(label1);

    //铆接部件
    QDockWidget * dock = new QDockWidget("aaa",this);
    addDockWidget(Qt::BottomDockWidgetArea,dock);

    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);

    //核心部件
    QTextEdit * edit=new QTextEdit(this);
    setCentralWidget(edit);
}

MainWindow::~MainWindow() {}
