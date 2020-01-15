#ifndef BOLA_H
#define BOLA_H

#include <QPainter>

class Bola{

public:
        Bola(bool, float , float , float , float, float );
        Bola(bool, float , float , float , float, float, QImage );
        Bola(bool, float , float , float , float, float, QColor );
	void pintarBola(QPainter &);
	void mover(float, float);
	bool chocar(Bola &);
	float calcDistancia(Bola );
	static const int vidaInicial = 1000;

	int vida;
        float x;
	float y;
	float vX;
	float vY;
	float radio;
	bool jugador;
	bool seleccionada;
	bool mostrarImagen;
	QColor color;
	QImage imagen;
	
private:

};

#endif 
