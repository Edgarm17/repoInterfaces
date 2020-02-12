/********************************************************************************
** Form generated from reading UI file 'DialogProva.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPROVA_H
#define UI_DIALOGPROVA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogProva
{
public:
    QPushButton *btnCrear;
    QLabel *label;
    QLineEdit *lePosX;
    QLabel *label_2;
    QLineEdit *lePosY;
    QLabel *label_3;
    QLineEdit *leVel;
    QLabel *label_4;
    QComboBox *cbApariencia;
    QLabel *label_5;
    QLineEdit *leRadio;
    QPushButton *btnElegir;

    void setupUi(QDialog *DialogProva)
    {
        if (DialogProva->objectName().isEmpty())
            DialogProva->setObjectName(QString::fromUtf8("DialogProva"));
        DialogProva->resize(430, 202);
        btnCrear = new QPushButton(DialogProva);
        btnCrear->setObjectName(QString::fromUtf8("btnCrear"));
        btnCrear->setGeometry(QRect(330, 160, 89, 25));
        label = new QLabel(DialogProva);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 71, 17));
        lePosX = new QLineEdit(DialogProva);
        lePosX->setObjectName(QString::fromUtf8("lePosX"));
        lePosX->setGeometry(QRect(90, 40, 41, 21));
        label_2 = new QLabel(DialogProva);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 71, 17));
        lePosY = new QLineEdit(DialogProva);
        lePosY->setObjectName(QString::fromUtf8("lePosY"));
        lePosY->setGeometry(QRect(90, 80, 41, 21));
        label_3 = new QLabel(DialogProva);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 160, 71, 17));
        leVel = new QLineEdit(DialogProva);
        leVel->setObjectName(QString::fromUtf8("leVel"));
        leVel->setGeometry(QRect(90, 160, 41, 21));
        label_4 = new QLabel(DialogProva);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 40, 81, 17));
        cbApariencia = new QComboBox(DialogProva);
        cbApariencia->setObjectName(QString::fromUtf8("cbApariencia"));
        cbApariencia->setGeometry(QRect(260, 40, 86, 21));
        label_5 = new QLabel(DialogProva);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 120, 41, 17));
        leRadio = new QLineEdit(DialogProva);
        leRadio->setObjectName(QString::fromUtf8("leRadio"));
        leRadio->setGeometry(QRect(90, 120, 41, 21));
        btnElegir = new QPushButton(DialogProva);
        btnElegir->setObjectName(QString::fromUtf8("btnElegir"));
        btnElegir->setGeometry(QRect(360, 30, 51, 31));

        retranslateUi(DialogProva);

        QMetaObject::connectSlotsByName(DialogProva);
    } // setupUi

    void retranslateUi(QDialog *DialogProva)
    {
        DialogProva->setWindowTitle(QApplication::translate("DialogProva", "Dialog", nullptr));
        btnCrear->setText(QApplication::translate("DialogProva", "Crear bola", nullptr));
        label->setText(QApplication::translate("DialogProva", "Poscion X:", nullptr));
        label_2->setText(QApplication::translate("DialogProva", "Poscion Y:", nullptr));
        label_3->setText(QApplication::translate("DialogProva", "Velocidad:", nullptr));
        label_4->setText(QApplication::translate("DialogProva", "Apariencia:", nullptr));
        label_5->setText(QApplication::translate("DialogProva", "Radio:", nullptr));
        btnElegir->setText(QApplication::translate("DialogProva", "Elegir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogProva: public Ui_DialogProva {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPROVA_H
