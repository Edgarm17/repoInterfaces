#include "mainwindow.h"
#include "InfoDialog.h"
#include <QPainter>
#include <QTimer>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <QVector>
#include "bola.h"
#include "DExamenDAM.h"
#include "DialogoTabla.h"
#include "DControlBolas.h"
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
		posX = rand()%800;
		posY = rand()%600;
		radio = 40;
		bolas.append(new Bola(false,posX,posY,velX,velY,radio));
	}
	
	posX = posY = 20;
	
    	jugador = new Bola(true,posX,posY,0.0,0.0,80);
    	
    	
    	setMouseTracking(true);
    	
}

void MainWindow::crearQActions(){
	accionDialogo = new QAction("Información",this);
	connect(accionDialogo, SIGNAL(triggered()),this, SLOT(slotDialogo()));
	
	accionExamen = new QAction("Examen",this);
	connect(accionExamen, SIGNAL(triggered()),this, SLOT(slotExamen()));
	
	accionTabla = new QAction("Tabla de información",this);
	connect(accionTabla, SIGNAL(triggered()),this, SLOT(slotInfoTabla()));
	
	accionControlBolas = new QAction("Control bolas",this);
	connect(accionControlBolas, SIGNAL(triggered()),this, SLOT(slotDControlBolas()));
}

void MainWindow::crearMenus(){

	menuArchivo = menuBar()->addMenu("Archivo");
	menuDialogos = menuBar()->addMenu("Dialogos");
        menuArchivo ->addAction(accionDialogo);
        menuDialogos->addAction(accionExamen);
        menuDialogos->addAction(accionTabla);
        menuDialogos->addAction(accionControlBolas);
        this->setContextMenuPolicy(Qt::ActionsContextMenu);
        this->addAction(accionDialogo);
	this->addAction(accionExamen);
	this->addAction(accionTabla);
	this->addAction(accionControlBolas);
	
	
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

void MainWindow::mousePressEvent(QMouseEvent * e){

	eventoInicial = new QMouseEvent(*e);	

}

void MainWindow::mouseReleaseEvent(QMouseEvent *e){
	
	if(eventoInicial == NULL)return;
	
	QMouseEvent * eventoFinal = e;
	
	if(eventoInicial->x()+eventoInicial->y() == eventoFinal->x()+eventoFinal->y())return;
	
	float radio = 50;
	float pInicialX = eventoInicial->x() - radio/2;
	float pInicialY = eventoInicial->y() - radio/2;
	float pFinalX = eventoFinal->x();
	float pFinalY = eventoFinal->y();
	float vX = (eventoFinal->x() - eventoInicial->x()) / 50.2;
	float vY = (eventoFinal->y() - eventoInicial->y()) / 50.3;
	
	
	Bola * newBola = new Bola(false,pInicialX,pInicialY,vX,vY,radio);
	
	bolas.append(newBola);
	
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent * e){
	float mouseX, mouseY;
	float radio = 50;
	mouseX = e->x()-radio;
	mouseY = e->y()-radio;
	float velX = (rand()%100-50)/50.1;
	float velY = (rand()%100-50)/50.1;
	
	Bola * newBola = new Bola(false,(float)mouseX,(float)mouseY,velX,velY,radio);
	bolas.append(newBola);
}

void MainWindow::mouseMoveEvent(QMouseEvent * e){

	

}

void MainWindow::moverJugadorRaton(void){

	posRatonX = QWidget::mapFromGlobal(QCursor::pos()).x();
	posRatonY = QWidget::mapFromGlobal(QCursor::pos()).y();
	
	float incVelx = (posRatonX - jugador->x);
	incVelx = pow((incVelx * 0.0012),3);
	float incVely = (posRatonY - jugador->y);
	incVely = pow((incVely * 0.0012),3);
	
	jugador->vX += incVelx;
	jugador->vY += incVely;
	
	jugador->vX = jugador->vX * 0.99;
	jugador->vY = jugador->vY * 0.99;
	
	
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
	
	moverJugadorRaton();
		
	
}

void MainWindow::slotExamen(void){
	DExamenDAM * dialogo = new DExamenDAM(bolas);
	dialogo->show();
}

void MainWindow::slotInfoTabla(void){

	DialogoTabla * dialogo = new DialogoTabla(&bolas);
	dialogo->show();	


}

void MainWindow::slotDControlBolas(void){

	DControlBolas * dialogo = new DControlBolas(&bolas);
	dialogo->show();	


}













