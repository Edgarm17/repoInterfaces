
#include <QtGui>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>
#include <QHBoxLayout>
#include <QListWidget>
#include "mainDialog.h"


 MainDialog::MainDialog(QWidget *parent)
      : QDialog(parent)
  {
      
      
      	labelBack = new QLabel(tr("Backward"));
      	labelFord = new QLabel(tr("Fordward"));
	back = new QListWidget();
	ford = new QListWidget();     
	   
	QVBoxLayout *leftLayout = new QVBoxLayout;
	leftLayout->addWidget(labelBack);
	leftLayout->addWidget(back);
	
	QVBoxLayout *rightLayout = new QVBoxLayout;
	rightLayout->addWidget(labelFord);
	rightLayout->addWidget(ford);
         
        QHBoxLayout *mainLayout = new QHBoxLayout;
         
	
	
	
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	
	setLayout(mainLayout);


    	
 	setWindowTitle(tr("Lista"));
    	setFixedHeight(sizeHint().height());
 }

 
void MainDialog::slotBackward(const QString &str, Qt::CaseSensitivity cs){
	back->addItem(str);
}
void MainDialog::slotFordward(const QString &str, Qt::CaseSensitivity cs){
	ford->addItem(str);
}
