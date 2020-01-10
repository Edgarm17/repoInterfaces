/********************************************************************************
** Form generated from reading UI file 'widgetBola.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETBOLA_H
#define UI_WIDGETBOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetBola
{
public:
    QPushButton *btnParar;
    QPushButton *btnColor;

    void setupUi(QWidget *WidgetBola)
    {
        if (WidgetBola->objectName().isEmpty())
            WidgetBola->setObjectName(QStringLiteral("WidgetBola"));
        WidgetBola->resize(188, 208);
        btnParar = new QPushButton(WidgetBola);
        btnParar->setObjectName(QStringLiteral("btnParar"));
        btnParar->setGeometry(QRect(50, 40, 89, 25));
        btnColor = new QPushButton(WidgetBola);
        btnColor->setObjectName(QStringLiteral("btnColor"));
        btnColor->setGeometry(QRect(50, 130, 89, 25));

        retranslateUi(WidgetBola);

        QMetaObject::connectSlotsByName(WidgetBola);
    } // setupUi

    void retranslateUi(QWidget *WidgetBola)
    {
        WidgetBola->setWindowTitle(QApplication::translate("WidgetBola", "Form", Q_NULLPTR));
        btnParar->setText(QApplication::translate("WidgetBola", "Parar Bola", Q_NULLPTR));
        btnColor->setText(QApplication::translate("WidgetBola", "Elegir color", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetBola: public Ui_WidgetBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETBOLA_H
