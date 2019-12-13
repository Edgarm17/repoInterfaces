#ifndef DIALOGEXAMEN_H
#define DIALOGEXAMEN_H
#include "ui_dialogExamen.h"
#include <QDialog>
#include <QStringList>

class DialogExamen : public QDialog, public Ui::DialogExamen {

	Q_OBJECT
	
public:

	DialogExamen(QWidget * parent = 0);
	QStringList lista;
private: 

	
public slots:
	
	void slotDialChanged(int); 
	void slotRadioButtonsToggled(bool);
	void slotBotones();
	void slotAddPalabra();
	void slotCambiarPalabra(QString);
};


#endif
