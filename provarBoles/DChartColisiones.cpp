#include "DChartColisiones.h"
#include <QValueAxis>
#include <QStringList>
#include <QBarSet>

DChartColisiones::DChartColisiones(QVector<BolaYWidget*> vector,QWidget * parent) : QDialog(parent){

	setupUi(this);
	
	set = new QBarSet(QString("Bola"));
	
	QTimer * temporizador = new QTimer();
    	temporizador->setSingleShot(false);
    	temporizador->setInterval(300); 
    	
    	
    	connect(temporizador,SIGNAL(timeout()),this,
    		SLOT(slotTemporizador()));
    	temporizador->start();
	
	bolas = vector;
	
	chart = new QChart();
    	QChartView * chartView = new QChartView(chart);
    	series = new QBarSeries();
    	
    	chart->addSeries(series);
    	chart->setAnimationOptions(QChart::SeriesAnimations);
    	
    	
    	series->append(set);
    	axisX = new QBarCategoryAxis();
    	for(int i = 0; i < bolas.size(); i++){
    		
    		set->append(bolas.at(i)->colisiones);	
    		
    		axisX->append(QString("Bola ")+
    			QString::number(i)+QString(": ")+
    			QString::number(bolas.at(i)->colisiones));
    		
    	}
    	
    	
    	
    	
    	chart->addAxis(axisX, Qt::AlignBottom);
    	series->attachAxis(axisX);
    	
    	QValueAxis *axisY = new QValueAxis();
    	axisY->setRange(0,50);
    	axisY->setTickType(QValueAxis::TicksDynamic);
    	axisY->setTickAnchor(5);
    	axisY->setTickInterval(5);

    	chart->addAxis(axisY,Qt::AlignLeft);
    	series->attachAxis(axisY);
    	
    	
    	chart->setTitle("Colisiones bolas");
    	
    	chart->legend()->setVisible(true);
    	chart->legend()->setAlignment(Qt::AlignBottom);
    	
    	QVBoxLayout *layout = new QVBoxLayout;
      	layout->addWidget(chartView);
     	
    	
    	FrameBolas->setLayout(layout);
	
	
}

void DChartColisiones::slotTemporizador(){
	for(int i = 0; i<set->count(); i++){
		set->replace(i,bolas.at(i)->colisiones);
		
		axisX->replace(axisX->at(i), QString("Bola ")+
    			QString::number(i)+QString(": ")+
    			QString::number(bolas.at(i)->colisiones));
		
	}
}

















