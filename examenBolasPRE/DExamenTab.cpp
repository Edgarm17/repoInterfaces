#include "DExamenTab.h"
#include <QVector>
#include "WidgetPRE.h"
#include <QDebug>

DExamenTab::DExamenTab(QVector<Bola*> * bolas,QWidget * parent) : QDialog(parent){

	setupUi(this);
	
	this->bolas = bolas;
	tabla->clear();
	
	
	for(int i = 0; i < bolas->size(); i++){
	
		tabla->insertTab(i, new WidgetPRE(bolas->at(i)), QString("Bola ")+QString::number(i));
	
	}


	
	
	
	
	
}




