#ifndef WIDGETPRE_H
#define WIDGETPRE_H

#include "ui_WidgetPRE.h"
#include "bola.h"

class WidgetPRE : public QWidget, public Ui::WidgetPRE{

	Q_OBJECT

public:
        WidgetPRE(Bola *,QWidget * parent = 0);
        Bola * bola;
        
        
        
public slots:

	void slotPonerImagen();
	void slotPonerColor();
	void slotPonerTrama();
      	
      	void slotTextoBola(int);
      
signals:

	void imgSelected(Bola *);

};

#endif 
