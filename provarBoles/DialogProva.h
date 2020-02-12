#ifndef DIALOGPROVA_H
#define DIALOGPROVA_H
#include "ui_DialogProva.h"
#include <QDialog>
#include "bola.h"
#include <QVector>
#include <BolaYWidget.h>



class DialogProva : public QDialog, public Ui::DialogProva {

	Q_OBJECT
	
public:

	
	DialogProva(QWidget * parent = 0);
	float posicionX;
	float posicionY;
	float radioBola;
	float velocidad;
	QImage * imagen;
	QColor * color;
	
	
public slots:

	void slotApariencia();
	void slotCrearBola();
	
signals:

	void bolaCreada(BolaYWidget * );

};

#endif
