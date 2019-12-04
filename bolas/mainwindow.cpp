#include "mainwindow.h"
#include "InfoDialog.h"
#include <QPainter>
#include <QTimer>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <QVector>
#include "bola.h"
#include <QDebug>
#include <QAction>
#include <QMenuBar>
MainWindow::MainWindow(QWidget * parent ,Qt::WindowFlags flags ) : QMainWindow(parent,flags) {

	QTimer * temporizador = new QTimer();
	/*programar el temporizador*/
	temporizador->setInterval(10);
	temporizador->setSingleShot(false);
	temporizador->start();
	/*arrancar el temporizador*/
	
	crearQActions();
	crearMenus();
	connect(temporizador,SIGNAL(timeout()),this, SLOT(slotRepintar()));
	
	resize(800,600);
	
	
	
	
	for(int i = 0; i<5; i++){
		velX = 3;
		velY = 3;
		posX = generador.bounded(0,800);
		posY = generador.bounded(0,600);
		radio = rand()%80;
		bolas.append(new Bola(false,posX,posY,velX,velY,radio));
	}
	
    	jugador = new Bola(true,posX,posY,velX,velY,80);
    
}

void MainWindow::crearQActions(){
	accionDialogo = new QAction("Información",this);
	connect(accionDialogo, SIGNAL(triggered()),this, SLOT(slotDialogo()));
}

void MainWindow::crearMenus(){

	menuArchivo = menuBar()->addMenu("Archivo");
        menuArchivo ->addAction(accionDialogo);
        this->setContextMenuPolicy(Qt::ActionsContextMenu);
        this->addAction(accionDialogo);
	
	
	
}

void MainWindow::paintEvent(QPaintEvent *e){
	
	
	QPainter pintor(this);
	
	jugador->pintarBola(pintor);
	
	for(int i = 0; i<bolas.size(); i++){
		bolas[i]->pintarBola(pintor);
		bolas[i]->mover(height(),width());
		
		for(int j = 0; j<bolas.size(); j++){
			bolas[i]->chocar(*bolas[j]);
		}
	}
	
	
	
	
    		

}


void MainWindow::slotDialogo(void){
	
	int numBolas = bolas.size();
	int alto = height();
	int ancho = width();
	
	InfoDialog * dialogo = new InfoDialog(numBolas,alto,ancho);
	
	dialogo->show();
}


void MainWindow::slotRepintar(void){
	
	update();	
	
}



