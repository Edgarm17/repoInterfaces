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
#include <QList>
#include "WidgetInfo.h"
#include <QStatusBar>
#include <QPushButton>
#include <QSlider>
#include <QComboBox>

class MainWindow : public QMainWindow {
Q_OBJECT
public:
        MainWindow(QWidget * parent = 0, Qt::WindowFlags flags = 0);

	//ATRIBUTOS VARIOS

	QVector<Bola *> bolas;
	int bolasTotales;
	int intervaloRepintar;
	
	QTimer * temporizador;
	
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
	
	//BARRA DE ESTADO
	
	QStatusBar * barraEstadoFIN;
	
	//WIDGETS BARRA
	QComboBox * comboBarraFIN;
	QPushButton * botonBarraFIN;
	QSlider * sliderBarraFIN;
	
	//WIDGETS
	
	WidgetInfo * widgetFIN;
	QList<WidgetInfo*> listaWidgetsFIN;

	//QACTIONS
	QAction * accionWidgetFIN;

	//MENUS
	QMenu * menuExamen;
	

	//EVENTOS
	QMouseEvent * eventoInicial;
	void paintEvent(QPaintEvent * );

	
        
public slots:

	void slotWidgetFIN();
	void slotNuevoWidgetFIN(int,bool);
	void slotVelocidadBolas(int);
	void slotRepintar();
	

};

#endif 
