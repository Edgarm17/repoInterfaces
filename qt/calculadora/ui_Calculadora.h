/********************************************************************************
** Form generated from reading UI file 'Calculadora.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULADORA_H
#define UI_CALCULADORA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculadora
{
public:
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Calculadora)
    {
        if (Calculadora->objectName().isEmpty())
            Calculadora->setObjectName(QString::fromUtf8("Calculadora"));
        Calculadora->resize(400, 300);
        b1 = new QPushButton(Calculadora);
        b1->setObjectName(QString::fromUtf8("b1"));
        b1->setGeometry(QRect(20, 240, 89, 25));
        b2 = new QPushButton(Calculadora);
        b2->setObjectName(QString::fromUtf8("b2"));
        b2->setGeometry(QRect(130, 240, 89, 25));
        pushButton_3 = new QPushButton(Calculadora);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(240, 240, 89, 25));

        retranslateUi(Calculadora);

        QMetaObject::connectSlotsByName(Calculadora);
    } // setupUi

    void retranslateUi(QWidget *Calculadora)
    {
        Calculadora->setWindowTitle(QApplication::translate("Calculadora", "Form", nullptr));
        b1->setText(QApplication::translate("Calculadora", "1", nullptr));
        b2->setText(QApplication::translate("Calculadora", "2", nullptr));
        pushButton_3->setText(QApplication::translate("Calculadora", "3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculadora: public Ui_Calculadora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULADORA_H
