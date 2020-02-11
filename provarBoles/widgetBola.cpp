#include "widgetBola.h"
#include "bola.h"
#include <QColor>
#include <QColorDialog>

WidgetBola::WidgetBola(Bola * bola,QWidget * parent) : QWidget(parent){

	setupUi(this);
	this->bola = bola;
	
	connect(btnParar, SIGNAL(clicked()),this, SLOT(slotPararBola()));
	connect(btnColor, SIGNAL(clicked()),this, SLOT(slotElegirColor()));
}

void WidgetBola::slotPararBola(void){

	bola->vX = 0;
	bola->vY = 0;

}

void WidgetBola::slotElegirColor(void){


	QColor colorElegido = QColorDialog::getColor(Qt::white,this,"Elige un color");
	if( colorElegido.isValid() ){
	
		bola->color = colorElegido;
		
	}
}
