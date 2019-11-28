#include "mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <math.h>
MainWindow::MainWindow(QWidget * parent ,Qt::WindowFlags flags ) : QMainWindow(parent,flags) {

	QTimer * temporizador = new QTimer();
	/*programar el temporizador*/
	temporizador->setInterval(10);
	temporizador->setSingleShot(false);
	temporizador->start();
	/*arrancar el temporizador*/
	
	connect(temporizador,SIGNAL(timeout()),this, SLOT(slotRepintar()));

	resize(800,600);
    	posX = posY = 100;
    	velX = 10;
    	velY = 10;
    
}



void MainWindow::paintEvent(QPaintEvent *e){
	
	QPainter pintor(this);
    	pintor.drawEllipse(posX,posY,20,20);
    	
    	
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

void MainWindow::slotRepintar(void){
	
	update();	
	
}



