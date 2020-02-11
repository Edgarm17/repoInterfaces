/********************************************************************************
** Form generated from reading UI file 'DPieChart.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPIECHART_H
#define UI_DPIECHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_DPieChart
{
public:

    void setupUi(QDialog *DPieChart)
    {
        if (DPieChart->objectName().isEmpty())
            DPieChart->setObjectName(QString::fromUtf8("DPieChart"));
        DPieChart->resize(762, 474);

        retranslateUi(DPieChart);

        QMetaObject::connectSlotsByName(DPieChart);
    } // setupUi

    void retranslateUi(QDialog *DPieChart)
    {
        DPieChart->setWindowTitle(QApplication::translate("DPieChart", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DPieChart: public Ui_DPieChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPIECHART_H
