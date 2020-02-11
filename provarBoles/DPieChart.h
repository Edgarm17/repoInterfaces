#ifndef DPIECHART_H
#define DPIECHART_H
#include "ui_DPieChart.h"
#include <QDialog>
#include <QChartView>
#include <QChart>
#include <QVector>
#include <QPieSeries>
#include <QPieSlice>
#include "BolaYWidget.h"
#include <QTimer>

QT_CHARTS_USE_NAMESPACE

class DPieChart : public QDialog, public Ui::DPieChart {

	Q_OBJECT
	
public:

	
	DPieChart(QVector<BolaYWidget*> ,QWidget * parent = 0);
	
	QVector<BolaYWidget*> bolas;
	QChart * chart;
	QPieSeries * series;
	QPieSlice * slice;
                
public slots:
	
	
	void slotTemporizador();
	void slotHover(QPieSlice *, bool);
	
};
#endif
