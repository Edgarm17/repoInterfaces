#include "DialogProva.h"
#include "bola.h"
#include "BolaYWidget.h"
#include <QDebug>
#include <QFileDialog>
#include <QColorDialog>
#include <QColor>
DialogProva::DialogProva(QWidget * parent) : QDialog(parent){

	setupUi(this);
	

	cbApariencia->addItem("Color");
	cbApariencia->addItem("Imagen");
	
	
	connect(btnElegir,SIGNAL(clicked()),this,SLOT(slotApariencia()));
	connect(btnCrear,SIGNAL(clicked()),this,SLOT(slotCrearBola()));
	
}

void DialogProva::slotApariencia(){
	
	QString seleccionado = cbApariencia->itemText(cbApariencia->currentIndex());
	if(cbApariencia->currentIndex() == 0){

		color = new QColor(QColorDialog::getColor(Qt::yellow, this ));
		
		
	}else{
		QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                  "./",
                                                  tr("Images (*.png *.xpm *.jpg)"));
		QString path = "./"+fileName.section('/',5,6);
		//qDebug() << path;
		imagen = new QImage(path);
		//qDebug() << fileName;
		
	}
	


	  
}

void DialogProva::slotCrearBola(){

	posicionX = lePosX->text().toFloat();
	posicionY = lePosY->text().toFloat();
	radioBola = leRadio->text().toFloat();
	velocidad = leVel->text().toFloat();
	
	if(cbApariencia->currentIndex() == 0){
		BolaYWidget * b = new BolaYWidget(false,posicionX,posicionY,velocidad,velocidad,radioBola,*color);
		emit bolaCreada(b);
	}else{
		BolaYWidget * b = new BolaYWidget(false,posicionX,posicionY,velocidad,velocidad,radioBola,*imagen);
		emit bolaCreada(b);
	}	

	

	  
}
