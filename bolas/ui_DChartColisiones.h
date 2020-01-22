/********************************************************************************
** Form generated from reading UI file 'DChartColisiones.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCHARTCOLISIONES_H
#define UI_DCHARTCOLISIONES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DChartColisiones
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *FrameBolas;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DChartColisiones)
    {
        if (DChartColisiones->objectName().isEmpty())
            DChartColisiones->setObjectName(QString::fromUtf8("DChartColisiones"));
        DChartColisiones->resize(757, 467);
        verticalLayout = new QVBoxLayout(DChartColisiones);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        FrameBolas = new QFrame(DChartColisiones);
        FrameBolas->setObjectName(QString::fromUtf8("FrameBolas"));
        FrameBolas->setFrameShape(QFrame::StyledPanel);
        FrameBolas->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(FrameBolas);

        buttonBox = new QDialogButtonBox(DChartColisiones);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DChartColisiones);
        QObject::connect(buttonBox, SIGNAL(accepted()), DChartColisiones, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DChartColisiones, SLOT(reject()));

        QMetaObject::connectSlotsByName(DChartColisiones);
    } // setupUi

    void retranslateUi(QDialog *DChartColisiones)
    {
        DChartColisiones->setWindowTitle(QApplication::translate("DChartColisiones", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DChartColisiones: public Ui_DChartColisiones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCHARTCOLISIONES_H
