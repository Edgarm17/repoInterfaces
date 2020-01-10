#ifndef DCONTROLBOLAS_H
#define DCONTROLBOLAS_H
#include "ui_DControlBolas.h"
#include <QDialog>
#include "bola.h"
#include <QVector>

class DControlBolas : public QDialog, public Ui::DControlBolas {

	Q_OBJECT
	
public:

	
	DControlBolas(QVector<Bola*> *,QWidget * parent = 0);
	QVector<Bola*> * bolas;
	
	void insertarBolas(QVector<Bola*> *);
	void closeEvent(QCloseEvent *e);
	
public slots:

	void slotPararBolas();
	void slotBolaSeleccionada(int );
	
private: 

	
	
};

#endif
