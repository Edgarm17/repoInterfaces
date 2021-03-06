#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QAction>
#include <bola.h>
#include <iostream>
#include <stdio.h>
#include <QVector>
#include <QPoint>
#include <QSystemTrayIcon>
#include "PowerUp.h"
class MainWindow : public QMainWindow {
Q_OBJECT
public:
        MainWindow(QWidget * parent = 0, Qt::WindowFlags flags = 0);
	void paintEvent(QPaintEvent * );
	void keyPressEvent(QKeyEvent * e);
	void mouseDoubleClickEvent(QMouseEvent * e);
	void mousePressEvent(QMouseEvent *e);
	void dropEvent(QDropEvent * event);
	void dragEnterEvent( QDragEnterEvent * event );
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void moverJugadorRaton(void);

private:
        float posX;
	float posY;
	float velX;
	float velY;
	float radio;
	float posRatonX;
	float posRatonY;
	void crearQActions();
	void crearMenus();
	void performDrag();
	void crearPowerUps();
	void movimientoChoqueBolas(QVector<Bola*> &);
	int vidasJugador;
	int cont;
	int bolasTotales;
	QPoint puntoEntrada;
	QPoint puntoSoltar;
	QPoint startPos;
	QImage imagenCorazon;
	QTimer * timerPU;
	
	QMouseEvent * eventoInicial;
	QAction * accionDialogo;
	QAction * accionExamen;
	QAction * accionTabla;
	QAction * accionControlBolas;
	QAction * accionDChart;
	QAction * accionDTree;
	QMenu * menuArchivo;
	QMenu * menuDialogos;
	Bola * jugador;
	QVector<Bola*> bolas;
	QVector<PowerUp*> powerUps;
	QSystemTrayIcon * trayIcon;
	
        
public slots:

	void slotRepintar();
	void slotDialogo();
	void slotExamen();
	void slotInfoTabla();
	void slotDControlBolas();
	void slotDChartColisiones();
	void slotDTreeView();
	
signals:

	//jugadorChoqued(int, int);

};

#endif 
