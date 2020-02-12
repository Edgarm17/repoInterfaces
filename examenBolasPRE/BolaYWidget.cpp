#include <BolaYWidget.h>
#include <bola.h>
#include <WidgetPRE.h>

BolaYWidget::BolaYWidget(bool jugador, float x, float y, float vX, float vY, float radio, QWidget * parent) :
	 Bola(jugador,x,y,vX,vY,radio) , WidgetPRE(this, parent)
{
	
	
}


BolaYWidget::BolaYWidget(bool jugador, float x, float y, float vX, float vY, float radio,QColor color, QWidget * parent) :
	 Bola(jugador,x,y,vX,vY,radio,color) , WidgetPRE(this, parent)
{
	
	
}

BolaYWidget::BolaYWidget(bool jugador, float x, float y, float vX, float vY, float radio,QImage imagen, QWidget * parent) :
	 Bola(jugador,x,y,vX,vY,radio,imagen) , WidgetPRE(this, parent)
{
	
	
}
