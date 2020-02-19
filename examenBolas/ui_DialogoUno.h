/********************************************************************************
** Form generated from reading UI file 'DialogoUno.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOUNO_H
#define UI_DIALOGOUNO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_DialogoUno
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogoUno)
    {
        if (DialogoUno->objectName().isEmpty())
            DialogoUno->setObjectName(QString::fromUtf8("DialogoUno"));
        DialogoUno->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogoUno);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogoUno);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoUno, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoUno, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogoUno);
    } // setupUi

    void retranslateUi(QDialog *DialogoUno)
    {
        DialogoUno->setWindowTitle(QApplication::translate("DialogoUno", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogoUno: public Ui_DialogoUno {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOUNO_H
