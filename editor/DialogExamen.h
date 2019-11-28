#ifndef DIALOGEXAMEN_H
#define DIALOGEXAMEN_H
#include "ui_DialogExamen.h"
#include <QDialog>

class DialogExamen : public QDialog, public Ui::DialogExamen {

	Q_OBJECT
	
public:

	DialogExamen(QWidget * parent = 0);
	
private slots:

	void slotSeccionMovimiento();
	void slotSeccionInsercion();

	
	
};


#endif
