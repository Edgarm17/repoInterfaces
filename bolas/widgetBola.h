#ifndef WIDGETBOLA_H
#define WIDGETBOLA_H

#include "ui_widgetBola.h"
#include "bola.h"

class WidgetBola : public QWidget, public Ui::WidgetBola{

	Q_OBJECT

public:
        WidgetBola(Bola *,QWidget * parent = 0);
        Bola * bola;
        
        
        
public slots:

	void slotPararBola();
	void slotCambiarColor();        
private:

};

#endif 
