/********************************************************************************
** Form generated from reading UI file 'DExamenTab.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEXAMENTAB_H
#define UI_DEXAMENTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DExamenTab
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabla;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QDialog *DExamenTab)
    {
        if (DExamenTab->objectName().isEmpty())
            DExamenTab->setObjectName(QString::fromUtf8("DExamenTab"));
        DExamenTab->resize(637, 418);
        buttonBox = new QDialogButtonBox(DExamenTab);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 380, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabla = new QTabWidget(DExamenTab);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        tabla->setGeometry(QRect(20, 30, 591, 341));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabla->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabla->addTab(tab_2, QString());

        retranslateUi(DExamenTab);
        QObject::connect(buttonBox, SIGNAL(accepted()), DExamenTab, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DExamenTab, SLOT(reject()));

        tabla->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DExamenTab);
    } // setupUi

    void retranslateUi(QDialog *DExamenTab)
    {
        DExamenTab->setWindowTitle(QApplication::translate("DExamenTab", "Dialog", nullptr));
        tabla->setTabText(tabla->indexOf(tab), QApplication::translate("DExamenTab", "Tab 1", nullptr));
        tabla->setTabText(tabla->indexOf(tab_2), QApplication::translate("DExamenTab", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DExamenTab: public Ui_DExamenTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEXAMENTAB_H
