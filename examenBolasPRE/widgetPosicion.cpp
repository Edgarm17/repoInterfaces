#include "widgetPosicion.h"
#include <QDebug>
WidgetPosicion::WidgetPosicion(QWidget * parent) : QWidget(parent){

	
	
	
	
	
}



void WidgetPosicion::mousePressEvent(QMouseEvent *event){

	
	emit posicionCambiada(event->x(),event->y());

}












