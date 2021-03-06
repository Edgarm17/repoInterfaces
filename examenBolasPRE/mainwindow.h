#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QAction>
#include <bola.h>
#include <iostream>
#include <QSystemTrayIcon>
#include <stdio.h>
#include <QPoint>
#include <QVector>
#include "DExamenTab.h"
#include "DTablaPRE.h"
class MainWindow : public QMainWindow {
Q_OBJECT
public:
        MainWindow(QWidget * parent = 0, Qt::WindowFlags flags = 0);

	//ATRIBUTOS VARIOS
	Bola * jugador;
	QVector<Bola *> bolas;
	QVector<PowerUp*> powerUps;
	int vidasJugador;
	int bolasTotales;
	bool moverConRaton;
	QImage imagenCorazon;
	QSystemTrayIcon * trayIcon;
	
	//POSICION, VELOCIDAD Y RADIO DE LAS BOLAS
        float posX;
	float posY;
	float velX;
	float velY;
	float radio;

	//POSICIONES Y PUNTOS RATON EN LA PANTALLA
	float posRatonX;
	float posRatonY;
	QPoint puntoEntrada;
	QPoint puntoSoltar;
	QPoint startPos;

	//MÉTODOS
	void crearQActions();
	void crearMenus();
	void performDrag();
	void movimientoChoqueBolas( QVector<Bola*> & );
	void moverJugadorRaton(void);
	
	//DIÁLOGOS
	DExamenTab * dialogTab;
	DTablaPre * dialogoTabla;

	//QACTIONS
	QAction * accionDExamenTab;
	QAction * accionDialogSegon;

	//MENUS
	QMenu * menuArchivo;
	QMenu * menuDialogos;
	

	//EVENTOS
	QMouseEvent * eventoInicial;
	void dropEvent(QDropEvent * event);
	void dragEnterEvent( QDragEnterEvent * event );
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void paintEvent(QPaintEvent * );
	void keyPressEvent(QKeyEvent * e);
	void mouseDoubleClickEvent(QMouseEvent * e);
	
        
public slots:

	void slotRepintar();
	void slotDExamenTab();
	void slotDialogoTabla();
	void slotMoverConRaton();

};

#endif 
