#include "mainwindow.h"
#include "InfoDialog.h"
#include <QPainter>
#include <QTimer>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <QVector>
#include "BolaYWidget.h"
#include "bola.h"
#include "DExamenDAM.h"
#include "DialogoTabla.h"
#include "DControlBolas.h"
#include "DChartColisiones.h"
#include "DPieChart.h"
#include <QDebug>
#include <QMimeData>
#include <QMessageBox>
#include <QAction>
#include <QDrag>
#include <QMenuBar>

MainWindow::MainWindow(QWidget * parent ,Qt::WindowFlags flags ) : QMainWindow(parent,flags) {

	imagenCorazon = QImage("./img/heartPU.png");
	vidasJugador = 5;
	crearQActions();
	crearMenus();
	resize(800,600);
	dialogProva = new DialogProva();
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
		velX = 3;
		velY = 3;
		posX = rand()%800;
		posY = rand()%600;
		radio = 60;
		bolas.append(new BolaYWidget(false,posX,posY,velX,velY,radio));
	}
	
	posX = posY = 20;
	
    	jugador = new BolaYWidget(true,posX,posY,0.0,0.0,80);
	bolasTotales++;
    	
    	dControlBolas = NULL ;
    	setMouseTracking(true);
	setAcceptDrops(true);

	if(QSystemTrayIcon::isSystemTrayAvailable() == true ) {
    	
    		QIcon icon = QIcon("./img/bolasIcon.png");
    		trayIcon = new QSystemTrayIcon(this);
    		trayIcon->setContextMenu(menuDialogos);
    		trayIcon->setIcon(icon);
    		trayIcon->show();
    		
    	}
    	
}

void MainWindow::crearQActions(){
	accionDialogo = new QAction("Información",this);
	connect(accionDialogo, SIGNAL(triggered()),this, SLOT(slotDialogo()));
	
	accionExamen = new QAction("Examen",this);
	connect(accionExamen, SIGNAL(triggered()),this, SLOT(slotExamen()));
	
	accionTabla = new QAction("Tabla de información (TableView)",this);
	connect(accionTabla, SIGNAL(triggered()),this, SLOT(slotInfoTabla()));
	
	accionControlBolas = new QAction("Control bolas (TabWidget)",this);
	connect(accionControlBolas, SIGNAL(triggered()),this, SLOT(slotDControlBolas()));

	accionDChart = new QAction("Gráfico barras ",this);
	connect(accionDChart, SIGNAL(triggered()),this, SLOT(slotDChartColisiones()));

	accionDProva = new QAction("Crear bola",this);
	connect(accionDProva, SIGNAL(triggered()),this, SLOT(slotDProva()));

	accionPieChart = new QAction("Gráfico pastel ",this);
	connect(accionPieChart, SIGNAL(triggered()),this, SLOT(slotPieChart()));
}

void MainWindow::crearMenus(){

	menuArchivo = menuBar()->addMenu("Archivo");
	menuDialogos = menuBar()->addMenu("Dialogos");
        menuArchivo ->addAction(accionDialogo);
        menuDialogos->addAction(accionExamen);
        menuDialogos->addAction(accionTabla);
        menuDialogos->addAction(accionControlBolas);
	menuDialogos->addAction(accionDChart);
	menuDialogos->addAction(accionPieChart);
	menuDialogos->addAction(accionDProva);
        this->setContextMenuPolicy(Qt::ActionsContextMenu);
        this->addAction(accionDialogo);
	this->addAction(accionExamen);
	this->addAction(accionTabla);
	this->addAction(accionControlBolas);
	this->addAction(accionDChart);
	
}

