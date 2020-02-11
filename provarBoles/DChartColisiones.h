#ifndef DCHARTCOLISIONES_H
#define DCHARTCOLISIONES_H
#include "ui_DChartColisiones.h"
#include <QDialog>
#include <QTimer>
#include <QChartView>
#include <QBarSeries>
#include <QChart>
#include <QVector>
#include <QValueAxis>
#include <QBarCategoryAxis>
#include "BolaYWidget.h"

QT_CHARTS_USE_NAMESPACE

class DChartColisiones : public QDialog, public Ui::DChartColisiones {

	Q_OBJECT
	
public:

	
	DChartColisiones(QVector<BolaYWidget*> ,QWidget * parent = 0);
	
	QVector<BolaYWidget*> bolas;
	QBarSeries * series;
        QChart * chart;
        QBarSet * set;
        QStringList bolasX;
        QBarCategoryAxis * axisX;
                
public slots:
	
	
	void slotTemporizador();
	
};
#endif
