/********************************************************************************
** Form generated from reading UI file 'widgetBola.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETBOLA_H
#define UI_WIDGETBOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetBola
{
public:
    QPushButton *btnParar;
    QPushButton *btnElegir;

    void setupUi(QWidget *WidgetBola)
    {
        if (WidgetBola->objectName().isEmpty())
            WidgetBola->setObjectName(QString::fromUtf8("WidgetBola"));
        WidgetBola->resize(190, 208);
        btnParar = new QPushButton(WidgetBola);
        btnParar->setObjectName(QString::fromUtf8("btnParar"));
        btnParar->setGeometry(QRect(50, 40, 89, 25));
        btnElegir = new QPushButton(WidgetBola);
        btnElegir->setObjectName(QString::fromUtf8("btnElegir"));
        btnElegir->setGeometry(QRect(50, 130, 89, 25));

        retranslateUi(WidgetBola);

        QMetaObject::connectSlotsByName(WidgetBola);
    } // setupUi

    void retranslateUi(QWidget *WidgetBola)
    {
        WidgetBola->setWindowTitle(QApplication::translate("WidgetBola", "Form", nullptr));
        btnParar->setText(QApplication::translate("WidgetBola", "Parar Bola", nullptr));
        btnElegir->setText(QApplication::translate("WidgetBola", "Elegir color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetBola: public Ui_WidgetBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETBOLA_H