void MainWindow::paintEvent(QPaintEvent *e){
	
	
	QPainter pintor(this);
	
	/*PINTAR JUGADOR*/
	jugador->pintarBola(pintor);
	
	/*PINTAR BOLAS*/
	for(int i = 0; i<bolas.size(); i++){
		bolas[i]->pintarBola(pintor);
	
	}
	
	/*PINTAR VIDA BOLAS Y JUGADOR*/
	for(int i = 0; i<bolas.size(); i++){
		bolas[i]->pintarVida(pintor);
	}
	
	jugador->pintarVida(pintor);
	
	/*PINTAR POWERUPS*/
	for(int i = 0; i<powerUps.size(); i++){
		powerUps[i]->pintarPU(pintor);
	}
	
	
	
    		

}

void MainWindow::slotCrearBola(BolaYWidget * b){
	
	
	bolas.append(b);
	//dialogProva->close();

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
	if (e->button() == Qt::LeftButton)
        	startPos = e->pos();
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
	
	
	BolaYWidget * newBola = new BolaYWidget(false,pInicialX,pInicialY,vX,vY,radio);
	
	bolas.append(newBola);
	
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent * e){
	float mouseX, mouseY;
	float radio = 50;
	mouseX = e->x()-radio;
	mouseY = e->y()-radio;
	float velX = (rand()%100-50)/50.1;
	float velY = (rand()%100-50)/50.1;
	
	BolaYWidget * newBola = new BolaYWidget(false,(float)mouseX,(float)mouseY,velX,velY,radio);
	bolas.append(newBola);
}

void MainWindow::mouseMoveEvent(QMouseEvent * e){

	if (e->buttons() & Qt::LeftButton) {
        int distance = (e->pos() - startPos).manhattanLength();
        if (distance >= QApplication::startDragDistance())
            performDrag();
    	}

}

void MainWindow::performDrag(){
	QMimeData *mime = new QMimeData;
        //mime->setText(QString("Hola pepe"));

	QPixmap pixmap(size());
	this->render(&pixmap);
	mime->setImageData(pixmap);
	
        QDrag *drag = new QDrag(this);
        drag->setMimeData(mime);
        drag->setPixmap(QPixmap("./img/drag.png"));
        drag->setDragCursor(QPixmap("./img/arrastrarMano.png"),
        	Qt::MoveAction);
        drag->exec(Qt::MoveAction);

}

void MainWindow::moverJugadorRaton(void){

	posRatonX = QWidget::mapFromGlobal(QCursor::pos()).x();
	posRatonY = QWidget::mapFromGlobal(QCursor::pos()).y();
	
	float incVelx = (posRatonX - jugador->Bola::x);
	incVelx = pow((incVelx * 0.0012),3);
	float incVely = (posRatonY - jugador->Bola::y);
	incVely = pow((incVely * 0.0012),3);
	
	/*
	jugador->vX += incVelx;
	jugador->vY += incVely;
	
	jugador->vX = jugador->vX * 0.99;
	jugador->vY = jugador->vY * 0.99;
	*/
}

void MainWindow::slotDialogo(void){
	
	int numBolas = bolas.size();
	int alto = height();
	int ancho = width();
	
	InfoDialog * dialogo = new InfoDialog(numBolas,alto,ancho);
	
	dialogo->show();
}

