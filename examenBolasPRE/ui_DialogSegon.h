/********************************************************************************
** Form generated from reading UI file 'DialogSegon.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSEGON_H
#define UI_DIALOGSEGON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_DialogSegon
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogSegon)
    {
        if (DialogSegon->objectName().isEmpty())
            DialogSegon->setObjectName(QString::fromUtf8("DialogSegon"));
        DialogSegon->resize(637, 416);
        buttonBox = new QDialogButtonBox(DialogSegon);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(280, 370, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogSegon);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogSegon, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogSegon, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogSegon);
    } // setupUi

    void retranslateUi(QDialog *DialogSegon)
    {
        DialogSegon->setWindowTitle(QApplication::translate("DialogSegon", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSegon: public Ui_DialogSegon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSEGON_H
