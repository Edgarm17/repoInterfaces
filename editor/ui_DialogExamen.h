/********************************************************************************
** Form generated from reading UI file 'DialogExamen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEXAMEN_H
#define UI_DIALOGEXAMEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_DialogExamen
{
public:
    QDial *dial;
    QLabel *valor;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QRadioButton *rb_insercion;
    QRadioButton *rb_movimiento;
    QPushButton *btnAtras;
    QPushButton *btnAlante;
    QGroupBox *groupBox_2;
    QComboBox *comboBox;
    QLabel *labelPosicion;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *le_palabra;
    QPushButton *btnIntroTexto;
    QCheckBox *checkAdd;
    QComboBox *comboPalabras;
    QLabel *label_6;

    void setupUi(QDialog *DialogExamen)
    {
        if (DialogExamen->objectName().isEmpty())
            DialogExamen->setObjectName(QString::fromUtf8("DialogExamen"));
        DialogExamen->resize(860, 700);
        dial = new QDial(DialogExamen);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(30, 60, 140, 170));
        valor = new QLabel(DialogExamen);
        valor->setObjectName(QString::fromUtf8("valor"));
        valor->setGeometry(QRect(220, 110, 201, 31));
        label = new QLabel(DialogExamen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 287, 17));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        buttonBox = new QDialogButtonBox(DialogExamen);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(640, 650, 181, 25));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(DialogExamen);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 400, 287, 199));
        rb_insercion = new QRadioButton(groupBox);
        rb_insercion->setObjectName(QString::fromUtf8("rb_insercion"));
        rb_insercion->setGeometry(QRect(10, 100, 112, 23));
        rb_movimiento = new QRadioButton(groupBox);
        rb_movimiento->setObjectName(QString::fromUtf8("rb_movimiento"));
        rb_movimiento->setGeometry(QRect(10, 40, 112, 23));
        sizePolicy.setHeightForWidth(rb_movimiento->sizePolicy().hasHeightForWidth());
        rb_movimiento->setSizePolicy(sizePolicy);
        btnAtras = new QPushButton(DialogExamen);
        btnAtras->setObjectName(QString::fromUtf8("btnAtras"));
        btnAtras->setGeometry(QRect(20, 280, 279, 25));
        btnAlante = new QPushButton(DialogExamen);
        btnAlante->setObjectName(QString::fromUtf8("btnAlante"));
        btnAlante->setGeometry(QRect(20, 340, 279, 25));
        btnAlante->setSizeIncrement(QSize(0, 0));
        groupBox_2 = new QGroupBox(DialogExamen);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(500, 10, 341, 121));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 40, 241, 25));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);
        labelPosicion = new QLabel(groupBox_2);
        labelPosicion->setObjectName(QString::fromUtf8("labelPosicion"));
        labelPosicion->setGeometry(QRect(10, 90, 141, 17));
        label_4 = new QLabel(DialogExamen);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(500, 290, 211, 17));
        label_5 = new QLabel(DialogExamen);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(500, 320, 121, 17));
        le_palabra = new QLineEdit(DialogExamen);
        le_palabra->setObjectName(QString::fromUtf8("le_palabra"));
        le_palabra->setGeometry(QRect(630, 320, 211, 25));
        btnIntroTexto = new QPushButton(DialogExamen);
        btnIntroTexto->setObjectName(QString::fromUtf8("btnIntroTexto"));
        btnIntroTexto->setGeometry(QRect(718, 350, 121, 25));
        checkAdd = new QCheckBox(DialogExamen);
        checkAdd->setObjectName(QString::fromUtf8("checkAdd"));
        checkAdd->setGeometry(QRect(500, 390, 211, 23));
        comboPalabras = new QComboBox(DialogExamen);
        comboPalabras->setObjectName(QString::fromUtf8("comboPalabras"));
        comboPalabras->setGeometry(QRect(500, 500, 341, 25));
        label_6 = new QLabel(DialogExamen);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(500, 470, 181, 17));

        retranslateUi(DialogExamen);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogExamen, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogExamen, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogExamen);
    } // setupUi

    void retranslateUi(QDialog *DialogExamen)
    {
        DialogExamen->setWindowTitle(QApplication::translate("DialogExamen", "Dialog", nullptr));
        valor->setText(QApplication::translate("DialogExamen", "Valor:", nullptr));
        label->setText(QApplication::translate("DialogExamen", "Tama\303\261o de bloque", nullptr));
        groupBox->setTitle(QApplication::translate("DialogExamen", " Modo del funcionamiento del di\303\241logo", nullptr));
        rb_insercion->setText(QApplication::translate("DialogExamen", "Insercion", nullptr));
        rb_movimiento->setText(QApplication::translate("DialogExamen", "Movimiento", nullptr));
        btnAtras->setText(QApplication::translate("DialogExamen", "Atras", nullptr));
        btnAlante->setText(QApplication::translate("DialogExamen", "Adelante", nullptr));
        groupBox_2->setTitle(QApplication::translate("DialogExamen", "Informaci\303\263n del cursor inicial", nullptr));
        labelPosicion->setText(QApplication::translate("DialogExamen", "Posicion Actual: ", nullptr));
        label_4->setText(QApplication::translate("DialogExamen", "Control de inserci\303\263n de texto", nullptr));
        label_5->setText(QApplication::translate("DialogExamen", "Texto a introducir", nullptr));
        btnIntroTexto->setText(QApplication::translate("DialogExamen", "Introducir texto", nullptr));
        checkAdd->setText(QApplication::translate("DialogExamen", "A\303\261adir a la lista de palabras", nullptr));
        label_6->setText(QApplication::translate("DialogExamen", "Palabras ya introducidas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogExamen: public Ui_DialogExamen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEXAMEN_H
