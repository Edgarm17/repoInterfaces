#ifndef WIDGETPOSICION_H
#define WIDGETPOSICION_H

#include <QWidget>
#include <QMouseEvent>

class WidgetPosicion : public QWidget{

	Q_OBJECT

public:
        WidgetPosicion(QWidget * parent = 0);

	void mousePressEvent(QMouseEvent *);
   
public slots:


signals:

	void posicionCambiada(int,int);
     	


};

#endif 
