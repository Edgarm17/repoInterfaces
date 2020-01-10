#include "DControlBolas.h"
#include "bola.h"
#include <QVector>
#include "widgetBola.h"

DControlBolas::DControlBolas(QVector<Bola*> * bolas,QWidget * parent) : QDialog(parent){

	setupUi(this);
	

	this->bolas = bolas;
	tabBolas->clear();
	this->insertarBolas(bolas);
	bolas->at(0)->seleccionada = true;
	
	connect(btnPararTodas, SIGNAL(clicked()),this, SLOT(slotPararBolas()));
	connect(tabBolas, SIGNAL(currentChanged(int)),this, SLOT(slotBolaSeleccionada(int)));
	
}

void DControlBolas::insertarBolas(QVector<Bola*> * bolas){

	for(int i = 0; i < bolas->size(); i++){
	
		tabBolas->insertTab(i, new WidgetBola(bolas->at(i)), QString("Bola ")+QString::number(i));
	
	}

}

void DControlBolas::slotBolaSeleccionada(int index){

	//for(int i = 0; i < bolas->size(); i++){
	//	if(i == index){
	//		bolas->at(i)->seleccionada = true;
	//	}else{
	//		bolas->at(i)->seleccionada = false;
	//	}
	//}


	for(int i = 0; i < tabBolas->count(); i++){
		WidgetBola * widget = qobject_cast<WidgetBola *>( tabBolas->widget(i) );
		Bola * bolaSel = widget->bola;
		bolaSel->seleccionada = false;
	
	}
	
	WidgetBola * widgetActual = qobject_cast<WidgetBola *>( tabBolas->currentWidget() );
	Bola * aResaltar = widgetActual->bola;
	aResaltar->seleccionada = true;

}

void DControlBolas::slotPararBolas(){

	for(int i = 0; i < tabBolas->count(); i++){
		WidgetBola * widget = qobject_cast<WidgetBola *>( tabBolas->widget(i) );
		widget->slotPararBola();
	
	}

}


void DControlBolas::closeEvent(QCloseEvent *e){
	for(int i = 0; i < bolas->size(); i++){
		bolas->at(i)->seleccionada = false;
	}
}



