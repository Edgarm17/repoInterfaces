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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DExamenTab
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabla;
    QWidget *tab;
    QWidget *tab_2;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DExamenTab)
    {
        if (DExamenTab->objectName().isEmpty())
            DExamenTab->setObjectName(QString::fromUtf8("DExamenTab"));
        DExamenTab->resize(637, 418);
        verticalLayout = new QVBoxLayout(DExamenTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabla = new QTabWidget(DExamenTab);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabla->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabla->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabla);

        listWidget = new QListWidget(DExamenTab);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout->addWidget(listWidget);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(DExamenTab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        buttonBox = new QDialogButtonBox(DExamenTab);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


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
        pushButton->setText(QApplication::translate("DExamenTab", "Show all numbers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DExamenTab: public Ui_DExamenTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEXAMENTAB_H
