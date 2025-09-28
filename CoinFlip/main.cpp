#include "mainscene.h"
#include"dataconfig.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainScene w;
    w.show();
    //测试

    return a.exec();
}
