#include "bola.h"
#include <math.h>
#include <QPainter>

Bola::Bola(bool esJugador,float  posX, float  posY, float velX, float velY, float rad)
{
	jugador = esJugador;
	x = posX;
	y = posY;
	vX = velX;
	vY = velY;
	radio = rad;
	vida = vidaInicial;
	color = QColor(rand()%256,rand()%256,rand()%256);
	
}

Bola::Bola(bool esJugador,float  posX, float  posY, float velX, float velY, float rad, QColor col) :
	 Bola(esJugador,posX,posY,velX,velY,radio)
{
	jugador = esJugador;
	x = posX;
	y = posY;
	vX = velX;
	vY = velY;
	radio = rad;
	vida = vidaInicial;
	color = col;
	
}

void Bola::pintarBola(QPainter & pintor){

	if(jugador){
		pintor.setBrush((QBrush(Qt::black)));
		pintor.setPen(Qt::red);
		pintor.drawEllipse(x,y,radio,radio);
	}else{
		pintor.setBrush(color);
		pintor.drawEllipse(x,y,radio,radio);
	}

	
    	
    	
    	
}

void Bola::mover(float altura, float anchura){
	/*Rebotes izquierda y derecha*/
    	
    	if(x > anchura-radio){
    		vX = -fabs(vX);
    	}
    	
    	if(x <= 0 ){
    		vX = fabs(vX);
    	}
    	
    	x = x + vX;
    	
    	
    	/*Rebotes arriba y abajo*/
    	
    	if(y > altura-radio){
    		vY = -fabs(vY);
    	}
    	
    	if(y <= 20 ){
    		vY = fabs(vY);
    	}
    	
    	y = y + vY;
}

bool Bola::chocar(Bola & otra){
	
	bool choque = false;
	
	Bola * izquierda;
	Bola * derecha;
	Bola * arriba;
	Bola * abajo;
	//Bola * grande;
	//Bola * pequena;
	
	//if(radio >= otra.radio){
	//	grande = this;
	//pequena = &otra;
	//}else{
	//	grande = &otra;
	//	pequena = this;
	//}
	

	if(calcDistancia(otra) > (radio+otra.radio)/2) return false;
	
	/* CHOQUE HORIZONTAL*/
	
	if(otra.x > x){
		derecha = &otra;
		izquierda = this;
	}else{
		derecha = this;
		izquierda = &otra;
	}
	
	
	if(izquierda->vX > derecha->vX){
		float aux = izquierda -> vX;
		izquierda->vX = derecha->vX;
		derecha->vX = aux;
		choque = true;
	}
	
	/*CHOQUE VERTICAL*/
	
	if(otra.y > y){
		abajo = &otra;
		arriba = this;
	}else{
		arriba = &otra;
		abajo = this;
	}
	
	if(arriba->vY > abajo->vY){
		float aux = abajo -> vY;
		abajo->vY = arriba -> vY;
		arriba->vY = aux;
		choque = true;
	}	

	return choque;
}

float Bola::calcDistancia(Bola otra){
	float distancia;
	
	distancia = sqrtf((powf(otra.x - x,2))+(powf(otra.y - y,2)));
	
	return distancia;
}











