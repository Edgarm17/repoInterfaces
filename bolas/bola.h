#ifndef BOLA_H
#define BOLA_H

#include <QPainter>

class Bola{

public:
        Bola(bool, float , float , float , float, float );
        Bola(bool, float , float , float , float, float, QColor );
	void pintarBola(QPainter &);
	void mover(float, float);
	void chocar(Bola &);
	float calcDistancia(Bola );

private:
        float x;
	float y;
	float vX;
	float vY;
	float radio;
	bool jugador;
	QColor color;


};

#endif 
