#ifndef SAMLLWIDGET_H
#define SAMLLWIDGET_H

#include <QWidget>

namespace Ui {
class samllwidget;
}

class samllwidget : public QWidget
{
    Q_OBJECT

public:
    explicit samllwidget(QWidget *parent = nullptr);
    ~samllwidget();

    void setval(int val);

    int getval();
private:
    Ui::samllwidget *ui;
};

#endif // SAMLLWIDGET_H
