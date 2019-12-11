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
	vidasJugador = 5;
	
	
	
	for(int i = 0; i<5; i++){
		velX = 3;
		velY = 3;
		posX = generador.bounded(0,800);
		posY = generador.bounded(0,600);
		radio = rand()%80;
		bolas.append(new Bola(false,posX,posY,velX,velY,radio));
	}
	
    	jugador = new Bola(true,posX,posY,0.0,0.0,80);
    	
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
	jugador->mover(height(),width());
	
	for(int i = 0; i<bolas.size(); i++){
		bolas[i]->pintarBola(pintor);
		bolas[i]->mover(height(),width());
		
		for(int j = 0; j<bolas.size(); j++){
			if(bolas[i]->chocar(*bolas[j])){
				bolas[j]->vida-=10;
				bolas[i]->vida-=10;
			}
		}
		if(jugador->chocar(*bolas[i])){
			jugador->vida-=10;
			bolas[i]->vida-=10;
		}
	}
	
	
	
	for(int i = 0; i<bolas.size(); i++){
		int ancho = bolas[i]->radio;
		float anchoVerde = (((float)bolas[i]->vida) / 
		bolas[i]->vidaInicial)*(float)ancho;
		
		float anchoRojo = (ancho - (float)anchoVerde);
		pintor.setBrush(Qt::green);
		pintor.drawRect(bolas[i]->x,bolas[i]->y,anchoVerde,3);
		pintor.setBrush(Qt::red);
		pintor.drawRect(bolas[i]->x + anchoVerde,bolas[i]->y,anchoRojo,3);
	}
	
		int ancho = jugador->radio;
		float anchoVerde = (((float)jugador->vida) / jugador->vidaInicial)*(float)ancho;
		float anchoRojo = (ancho - (float)anchoVerde);
		pintor.setBrush(Qt::green);
		pintor.drawRect(jugador->x,jugador->y,anchoVerde,3);
		pintor.setBrush(Qt::red);
		pintor.drawRect(jugador->x + anchoVerde,jugador->y,anchoRojo,3);
		
	
	
	
    		

}

void MainWindow::keyPressEvent(QKeyEvent * e){
	
	int tecla = e->key();
	
	switch(tecla){
		case Qt::Key_Left: //Izquierda
			jugador->vX-=1;
			break;
		case Qt::Key_Right://Derecha
			jugador->vX+=1;
			break;
		case Qt::Key_Up://Arriba
			jugador->vY-=1;
			break;
		case Qt::Key_Down://Abajo
			jugador->vY+=1;
			break;
	
	}
	
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent * e){
	float mouseX, mouseY;
	float radio = 50;
	mouseX = e->x()-radio;
	mouseY = e->y()-radio;
	
	
	Bola * newBola = new Bola(false,(float)mouseX,(float)mouseY,(float)3.0,(float)3.0,radio);
	bolas.append(newBola);
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
	
	for(int i = 0; i<bolas.size(); i++){
		if(bolas[i]->vida < 0){
			bolas.erase(bolas.begin()+i);
		}
	}
	
	if(jugador->vida < 0){
		jugador->vida = 100;
		
	}
	
	
	
		
	
}



