#ifndef DIALOGINFO_H
#define DIALOGINFO_H
#include "ui_DialogInfo.h"
#include <QDialog>
#include <QVector>
#include "bola.h"

class DialogInfo : public QDialog, public Ui::DialogInfo {

	Q_OBJECT
	
public:

	
	DialogInfo(Bola * b,QWidget * parent = 0);
	Bola * bola;
	
	
	
public slots:

	void slotTemporizador();
	
private: 

	
	
};

#endif
