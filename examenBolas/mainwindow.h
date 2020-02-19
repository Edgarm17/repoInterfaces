#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QAction>
#include <bola.h>
#include <iostream>
#include <stdio.h>
#include <QPoint>
#include <QVector>
#include "DialogoUno.h"
class MainWindow : public QMainWindow {
Q_OBJECT
public:
        MainWindow(QWidget * parent = 0, Qt::WindowFlags flags = 0);

	//ATRIBUTOS VARIOS

	QVector<Bola *> bolas;
	int bolasTotales;
	
	//POSICION, VELOCIDAD Y RADIO DE LAS BOLAS
        float posX;
	float posY;
	float velX;
	float velY;
	float radio;

	//MÉTODOS
	void crearQActions();
	void crearMenus();
	void movimientoChoqueBolas( QVector<Bola*> & );
	
	//DIÁLOGOS
	DialogoUno * dialog;

	//QACTIONS
	QAction * accionDialogoUno;

	//MENUS
	QMenu * menuExamen;
	

	//EVENTOS
	QMouseEvent * eventoInicial;
	void paintEvent(QPaintEvent * );

	
        
public slots:

	void slotRepintar();

};

#endif 
