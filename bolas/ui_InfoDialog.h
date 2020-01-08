/********************************************************************************
** Form generated from reading UI file 'InfoDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFODIALOG_H
#define UI_INFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_InfoDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *lbNum;
    QLabel *lbSize;

    void setupUi(QDialog *InfoDialog)
    {
        if (InfoDialog->objectName().isEmpty())
            InfoDialog->setObjectName(QStringLiteral("InfoDialog"));
        InfoDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(InfoDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(InfoDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 60, 121, 17));
        label_2 = new QLabel(InfoDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 130, 121, 17));
        lbNum = new QLabel(InfoDialog);
        lbNum->setObjectName(QStringLiteral("lbNum"));
        lbNum->setGeometry(QRect(200, 60, 67, 17));
        lbSize = new QLabel(InfoDialog);
        lbSize->setObjectName(QStringLiteral("lbSize"));
        lbSize->setGeometry(QRect(190, 130, 67, 17));

        retranslateUi(InfoDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), InfoDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InfoDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(InfoDialog);
    } // setupUi

    void retranslateUi(QDialog *InfoDialog)
    {
        InfoDialog->setWindowTitle(QApplication::translate("InfoDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("InfoDialog", "N\303\272mero de bolas:", Q_NULLPTR));
        label_2->setText(QApplication::translate("InfoDialog", "Tama\303\261o ventana:", Q_NULLPTR));
        lbNum->setText(QString());
        lbSize->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InfoDialog: public Ui_InfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFODIALOG_H
