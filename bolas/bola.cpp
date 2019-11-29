#include "bola.h"
#include <math.h>
#include <QPainter>

Bola::Bola(float  posX, float  posY, float velX, float velY)
{
	x = posX;
	y = posY;
	vX = velX;
	vY = velY;
	
}

void Bola::pintarBola(QPainter & pintor){
	pintor.drawEllipse(x,y,20,20);
    	
    	
    	
}

