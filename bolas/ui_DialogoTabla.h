/********************************************************************************
** Form generated from reading UI file 'DialogoTabla.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOTABLA_H
#define UI_DIALOGOTABLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DialogoTabla
{
public:
    QDialogButtonBox *buttonBox;
    QTableView *tableView;

    void setupUi(QDialog *DialogoTabla)
    {
        if (DialogoTabla->objectName().isEmpty())
            DialogoTabla->setObjectName(QString::fromUtf8("DialogoTabla"));
        DialogoTabla->resize(650, 369);
        buttonBox = new QDialogButtonBox(DialogoTabla);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 330, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableView = new QTableView(DialogoTabla);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(40, 20, 521, 281));

        retranslateUi(DialogoTabla);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoTabla, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoTabla, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogoTabla);
    } // setupUi

    void retranslateUi(QDialog *DialogoTabla)
    {
        DialogoTabla->setWindowTitle(QApplication::translate("DialogoTabla", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogoTabla: public Ui_DialogoTabla {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOTABLA_H
