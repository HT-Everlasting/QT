/********************************************************************************
** Form generated from reading UI file 'samllwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMLLWIDGET_H
#define UI_SAMLLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_samllwidget
{
public:
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QWidget *samllwidget)
    {
        if (samllwidget->objectName().isEmpty())
            samllwidget->setObjectName("samllwidget");
        samllwidget->resize(286, 109);
        spinBox = new QSpinBox(samllwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(30, 60, 42, 25));
        horizontalSlider = new QSlider(samllwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(100, 60, 160, 22));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        retranslateUi(samllwidget);

        QMetaObject::connectSlotsByName(samllwidget);
    } // setupUi

    void retranslateUi(QWidget *samllwidget)
    {
        samllwidget->setWindowTitle(QCoreApplication::translate("samllwidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class samllwidget: public Ui_samllwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMLLWIDGET_H
