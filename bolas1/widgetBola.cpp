#include "widgetBola.h"
#include "bola.h"

WidgetBola::WidgetBola(Bola * bola,QWidget * parent) : QWidget(parent){

	setupUi(this);
	this->bola = bola;
	
	connect(btnParar, SIGNAL(clicked()),this, SLOT(slotPararBola()));
}

void WidgetBola::slotPararBola(void){

	bola->vX = 0;
	bola->vY = 0;

}

void WidgetBola::slotCambiarColor(void){

}