void MainWindow::movimientoChoqueBolas( QVector<BolaYWidget*> & vector){
	for(int i=0; i<vector.size(); i++){
		vector[i]->mover(height(),width());
		
		
		
		//pintor.drawText(posX+15,posY+15, QString::number(numBola);
		
		
		for(int j = 0; j<vector.size(); j++){
			if(vector[i]->chocar(*vector[j])){
				vector[j]->vida-=10;
				vector[j]->colisiones++;
				vector[i]->vida-=10;
				vector[i]->colisiones++;
				/*
				if(rand()%100 < 20 && bolasTotales < 15){
					float posX = rand()%800;
					float posY = rand()%600;
					float radio = 0;
					
					if(vector[i]->radio - 10 > 10){
						radio = vector[i]->radio - 10;
					}else{
						radio = vector[i]->radio;
					}
					//qDebug()<< "Bola creada" << endl;
					BolaYWidget * nuevaBola = new BolaYWidget(false,posX,posY,3,3,radio);
					nuevaBola->mostrarImagen = false;
					nuevaBola->pare = vector[i];
					vector[i]->hijas.append(nuevaBola);
					bolas.append(nuevaBola);
					bolasTotales++;
				}
				*/
			}
		}
		if(jugador->chocar(*bolas[i])){
			jugador->vida-=10;
			bolas[i]->vida-=10;
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
	
	if(jugador->vida < 0){
		jugador->vida = 100;
		
	}
	
	/*MOVER AL JUGADOR CON EL RATON*/
	
	moverJugadorRaton();
	
	/*MOVER BOLAS Y CONTROLAR CHOQUE*/
	
	jugador->mover(height(),width());
	
	movimientoChoqueBolas(bolas);
	
	
	
	/*CONTROLAR CHOQUE CON POWERUPS*/
	
	for(int i=0; i<bolas.size(); i++){
		
		for(int j = 0; j<powerUps.size(); j++){
			if(bolas[i]->distanciaPU(powerUps[j]->posX,powerUps[j]->posY) < 40){
				powerUps.erase(powerUps.begin()+j);
				if(bolas[i]->vida <= 800){
				
					bolas[i]->vida += 20;
				}
			}
			
		}
		
	}
	
	for(int j = 0; j<powerUps.size(); j++){
	
		if(jugador->distanciaPU(powerUps[j]->posX,powerUps[j]->posY) < 40){
			powerUps.erase(powerUps.begin()+j);
			if(jugador->vida <= 800){
				
					jugador->vida += 20;
			}
		}
		
		//powerUps[j]->resizePU();	
	}
	
	
	
	int aleatorio = rand()%1000;
	
	int cont = 0;
	
	
	if(aleatorio < 2){

		powerUps.append(new PowerUp(rand()%750,rand()%550,imagenCorazon));
	}
		
	
}

void MainWindow::dropEvent(QDropEvent * event){

	if(!event->mimeData()->hasUrls()) return;
	
	QString text = (event->mimeData()->urls()).first().path();
	puntoSoltar = event->pos();
	qDebug()<<"Punto soltar: " << puntoSoltar.x() << endl;
	QMessageBox::warning(this, tr("Archivo arrastrado"),
                                tr("Has arrastrado el archivo:\n")+text,
                                QMessageBox::Save | QMessageBox::Discard
                                | QMessageBox::Cancel,
                                QMessageBox::Save);
                                
      	//QImage * newImagen = new QImage(text);
      	//for(int i = 0; i < bolas.size() ; i++){
      	//	bolas.at(i)->imagen = QImage(text);//*newImagen;
      	//}
      	
      	
	
	float vX = (puntoSoltar.x() - puntoEntrada.x()) / 50.2;
	float vY = (puntoSoltar.y() - puntoEntrada.y()) / 50.3;
	
	QImage img = QImage(text);      	
	
      	BolaYWidget * nuevaBola = new BolaYWidget(false,puntoSoltar.x(),puntoSoltar.y(),vX,vY,
      	radio,img);
      	bolas.append(nuevaBola);
}

void MainWindow::dragEnterEvent ( QDragEnterEvent * event ) {
    event->acceptProposedAction();
    puntoEntrada = event->pos();
    qDebug()<<"Punto entrada: " << puntoEntrada.x() << endl;
    
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
	
	if (dControlBolas == NULL ) 
		dControlBolas = new DControlBolas(&bolas);
	
	dControlBolas->show();	


}

void MainWindow::slotDChartColisiones(){
	DChartColisiones * dialogo = new DChartColisiones(bolas);
	dialogo->show();
}

void MainWindow::slotPieChart(){
	DPieChart * dialogo = new DPieChart(bolas);
	dialogo->show();
}

void MainWindow::slotDProva(){

	if (dialogProva == NULL ) 
		dialogProva = new DialogProva();
	dialogProva->show();
}













