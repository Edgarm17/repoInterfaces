#include "DControlBolas.h"
#include "BolaYWidget.h"
#include <QVector>
#include "widgetBola.h"
#include "bola.h"
#include <QDebug>

DControlBolas::DControlBolas(QVector<BolaYWidget*> * bolas,QWidget * parent) : QDialog(parent){

	setupUi(this);
	

	this->bolas = bolas;
	bolasAux = bolas;
	tabBolas->clear();
	this->insertarBolas(bolas);
	bolas->at(0)->seleccionada = true;
	
	connect(btnPararTodas, SIGNAL(clicked()),this, SLOT(slotPararBolas()));
	connect(tabBolas, SIGNAL(currentChanged(int)),this, SLOT(slotBolaSeleccionada(int)));
	connect(buttonBox, SIGNAL(accepted()),this, SLOT(slotCancelar()));
	connect(buttonBox, SIGNAL(rejected()),this, SLOT(slotCancelar()));
	
}

void DControlBolas::insertarBolas(QVector<BolaYWidget*> * bolas){

	for(int i = 0; i < bolas->size(); i++){
	
		tabBolas->insertTab(i, bolas->at(i), QString("Bola ")+QString::number(i));
	
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
		BolaYWidget * widget = qobject_cast<BolaYWidget *>( tabBolas->widget(i) );
		Bola * bolaSel = widget->bola;
		bolaSel->seleccionada = false;
	
	}
	
	BolaYWidget * widgetActual = qobject_cast<BolaYWidget *>( tabBolas->currentWidget() );
	Bola * aResaltar = widgetActual->bola;
	aResaltar->seleccionada = true;

}

void DControlBolas::slotPararBolas(){

	for(int i = 0; i < tabBolas->count(); i++){
		BolaYWidget * widget = qobject_cast<BolaYWidget *>( tabBolas->widget(i) );
		widget->slotPararBola();
	
	}

}


void DControlBolas::closeEvent(QCloseEvent *e){
	for(int i = 0; i < bolas->size(); i++){
		bolas->at(i)->seleccionada = false;
	}
}


void DControlBolas::slotAceptar(){

	   

}

void DControlBolas::slotCancelar(){

	qDebug()<<"Hola";
	for(int i = 0; i < bolas->size(); i++){
		bolas->at(i)->seleccionada = false;
	}

}


