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
	
	
	
	bolasTotales = 0;

	QTimer * temporizador = new QTimer();
	/*programar el temporizador*/
	temporizador->setInterval(10);
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

	

	
    	
    	setMouseTracking(true);
	setAcceptDrops(true);

    	crearQActions();
	crearMenus();


	
}

void MainWindow::crearQActions(){
	
	accionDialogoUno = new QAction("Dialogo Uno",this);
	//connect(acionDialogoUno, SIGNAL(triggered()),this, SLOT());


}

void MainWindow::crearMenus(){


	menuExamen = menuBar()->addMenu("Examen");
	menuExamen->addAction(accionDialogoUno);

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
				vector[j]->colisiones++;
				vector[i]->vida-=10;
				vector[i]->colisiones++;
				
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























