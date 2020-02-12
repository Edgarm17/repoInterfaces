#ifndef DIALOGINFO_H
#define DIALOGINFO_H
#include "ui_DialogInfo.h"
#include <QDialog>
#include "BolaYWidget.h"
#include <QVector>
#include "bola.h"

class DialogInfo : public QDialog, public Ui::DialogInfo {

	Q_OBJECT
	
public:

	
	DialogInfo(BolaYWidget * b,QWidget * parent = 0);
	BolaYWidget * bola;
	
	
	
public slots:

	void slotTemporizador();
	
private: 

	
	
};

#endif
