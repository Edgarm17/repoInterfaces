#include "DialogInfo.h"
#include "bola.h"
#include <QVector>
#include <QDebug>
#include <QTimer>
DialogInfo::DialogInfo(Bola * b,QWidget * parent) : QDialog(parent){

	setupUi(this);

	QTimer * temporizador = new QTimer();
    	temporizador->setSingleShot(false);
    	temporizador->setInterval(500); 
    	
    	
    	connect(temporizador,SIGNAL(timeout()),this,
    		SLOT(slotTemporizador()));
    	temporizador->start();
	
	this->bola = b;
	setWindowTitle(QString("Bola ")+QString::number(b->Bola::id));
	
	lbPosX->setText(lbPosX->text()+"   "+QString::number(b->Bola::x));
	lbPosY->setText(lbPosY->text()+"   "+QString::number(b->Bola::y));
	lbVel->setText(lbVel->text()+"   "+QString::number(b->Bola::vX));
	lbId->setText(lbId->text()+"   "+QString::number(b->Bola::id));
	
}


void DialogInfo::slotTemporizador(){
	lbPosX->setText("Posicion X:   "+QString::number(bola->Bola::x));
	lbPosY->setText("Posicion Y:   "+QString::number(bola->Bola::y));
	lbVel->setText("Velocidad:   "+QString::number(bola->Bola::vX));
	lbId->setText("Id:   "+QString::number(bola->Bola::id));
}
