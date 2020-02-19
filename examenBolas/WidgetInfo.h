#ifndef WIDGETINFO_H
#define WIDGETINFO_H

#include "ui_WidgetInfo.h"
#include "bola.h"
#include <QChart>
#include <QPieSeries>
#include <QPieSlice>

QT_CHARTS_USE_NAMESPACE

class WidgetInfo : public QWidget, public Ui::WidgetInfo{

	Q_OBJECT

public:
        WidgetInfo(Bola *,QWidget * parent = 0);
        Bola * bola;
        
        QChart * chartFIN;
	QPieSeries * seriesFIN;
	QPieSlice * sliceBolasFIN;
	QPieSlice * sliceParedFIN;
	static int contWidFIN;
	
	void closeEvent(QCloseEvent *e);
        
public slots:
      
	void slotTemporizador();
	void slotBotonNext();
	void slotBotonPrev();
	
signals:

	void botonNuevoWidgetClicked(int,bool);
	

};

#endif 
