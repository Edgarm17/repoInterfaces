#ifndef DCONTROLBOLAS_H
#define DCONTROLBOLAS_H
#include "ui_DControlBolas.h"
#include <QDialog>
#include "BolaYWidget.h"
#include <QVector>

class DControlBolas : public QDialog, public Ui::DControlBolas {

	Q_OBJECT
	
public:

	
	DControlBolas(QVector<BolaYWidget*> *,QWidget * parent = 0);
	QVector<BolaYWidget*> * bolas;
	QVector<BolaYWidget*> * bolasAux;
	
	void insertarBolas(QVector<BolaYWidget*> *);
	void closeEvent(QCloseEvent *e);
	
public slots:

	void slotPararBolas();
	void slotBolaSeleccionada(int );
	void slotAceptar();
	void slotCancelar();
	
private: 

	
	
};

#endif
