#ifndef BOLA_H
#define BOLA_H

#include <QPainter>
#include <QVector>
class Bola {

public:
        Bola(bool, float , float , float , float, float );
        Bola(bool, float , float , float , float, float, QImage );
        Bola(bool, float , float , float , float, float, QColor );
	void pintarBola(QPainter &);
	void pintarVida(QPainter &);
	void mover(float, float);
	void parar();
	bool chocar(Bola &);
	float distanciaPU(float,float);
	float calcDistancia(Bola );
	static const int vidaInicial = 100;

	int vida;
	static int contId;
	int id;
	int colisionesBolas;
	int colisionesPared;
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



	
	
public slots:



};

#endif 
