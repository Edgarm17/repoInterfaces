#include "WidgetPRE.h"
#include "bola.h"
#include <QColor>
#include <QColorDialog>
#include <QFileDialog>
#include <QDebug>
#include <QPushButton>
#include "widgetPosicion.h"
WidgetPRE::WidgetPRE(Bola * bola,QWidget * parent) : QWidget(parent){

	setupUi(this);
	this->bola = bola;
	
	QHBoxLayout * layout = new QHBoxLayout();
	
	wid = new WidgetPosicion();

	

	layout->addWidget(wid);

	this->frame->setLayout(layout);

	connect(wid, SIGNAL(posicionCambiada(int,int)), bola, SLOT(slotPosicionTexto(int, int)));

	connect(chBoxMostrarNum, SIGNAL(stateChanged(int)),this->bola,  SLOT(slotTextoBola(int)));
  
	connect(rBImagen, SIGNAL(clicked()),this,  SLOT(slotPonerImagen()));
	connect(rBColor, SIGNAL(clicked()),this,  SLOT(slotPonerColor()));
	connect(radioButton, SIGNAL(clicked()),this,  SLOT(slotPonerTrama()));
	
	
	
}



void WidgetPRE::slotPonerImagen(){

	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                  "./",
                                                  tr("Images (*.png)"));
       
		
	QImage img = QImage(fileName);
	bola->imagen = img.scaled(bola->radio,bola->radio);
	bola->mostrarImagen = true;
	bola->seleccionada = false;
		
}

void WidgetPRE::slotPonerColor(){
	bola->color = QColor(QColorDialog::getColor(Qt::yellow, this ));
	bola->mostrarImagen = false;
	bola->seleccionada = false;
}

void WidgetPRE::slotPonerTrama(){
	bola->mostrarImagen = false;
	bola->seleccionada = true;

}

void WidgetPRE::slotModificarCheck(int state){

	
	
	if(state == 0){
	
		chBoxMostrarNum->setCheckState(Qt::Unchecked);
		
	}else{
	
		chBoxMostrarNum->setCheckState(Qt::Checked);
		
	}
	
	
	
	
	

}














