#ifndef BOLAYWIDGET_H
#define BOLAYWIDGET_H

#include "widgetBola.h"
#include "bola.h"

class BolaYWidget : public WidgetBola, public Bola{

	Q_OBJECT

public:
        BolaYWidget(bool jugador,float x, float y, float vX, float vY,float radio, QWidget * parent = 0);
        BolaYWidget(bool jugador,float x, float y, float vX, float vY,float radio, QColor color, QWidget * parent = 0);
        


};

#endif 
