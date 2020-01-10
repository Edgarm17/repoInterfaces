#include <BolaYWidget.h>
#include <bola.h>
#include <widgetBola.h>

BolaYWidget::BolaYWidget(bool jugador, float x, float y, float vX, float vY, float radio, QWidget * parent) :
	 Bola(jugador,x,y,vX,vY,radio) , WidgetBola(this, parent)
{
	
	
}


BolaYWidget::BolaYWidget(bool jugador, float x, float y, float vX, float vY, float radio,QColor color, QWidget * parent) :
	 Bola(jugador,x,y,vX,vY,radio,color) , WidgetBola(this, parent)
{
	
	
}
