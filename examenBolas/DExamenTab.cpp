#include "DExamenTab.h"
#include "BolaYWidget.h"
#include <QVector>
#include "widgetBola.h"
#include <QDebug>

DExamenTab::DExamenTab(QVector<BolaYWidget*> * bolas,QWidget * parent) : QDialog(parent){

	setupUi(this);
	
	this->bolas = bolas;
	tabla->clear();
	
	for(int i = 0; i < bolas->size(); i++){
	
		tabla->insertTab(i, bolas->at(i), QString("Bola ")+QString::number(i));
	
	}
	
}




