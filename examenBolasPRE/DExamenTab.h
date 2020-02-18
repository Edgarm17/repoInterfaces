#ifndef DEXAMENTAB_H
#define DEXAMENTAB_H
#include "ui_DExamenTab.h"
#include <QDialog>
#include <QVector>
#include "bola.h"

class DExamenTab : public QDialog, public Ui::DExamenTab {

	Q_OBJECT
	
public:

	
	DExamenTab(QVector<Bola*> *,QWidget * parent = 0);
	QVector<Bola*> * bolas;
	
	
	
public slots:

	
	void slotCambiarNombreBoton();


signals:

	void modificarTodosClicked(int);
	
	
};

#endif
