#ifndef BOLA_H
#define BOLA_H

#include <QPainter>
#include "PowerUp.h"
#include <QVector>
class Bola{

public:
        Bola(bool, float , float , float , float, float );
        Bola(bool, float , float , float , float, float, QImage );
        Bola(bool, float , float , float , float, float, QColor );
	void pintarBola(QPainter &);
	void pintarVida(QPainter &);
	void mover(float, float);
	bool chocar(Bola &);
	float distanciaPU(float,float);
	float calcDistancia(Bola );
	static const int vidaInicial = 100;

	int vida;
	static int contId;
	int id;
	int colisiones;
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
	Bola * pare;
	QVector<Bola*> hijas;
	
	
private:

};

#endif 
