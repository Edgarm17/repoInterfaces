#include "mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <math.h>
#include <QVector>
#include "bola.h"
#include <QDebug>
#include <QAction>
#include <QMenuBar>

MainWindow::MainWindow(QWidget * parent ,Qt::WindowFlags flags ) : QMainWindow(parent,flags) {

	
	resize(800,600);
	
	intervaloRepintar = 10;
	
	bolasTotales = 0;

	temporizador = new QTimer();
	/*programar el temporizador*/
	temporizador->setInterval(intervaloRepintar);
	temporizador->setSingleShot(false);
	temporizador->start();
	/*arrancar el temporizador*/
	connect(temporizador,SIGNAL(timeout()),this, SLOT(slotRepintar()));
	

	/*CREAR BOLAS*/
	for(int i = 0; i<5; i++){
		velX = 1;
		velY = 1;
		posX = rand()%800;
		posY = rand()%600;
		radio = 60;
		bolas.append(new Bola(false,posX,posY,velX,velY,radio));
	}

	
	barraEstadoFIN = new QStatusBar();
	QLabel * label = new QLabel("Ventana a cerrar");
	comboBarraFIN = new QComboBox();
	botonBarraFIN = new QPushButton();
	sliderBarraFIN = new QSlider();
	sliderBarraFIN->setOrientation(Qt::Horizontal);
	sliderBarraFIN->setRange(1,20);
	sliderBarraFIN->setInvertedAppearance(true);
	sliderBarraFIN->setInvertedControls(true);
	
	connect(sliderBarraFIN,SIGNAL(sliderMoved(int)),this,SLOT(slotVelocidadBolas(int)));
	
	barraEstadoFIN->addWidget(label);
	barraEstadoFIN->addWidget(comboBarraFIN);
	barraEstadoFIN->addWidget(botonBarraFIN);
	barraEstadoFIN->addWidget(sliderBarraFIN);
	
	setStatusBar(barraEstadoFIN);
	
    	
    	setMouseTracking(true);
	setAcceptDrops(true);

    	crearQActions();
	crearMenus();


	
}

void MainWindow::slotVelocidadBolas(int value){
	temporizador->setInterval(value);
}

void MainWindow::crearQActions(){
	
	accionWidgetFIN = new QAction("Widget info",this);
	connect(accionWidgetFIN, SIGNAL(triggered()),this, SLOT(slotWidgetFIN()));


}

void MainWindow::crearMenus(){


	menuExamen = menuBar()->addMenu("Examen");
	menuExamen->addAction(accionWidgetFIN);

}



void MainWindow::paintEvent(QPaintEvent *e){
	
	
	QPainter pintor(this);
	
	/*PINTAR BOLAS*/
	for(int i = 0; i<bolas.size(); i++){
		//bolas[i]->mostrarImagen = false;
		bolas[i]->pintarBola(pintor);
	
	}

	
	
	
    		

}



void MainWindow::movimientoChoqueBolas( QVector<Bola*> & vector){
	for(int i=0; i<vector.size(); i++){
		vector[i]->mover(height(),width());
		
		for(int j = 0; j<vector.size(); j++){
			if(vector[i]->chocar(*vector[j])){
				vector[j]->vida-=10;
				vector[j]->colisionesBolas++;
				vector[i]->vida-=10;
				vector[i]->colisionesBolas++;
				
			}
		}
		
	}
}


void MainWindow::slotRepintar(void){
	
	update();
	
	/*ELIMINAR BOLAS MUERTAS*/
	
	for(int i = 0; i<bolas.size(); i++){
		if(bolas[i]->vida < 0){
			//bolas.erase(bolas.begin()+i);
			
			bolas[i]->vida = 100; 	//REINICIAR VIDA BOLAS MUERTAS
		}
	}
	

	
	/*MOVER BOLAS Y CONTROLAR CHOQUE*/
	
	movimientoChoqueBolas(bolas);
	
	
}



void MainWindow::slotWidgetFIN(){

	widgetFIN = new WidgetInfo(bolas.at(0));
	widgetFIN->show();
	widgetFIN->setAttribute(Qt::WA_DeleteOnClose);
	listaWidgetsFIN.append(widgetFIN);
	
	connect(widgetFIN, SIGNAL(botonNuevoWidgetClicked(int,bool)),this,SLOT(slotNuevoWidgetFIN(int,bool)));
}

void MainWindow::slotNuevoWidgetFIN(int numBola,bool nextOPrev){
	
	
	if(nextOPrev){
		if(numBola == 4)return;
		WidgetInfo * widgetNext = new WidgetInfo(bolas.at(numBola+1));
		widgetNext->setAttribute(Qt::WA_DeleteOnClose);
		widgetNext->show();
		connect(widgetNext, SIGNAL(botonNuevoWidgetClicked(int,bool)),this,SLOT(slotNuevoWidgetFIN(int,bool)));
		listaWidgetsFIN.append(widgetNext);
		

	
		
	}else{
		if(numBola == 0)return;
		WidgetInfo * widgetPrev = new WidgetInfo(bolas.at(numBola-1));
		widgetPrev->show();
		widgetPrev->setAttribute(Qt::WA_DeleteOnClose);
		connect(widgetPrev, SIGNAL(botonNuevoWidgetClicked(int,bool)),this,SLOT(slotNuevoWidgetFIN(int,bool)));
		listaWidgetsFIN.append(widgetPrev);
		
		
	}
	

}
























