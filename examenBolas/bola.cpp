#include "bola.h"
#include <math.h>
#include <QPainter>

int Bola::contId;

Bola::Bola(bool esJugador,float  posX, float  posY, float velX, float velY, float rad) 
{

	jugador = esJugador;
	seleccionada = false;
	colisionesBolas = 0;
	colisionesPared = 0;
	id = contId ++;
	x = posX;
	y = posY;
	vX = velX;
	vY = velY;
	radio = rad;
	vida = vidaInicial;
	color = QColor(rand()%256,rand()%256,rand()%256);
	imagen = QImage("./img/batman.png");
	imagen = imagen.scaled(Bola::radio,Bola::radio);
	mostrarImagen = false;
	
}

Bola::Bola(bool esJugador,float  posX, float  posY, float velX, float velY, float rad,
	QImage img)
{

	jugador = esJugador;
	seleccionada = false;
	colisionesBolas = 0;
	colisionesPared = 0;
	id = contId ++;
	x = posX;
	y = posY;
	vX = velX;
	vY = velY;
	radio = rad;
	vida = vidaInicial;
	color = QColor(rand()%256,rand()%256,rand()%256);
	imagen = img;
	imagen = imagen.scaled(Bola::radio,Bola::radio);
	mostrarImagen = true;
	
}

Bola::Bola(bool esJugador,float  posX, float  posY, float velX, float velY, float rad, QColor col) :
	 Bola(esJugador,posX,posY,velX,velY,radio)
{

	jugador = esJugador;
	seleccionada = false;
	colisionesBolas = 0;
	colisionesPared = 0;
	id = contId ++;
	x = posX;
	y = posY;
	vX = velX;
	vY = velY;
	radio = rad;
	vida = vidaInicial;
	color = col;
	imagen = QImage("./img/batman.png");
	imagen = imagen.scaled(Bola::radio, Bola::radio, Qt::IgnoreAspectRatio, Qt::FastTransformation);
	mostrarImagen = false;
	
}

void Bola::parar(){

	vX = 0;
	vY = 0;

}

void Bola::pintarBola(QPainter & pintor){

	if(jugador){
		pintor.drawImage(x,y,imagen);
		//pintor.setBrush((QBrush(Qt::black)));
		//pintor.setPen(Qt::red);
		//pintor.drawEllipse(x,y,radio,radio);
	}else{
		if(seleccionada){
			pintor.setBrush(Qt::FDiagPattern);
			pintor.drawEllipse(x,y,radio,radio);
			
		}else{
			
			if(mostrarImagen){
				pintor.drawImage(x,y,imagen);
				
			}else{
				pintor.setBrush(color);
				pintor.drawEllipse(x,y,radio,radio);
				pintor.drawText(x+radio+3,y+radio+3,QString::number(id));
			}
			
		}
		
		
	}

	
    	
    	
    	
}

void Bola::pintarVida(QPainter & pintor){

	
	float anchoVerde = (((float)vida) / vidaInicial)*(float)radio;
		
	float anchoRojo = (radio - (float)anchoVerde);
	pintor.setBrush(Qt::green);
	pintor.drawRect(x,y,anchoVerde,3);
	pintor.setBrush(Qt::red);
	pintor.drawRect(x + anchoVerde,y,anchoRojo,3);

}

void Bola::mover(float altura, float anchura){
	/*Rebotes izquierda y derecha*/
    	
    	if(x > anchura-radio){
    		vX = -fabs(vX);
    		colisionesPared++;
    	}
    	
    	if(x <= 0 ){
    		vX = fabs(vX);
    		colisionesPared++;
    	}
    	
    	x = x + vX;
    	
    	
    	/*Rebotes arriba y abajo*/
    	
    	if(y > altura-radio){
    		vY = -fabs(vY);
    		colisionesPared++;
    	}
    	
    	if(y <= 20 ){
    		vY = fabs(vY);
    		colisionesPared++;
    	}
    	
    	y = y + vY;
}

bool Bola::chocar(Bola & otra){
	
	bool choque = false;
	
	Bola * izquierda;
	Bola * derecha;
	Bola * arriba;
	Bola * abajo;
	

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

float Bola::distanciaPU(float posX, float posY){

	float distancia;
	
	distancia = sqrtf((powf(posX - (x+radio/2),2))+(powf(posY - (y+radio/2),2)));
	
	return distancia;
	
}

float Bola::calcDistancia(Bola otra){
	float distancia;
	
	distancia = sqrtf((powf(otra.x - x,2))+(powf(otra.y - y,2)));
	
	return distancia;
}













