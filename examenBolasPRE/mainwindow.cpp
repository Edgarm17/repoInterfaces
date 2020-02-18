#include "mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <math.h>
#include <QVector>
#include "bola.h"
#include <QDebug>
#include <QAction>
#include <QMenuBar>
#include <QMimeData>
#include <QMessageBox>
#include <QDrag>
#include <QShortcut>
#include "DialogInfo.h"
MainWindow::MainWindow(QWidget * parent ,Qt::WindowFlags flags ) : QMainWindow(parent,flags) {
	
	//setCursor(QCursor(QPixmap("./img/cursor.png")));
	imagenCorazon = QImage("./img/heartPU.png");
	vidasJugador = 5;
	moverConRaton = false;
	
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

	
	
	posX = posY = 20;
	
    	jugador = new Bola(true,posX,posY,0.0,0.0,60);
	bolasTotales++;

	
    	
    	setMouseTracking(true);
	setAcceptDrops(true);

	

	new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_A), this, SLOT(slotMoverConRaton()));
    	crearQActions();
	crearMenus();

	if(QSystemTrayIcon::isSystemTrayAvailable() == true ) {
	    	
	    		QIcon icon = QIcon("./img/bolasIcon.png");
	    		trayIcon = new QSystemTrayIcon(this);
	    		trayIcon->setContextMenu(menuDialogos);
	    		trayIcon->setIcon(icon);
	    		trayIcon->show();
	    		
	    	}

	
}

void MainWindow::crearQActions(){
	
	accionDExamenTab = new QAction("Dialogo TabWidget",this);
	connect(accionDExamenTab, SIGNAL(triggered()),this, SLOT(slotDExamenTab()));

	accionDialogSegon = new QAction("Dialogo TableView",this);
	connect(accionDialogSegon, SIGNAL(triggered()),this, SLOT(slotDialogoTabla()));
	
	

}

void MainWindow::crearMenus(){
	menuArchivo = menuBar()->addMenu("Archivo");
	menuDialogos = menuBar()->addMenu("Dialogos");


        menuDialogos ->addAction(accionDExamenTab);
        menuDialogos ->addAction(accionDialogSegon);

        this->setContextMenuPolicy(Qt::ActionsContextMenu);
        this->addAction(accionDExamenTab);
	this->addAction(accionDialogSegon);
	
	
}

void MainWindow::slotDExamenTab(void){
	
	dialogTab = new DExamenTab(&bolas);
	dialogTab->show();
	
	
}


void MainWindow::slotDialogoTabla(void){
	
	dialogoTabla = new DTablaPre(&bolas);
	dialogoTabla->show();
}

void MainWindow::slotMoverConRaton(void){
	
	

	if(moverConRaton){
		qDebug() << "Movimiento con raton desactivado" ;
		moverConRaton = false;
	}else{
		qDebug() << "Movimiento con raton activado" ;
		moverConRaton = true;
	}

}


void MainWindow::paintEvent(QPaintEvent *e){
	
	
	QPainter pintor(this);
	
	/*PINTAR JUGADOR*/
	jugador->pintarBola(pintor);
	
	/*PINTAR BOLAS*/
	for(int i = 0; i<bolas.size(); i++){
		//bolas[i]->mostrarImagen = false;
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

	QPoint p = e->pos();
		
	for(int i = 0; i<bolas.size(); i++){
		if(bolas.at(i)->distanciaPU(p.x(),p.y()) <= bolas.at(i)->radio/2){
			qDebug() << "Has tocado la bola " << bolas.at(i)->id;
			DialogInfo * dialog = new DialogInfo(bolas.at(i));
			dialog->show();
		}
	}
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
	
	if(moverConRaton){
		jugador->vX += incVelx;
		jugador->vY += incVely;
	
		jugador->vX = jugador->vX * 0.99;
		jugador->vY = jugador->vY * 0.99;
	}
	
	
}

void MainWindow::movimientoChoqueBolas( QVector<Bola*> & vector){
	for(int i=0; i<vector.size(); i++){
		vector[i]->mover(height(),width());
		
		
		
		//pintor.drawText(posX+15,posY+15, QString::number(numBola);
		
		
		for(int j = 0; j<vector.size(); j++){
			if(vector[i]->chocar(vector[j])){
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
					Bola * nuevaBola = new Bola(false,posX,posY,3,3,radio);
					nuevaBola->mostrarImagen = false;
					nuevaBola->pare = vector[i];
					vector[i]->hijas.append(nuevaBola);
					bolas.append(nuevaBola);
					bolasTotales++;
				}
				*/
			}
		}
		if(jugador->chocar(bolas[i])){
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
			if(bolas[i]->distanciaPU(powerUps[j]->posX+(powerUps[j]->width/2),powerUps[j]->posY+(powerUps[j]->height/2)) < bolas[i]->radio){
				powerUps.erase(powerUps.begin()+j);
				if(bolas[i]->vida <= 800){
				
					bolas[i]->vida += 20;
				}
			}
			
		}
		
	}
	
	for(int j = 0; j<powerUps.size(); j++){
	
		if(jugador->distanciaPU(powerUps[j]->posX+(powerUps[j]->width/2),powerUps[j]->posY+(powerUps[j]->height/2)) < jugador->radio){
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
      	
      	Bola * nuevaBola = new Bola(false,puntoSoltar.x(),puntoSoltar.y(),vX,vY,
      	radio,QImage(text));
      	bolas.append(nuevaBola);
}

void MainWindow::dragEnterEvent ( QDragEnterEvent * event ) {
    event->acceptProposedAction();
    puntoEntrada = event->pos();
    qDebug()<<"Punto entrada: " << puntoEntrada.x() << endl;
    
}





















