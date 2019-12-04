#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
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
	

private:
        float posX;
	float posY;
	float velX;
	float velY;
	float radio;
	void crearQActions();
	void crearMenus();
	
	QAction * accionDialogo;
	QMenu * menuArchivo;
	QRandomGenerator generador;
	Bola * jugador;
	QVector<Bola*> bolas;
	
        
public slots:

	void slotRepintar();
	void slotDialogo();
	
};

#endif 
