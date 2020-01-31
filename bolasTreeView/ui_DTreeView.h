/********************************************************************************
** Form generated from reading UI file 'DTreeView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTREEVIEW_H
#define UI_DTREEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DTreeView
{
public:
    QVBoxLayout *verticalLayout;
    QTreeView *treeBolas;
    QPushButton *btnTreeview;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DTreeView)
    {
        if (DTreeView->objectName().isEmpty())
            DTreeView->setObjectName(QString::fromUtf8("DTreeView"));
        DTreeView->resize(694, 446);
        verticalLayout = new QVBoxLayout(DTreeView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeBolas = new QTreeView(DTreeView);
        treeBolas->setObjectName(QString::fromUtf8("treeBolas"));

        verticalLayout->addWidget(treeBolas);

        btnTreeview = new QPushButton(DTreeView);
        btnTreeview->setObjectName(QString::fromUtf8("btnTreeview"));

        verticalLayout->addWidget(btnTreeview);

        buttonBox = new QDialogButtonBox(DTreeView);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DTreeView);
        QObject::connect(buttonBox, SIGNAL(accepted()), DTreeView, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DTreeView, SLOT(reject()));

        QMetaObject::connectSlotsByName(DTreeView);
    } // setupUi

    void retranslateUi(QDialog *DTreeView)
    {
        DTreeView->setWindowTitle(QApplication::translate("DTreeView", "Dialog", nullptr));
        btnTreeview->setText(QApplication::translate("DTreeView", "Recargar arbol", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DTreeView: public Ui_DTreeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTREEVIEW_H
