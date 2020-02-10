#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QAction>
#include <BolaYWidget.h>
#include <iostream>
#include <QSystemTrayIcon>
#include <stdio.h>
#include <QPoint>
#include <QVector>
#include "DControlBolas.h"
class MainWindow : public QMainWindow {
Q_OBJECT
public:
        MainWindow(QWidget * parent = 0, Qt::WindowFlags flags = 0);
	void paintEvent(QPaintEvent * );
	void keyPressEvent(QKeyEvent * e);
	void mouseDoubleClickEvent(QMouseEvent * e);
	void dropEvent(QDropEvent * event);
	void dragEnterEvent( QDragEnterEvent * event );
	void mousePressEvent(QMouseEvent *e);
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
	int vidasJugador;
	int bolasTotales;
	QPoint puntoEntrada;
	QPoint puntoSoltar;
	QPoint startPos;
	
	QImage imagenCorazon;
	QSystemTrayIcon * trayIcon;
	QMouseEvent * eventoInicial;
	QAction * accionDialogo;
	QAction * accionExamen;
	QAction * accionTabla;
	QAction * accionControlBolas;
	QAction * accionDChart;
	QAction * accionPieChart;
	QMenu * menuArchivo;
	QMenu * menuDialogos;
	BolaYWidget * jugador;
	QVector<BolaYWidget *> bolas;
	QVector<PowerUp*> powerUps;
	DControlBolas * dControlBolas;
	void movimientoChoqueBolas( QVector<BolaYWidget*> & );
        
public slots:

	void slotRepintar();
	void slotDialogo();
	void slotExamen();
	void slotInfoTabla();
	void slotDControlBolas();
	void slotDChartColisiones();
	void slotPieChart();
};

#endif 
