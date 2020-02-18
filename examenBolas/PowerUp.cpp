#include "PowerUp.h"
#include <QPainter>

PowerUp::PowerUp(float pX, float pY, QImage img){
	posX = pX;
	posY = pY;
	imagen = img;
	width = 50.0;
	height = 50.0;
	imagen = imagen.scaled(width,height);
}

void PowerUp::pintarPU(QPainter & pintor){

	
	pintor.drawImage(posX,posY,imagen);
	
}

void PowerUp::resizePU(){
	
	
	if(width<30){
		width++;
		height++;
		imagen.scaled(width,height);
	}else if(width>30 && width>0){
		width--;
		height--;
		imagen = imagen.scaled(width,height);
	}
}
