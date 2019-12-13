#include "dialogExamen.h"
#include <QStringList>
#include <QMessageBox>

DialogExamen::DialogExamen(QWidget * parent) : QDialog(parent){

	setupUi(this);

	lista.append("nada");
	lista.append("caracter");
	lista.append("línea");
	lista.append("párrafo");
	lista.append("documento");

	dial->setRange(0,4);
	connect(dial,SIGNAL(valueChanged(int)),this,SLOT(slotDialChanged(int)));
	connect(rbMovimiento, SIGNAL(toggled(bool)),this,SLOT(slotRadioButtonsToggled(bool)));
	connect(btnAdelante,SIGNAL(clicked()),this,SLOT(slotBotones()));
	connect(btnAtras,SIGNAL(clicked()),this,SLOT(slotBotones()));
	connect(btnIntroTxt,SIGNAL(clicked()),this,SLOT(slotAddPalabra()));
	connect(cbPalabras, SIGNAL(currentTextChanged(const QString)),this,SLOT(slotCambiarPalabra(QString)));
}

void DialogExamen::slotDialChanged(int valor){

	// "nada", "caracter", "línea", "párrafo", "documento"
	
	
	lbValor->setText(QString("Valor: ")+lista.at(valor));

}

void DialogExamen::slotRadioButtonsToggled(bool checked){

	if(rbMovimiento->isChecked()){
		dial->setEnabled(true);
		btnAdelante->setEnabled(true);
		btnAtras->setEnabled(true);
		lineEdit->setEnabled(false);
		btnIntroTxt->setEnabled(false);
		cbPalabras->setEnabled(false);
		checkAdd->setEnabled(false);
	}else{
		dial->setEnabled(false);
		btnAdelante->setEnabled(false);
		btnAtras->setEnabled(false);
		lineEdit->setEnabled(true);
		btnIntroTxt->setEnabled(true);
		cbPalabras->setEnabled(true);
		checkAdd->setEnabled(true);
	}
	
}

void DialogExamen::slotBotones(){

	QString cadAdelante("Va usted a avanzar");
	QString cadAtras("Va usted a retroceder");

	QPushButton * btnPulsado;
	btnPulsado = qobject_cast<QPushButton*>(sender());
	QString cadElegida;

	if(btnPulsado == btnAdelante){
		cadElegida = cadAdelante;
	}
	
	if(btnPulsado == btnAtras){
		cadElegida = cadAtras;
	}
	
	cadElegida = cadElegida + " " + lista.at(dial->value());

	int r = QMessageBox::warning(this, tr("Editor"),
			cadElegida,
			QMessageBox::Yes | QMessageBox::No);


}

void DialogExamen::slotAddPalabra(){
	
	if(!checkAdd->isChecked()) return;
	bool existe = false;

	QStringList conjunto = lineEdit->text().split(' ');
	if(conjunto.count() != 1) return;
	
	for(int i = 0; i<cbPalabras->count(); i++){
	
		if(cbPalabras->itemText(i) == lineEdit->text()){return;}

	}
	
	
	cbPalabras->addItem(lineEdit->text());
	
	

}

void DialogExamen::slotCambiarPalabra(QString palabra){

	lineEdit->setText(palabra);

}



























