#include "DialogExamen.h"

DialogExamen::DialogExamen(QWidget * parent) : QDialog(parent){

	setupUi(this);
	dial->setNotchTarget(5.00);
	
	connect(rb_movimiento, SIGNAL(clicked()),this, SLOT(slotSeleccionMovimiento()));
	
}

void DialogExamen::slotSeccionMovimiento(void){
	/*if(rb_movimiento->isEnabled()){
		dial->setNotchesVisible(true);
	}else{
		dial->setNotchesVisible(false);
	}*/
}

void DialogExamen::slotSeccionInsercion(void){
	if(rb_insercion->isEnabled()){
		
	}else{
		lbInsercionTexo->
	}
}
