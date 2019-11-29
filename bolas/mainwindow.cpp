#include "mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <QVector>
MainWindow::MainWindow(QWidget * parent ,Qt::WindowFlags flags ) : QMainWindow(parent,flags) {

	QTimer * temporizador = new QTimer();
	/*programar el temporizador*/
	temporizador->setInterval(10);
	temporizador->setSingleShot(false);
	temporizador->start();
	/*arrancar el temporizador*/
	
	
	connect(temporizador,SIGNAL(timeout()),this, SLOT(slotRepintar()));
	cargarBolas(bolas);
	resize(800,600);
    	posX = posY = 100;
    	velX = 10;
    	velY = 10;
    
}



void MainWindow::paintEvent(QPaintEvent *e){
	
	QPainter pintor(this);
    	
	Bola * bola = new Bola(posX,posY,velX,velY);
	bola->pintarBola(pintor);	

    	

	/*Rebotes izquierda y derecha*/
    	
    	if(posX > 780){
    		velX = -fabs(velX);
    	}
    	
    	if(posX <= 0 ){
    		velX = fabs(velX);
    	}
    	
    	posX = posX + velX;
    	
    	
    	/*Rebotes arriba y abajo*/
    	
    	if(posY > 580){
    		velY = -fabs(velY);
    	}
    	
    	if(posY <= 0 ){
    		velY = fabs(velY);
    	}
    	
    	posY = posY + velY;
    	
    	
    	
}

void MainWindow::cargarBolas(QVector<Bola*> bolas){
	
	for(int i = 0; i<5 ; i++){
		bolas.push_back(new Bola(50*i,50*i,10,10));
	}

}

void MainWindow::slotRepintar(void){
	
	update();	
	
}



