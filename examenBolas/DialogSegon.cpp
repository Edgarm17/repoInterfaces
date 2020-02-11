#include "DialogSegon.h"
#include "BolaYWidget.h"
#include <QVector>
#include "widgetBola.h"
#include <QDebug>

DialogSegon::DialogSegon(QVector<BolaYWidget*> * bolas,QWidget * parent) : QDialog(parent){

	setupUi(this);
	
	this->bolas = bolas;
	
}




