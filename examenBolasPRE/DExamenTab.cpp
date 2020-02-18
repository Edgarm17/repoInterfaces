#include "DExamenTab.h"
#include <QVector>
#include "WidgetPRE.h"
#include <QDebug>

DExamenTab::DExamenTab(QVector<Bola*> * bolas,QWidget * parent) : QDialog(parent){

	setupUi(this);
	
	this->bolas = bolas;
	tabla->clear();
	
	connect(pushButton,SIGNAL(clicked()),this,SLOT(slotCambiarNombreBoton()));
	
	
	for(int i = 0; i < bolas->size(); i++){
		
		WidgetPRE * widget = new WidgetPRE(this->bolas->at(i));
		
		connect(this,SIGNAL(modificarTodosClicked(int)),widget,SLOT(slotModificarCheck(int)));
		
		
		tabla->insertTab(i, widget , QString("Bola ")+QString::number(i));
	
	}
	

	
}

void DExamenTab::slotCambiarNombreBoton(){

 	if(pushButton->text() == "Show all numbers"){
		pushButton->setText("Hide all numbers");
		emit modificarTodosClicked(1);
		
	}else{
		pushButton->setText("Show all numbers");
		emit modificarTodosClicked(0);
		
	}
	

}






