#ifndef DIALOGSEGON_H
#define DIALOGSEGON_H
#include "ui_DialogSegon.h"
#include <QDialog>
#include "BolaYWidget.h"
#include <QVector>
#include "bola.h"

class DialogSegon : public QDialog, public Ui::DialogSegon {

	Q_OBJECT
	
public:

	
	DialogSegon(QVector<BolaYWidget*> *,QWidget * parent = 0);
	QVector<BolaYWidget*> * bolas;
	
	
	
public slots:

	
	
private: 

	
	
};

#endif
