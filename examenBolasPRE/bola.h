#ifndef BOLA_H
#define BOLA_H

#include <QPainter>
#include "PowerUp.h"
#include <QVector>
class Bola : public QObject{

	Q_OBJECT

public:
        Bola(bool, float , float , float , float, float, QObject * parent = nullptr);
        Bola(bool, float , float , float , float, float, QImage, QObject * parent = nullptr);
        Bola(bool, float , float , float , float, float, QColor, QObject * parent = nullptr);
	void pintarBola(QPainter &);
	void pintarVida(QPainter &);
	void mover(float, float);
	void parar();
	bool chocar(Bola *);
	float distanciaPU(float,float);
	float calcDistancia(Bola *);
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
	bool mostrarTexto;
	
	
public slots:

	void slotTextoBola(int);

};

#endif 
