/********************************************************************************
** Form generated from reading UI file 'WidgetInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETINFO_H
#define UI_WIDGETINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetInfo
{
public:
    QLabel *labelNumBola;
    QPushButton *botonNext;
    QPushButton *botonPrevious;
    QFrame *frameChart;
    QSpinBox *spinBox;
    QLabel *label_2;
    QCheckBox *chBNoCerrar;

    void setupUi(QWidget *WidgetInfo)
    {
        if (WidgetInfo->objectName().isEmpty())
            WidgetInfo->setObjectName(QString::fromUtf8("WidgetInfo"));
        WidgetInfo->resize(575, 437);
        labelNumBola = new QLabel(WidgetInfo);
        labelNumBola->setObjectName(QString::fromUtf8("labelNumBola"));
        labelNumBola->setGeometry(QRect(20, 20, 181, 16));
        botonNext = new QPushButton(WidgetInfo);
        botonNext->setObjectName(QString::fromUtf8("botonNext"));
        botonNext->setGeometry(QRect(170, 350, 86, 27));
        botonPrevious = new QPushButton(WidgetInfo);
        botonPrevious->setObjectName(QString::fromUtf8("botonPrevious"));
        botonPrevious->setGeometry(QRect(60, 350, 86, 27));
        frameChart = new QFrame(WidgetInfo);
        frameChart->setObjectName(QString::fromUtf8("frameChart"));
        frameChart->setGeometry(QRect(50, 50, 471, 261));
        frameChart->setFrameShape(QFrame::StyledPanel);
        frameChart->setFrameShadow(QFrame::Raised);
        spinBox = new QSpinBox(WidgetInfo);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(150, 390, 42, 26));
        label_2 = new QLabel(WidgetInfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 390, 101, 16));
        chBNoCerrar = new QCheckBox(WidgetInfo);
        chBNoCerrar->setObjectName(QString::fromUtf8("chBNoCerrar"));
        chBNoCerrar->setGeometry(QRect(280, 350, 86, 21));

        retranslateUi(WidgetInfo);

        QMetaObject::connectSlotsByName(WidgetInfo);
    } // setupUi

    void retranslateUi(QWidget *WidgetInfo)
    {
        WidgetInfo->setWindowTitle(QApplication::translate("WidgetInfo", "Form", nullptr));
        labelNumBola->setText(QApplication::translate("WidgetInfo", "Bola N\303\272mero ", nullptr));
        botonNext->setText(QApplication::translate("WidgetInfo", "Next Ball", nullptr));
        botonPrevious->setText(QApplication::translate("WidgetInfo", "Previous Ball", nullptr));
        label_2->setText(QApplication::translate("WidgetInfo", "Hijos En \303\241rbol", nullptr));
        chBNoCerrar->setText(QApplication::translate("WidgetInfo", "No Cerrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetInfo: public Ui_WidgetInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETINFO_H
