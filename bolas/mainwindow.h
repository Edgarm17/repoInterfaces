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
#include <QRandomGenerator>
class MainWindow : public QMainWindow {
Q_OBJECT
public:
        MainWindow(QWidget * parent = 0, Qt::WindowFlags flags = 0);
	void paintEvent(QPaintEvent * );
	void keyPressEvent(QKeyEvent * e);
	void mouseDoubleClickEvent(QMouseEvent * e);
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
	int vidasJugador;
	
	QMouseEvent * eventoInicial;
	QAction * accionDialogo;
	QAction * accionExamen;
	QMenu * menuArchivo;
	QMenu * menuDialogos;
	QRandomGenerator generador;
	Bola * jugador;
	QVector<Bola*> bolas;
	
        
public slots:

	void slotRepintar();
	void slotDialogo();
	void slotExamen();
};

#endif 
