#ifndef DEXAMENTAB_H
#define DEXAMENTAB_H
#include "ui_DExamenTab.h"
#include <QDialog>
#include "BolaYWidget.h"
#include <QVector>
#include "bola.h"

class DExamenTab : public QDialog, public Ui::DExamenTab {

	Q_OBJECT
	
public:

	
	DExamenTab(QVector<BolaYWidget*> *,QWidget * parent = 0);
	QVector<BolaYWidget*> * bolas;
	
	
	
public slots:

	
	
private: 

	
	
};

#endif
