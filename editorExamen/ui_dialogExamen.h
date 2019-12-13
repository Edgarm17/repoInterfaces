/********************************************************************************
** Form generated from reading UI file 'dialogExamen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEXAMEN_H
#define UI_DIALOGEXAMEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogExamen
{
public:
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QDial *dial;
    QLabel *lbValor;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QPushButton *btnAtras;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnAdelante;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QRadioButton *rbMovimiento;
    QRadioButton *rbInsercion;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QComboBox *cbCursor;
    QLabel *lbPosicionActual;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnIntroTxt;
    QCheckBox *checkAdd;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_8;
    QComboBox *cbPalabras;
    QSpacerItem *verticalSpacer_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogExamen)
    {
        if (DialogExamen->objectName().isEmpty())
            DialogExamen->setObjectName(QStringLiteral("DialogExamen"));
        DialogExamen->resize(657, 588);
        verticalLayout_9 = new QVBoxLayout(DialogExamen);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DialogExamen);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        dial = new QDial(DialogExamen);
        dial->setObjectName(QStringLiteral("dial"));

        horizontalLayout->addWidget(dial);

        lbValor = new QLabel(DialogExamen);
        lbValor->setObjectName(QStringLiteral("lbValor"));

        horizontalLayout->addWidget(lbValor);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        btnAtras = new QPushButton(DialogExamen);
        btnAtras->setObjectName(QStringLiteral("btnAtras"));

        verticalLayout_3->addWidget(btnAtras);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        btnAdelante = new QPushButton(DialogExamen);
        btnAdelante->setObjectName(QStringLiteral("btnAdelante"));

        verticalLayout_3->addWidget(btnAdelante);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_3 = new QLabel(DialogExamen);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_5->addWidget(label_3);

        rbMovimiento = new QRadioButton(DialogExamen);
        rbMovimiento->setObjectName(QStringLiteral("rbMovimiento"));

        verticalLayout_5->addWidget(rbMovimiento);

        rbInsercion = new QRadioButton(DialogExamen);
        rbInsercion->setObjectName(QStringLiteral("rbInsercion"));

        verticalLayout_5->addWidget(rbInsercion);


        verticalLayout->addLayout(verticalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(DialogExamen);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        cbCursor = new QComboBox(groupBox);
        cbCursor->setObjectName(QStringLiteral("cbCursor"));

        verticalLayout_6->addWidget(cbCursor);

        lbPosicionActual = new QLabel(groupBox);
        lbPosicionActual->setObjectName(QStringLiteral("lbPosicionActual"));

        verticalLayout_6->addWidget(lbPosicionActual);


        verticalLayout_7->addLayout(verticalLayout_6);


        verticalLayout_2->addWidget(groupBox);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        label_5 = new QLabel(DialogExamen);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(DialogExamen);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        lineEdit = new QLineEdit(DialogExamen);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        btnIntroTxt = new QPushButton(DialogExamen);
        btnIntroTxt->setObjectName(QStringLiteral("btnIntroTxt"));

        horizontalLayout_4->addWidget(btnIntroTxt);


        verticalLayout_2->addLayout(horizontalLayout_4);

        checkAdd = new QCheckBox(DialogExamen);
        checkAdd->setObjectName(QStringLiteral("checkAdd"));

        verticalLayout_2->addWidget(checkAdd);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(DialogExamen);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        cbPalabras = new QComboBox(DialogExamen);
        cbPalabras->setObjectName(QStringLiteral("cbPalabras"));

        verticalLayout_8->addWidget(cbPalabras);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_4);


        verticalLayout_2->addLayout(verticalLayout_8);


        horizontalLayout_6->addLayout(verticalLayout_2);


        verticalLayout_9->addLayout(horizontalLayout_6);

        buttonBox = new QDialogButtonBox(DialogExamen);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_9->addWidget(buttonBox);


        retranslateUi(DialogExamen);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogExamen, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogExamen, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogExamen);
    } // setupUi

    void retranslateUi(QDialog *DialogExamen)
    {
        DialogExamen->setWindowTitle(QApplication::translate("DialogExamen", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogExamen", "Tama\303\261o de bloque", Q_NULLPTR));
        lbValor->setText(QApplication::translate("DialogExamen", "Valor:", Q_NULLPTR));
        btnAtras->setText(QApplication::translate("DialogExamen", "Atr\303\241s", Q_NULLPTR));
        btnAdelante->setText(QApplication::translate("DialogExamen", "Adelante", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogExamen", "Modo de funcionamiento del di\303\241logo", Q_NULLPTR));
        rbMovimiento->setText(QApplication::translate("DialogExamen", "Movimiento", Q_NULLPTR));
        rbInsercion->setText(QApplication::translate("DialogExamen", "Inserci\303\263n", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DialogExamen", "Informaci\303\263n del cursor inicial", Q_NULLPTR));
        cbCursor->clear();
        cbCursor->insertItems(0, QStringList()
         << QApplication::translate("DialogExamen", "Bloque", Q_NULLPTR)
         << QApplication::translate("DialogExamen", "Fila", Q_NULLPTR)
         << QApplication::translate("DialogExamen", "Columna", Q_NULLPTR)
        );
        lbPosicionActual->setText(QApplication::translate("DialogExamen", "Posici\303\263n Actual:", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogExamen", "Control de inserci\303\263n de texto", Q_NULLPTR));
        label_6->setText(QApplication::translate("DialogExamen", "Texto a introducir", Q_NULLPTR));
        btnIntroTxt->setText(QApplication::translate("DialogExamen", "Introducir texto", Q_NULLPTR));
        checkAdd->setText(QApplication::translate("DialogExamen", "A\303\261adir a lista de palabras", Q_NULLPTR));
        label_7->setText(QApplication::translate("DialogExamen", "Palabras ya introducidas", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogExamen: public Ui_DialogExamen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEXAMEN_H
