/********************************************************************************
** Form generated from reading UI file 'DialogInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGINFO_H
#define UI_DIALOGINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DialogInfo
{
public:
    QLabel *lbPosX;
    QLabel *lbPosY;
    QLabel *lbVel;
    QLabel *lbId;

    void setupUi(QDialog *DialogInfo)
    {
        if (DialogInfo->objectName().isEmpty())
            DialogInfo->setObjectName(QString::fromUtf8("DialogInfo"));
        DialogInfo->resize(220, 198);
        lbPosX = new QLabel(DialogInfo);
        lbPosX->setObjectName(QString::fromUtf8("lbPosX"));
        lbPosX->setGeometry(QRect(30, 40, 181, 17));
        lbPosY = new QLabel(DialogInfo);
        lbPosY->setObjectName(QString::fromUtf8("lbPosY"));
        lbPosY->setGeometry(QRect(30, 70, 181, 17));
        lbVel = new QLabel(DialogInfo);
        lbVel->setObjectName(QString::fromUtf8("lbVel"));
        lbVel->setGeometry(QRect(30, 100, 171, 17));
        lbId = new QLabel(DialogInfo);
        lbId->setObjectName(QString::fromUtf8("lbId"));
        lbId->setGeometry(QRect(30, 140, 171, 17));

        retranslateUi(DialogInfo);

        QMetaObject::connectSlotsByName(DialogInfo);
    } // setupUi

    void retranslateUi(QDialog *DialogInfo)
    {
        DialogInfo->setWindowTitle(QApplication::translate("DialogInfo", "Dialog", nullptr));
        lbPosX->setText(QApplication::translate("DialogInfo", "Posicion X:", nullptr));
        lbPosY->setText(QApplication::translate("DialogInfo", "Posicion Y:", nullptr));
        lbVel->setText(QApplication::translate("DialogInfo", "Velocidad:", nullptr));
        lbId->setText(QApplication::translate("DialogInfo", "Id:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogInfo: public Ui_DialogInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGINFO_H
