#include "DPieChart.h"
#include <QVBoxLayout>
#include <QDebug>

DPieChart::DPieChart(QVector<BolaYWidget*> vector,QWidget * parent) : QDialog(parent){

	setupUi(this);
	
	
	QTimer * temporizador = new QTimer();
    	temporizador->setSingleShot(false);
    	temporizador->setInterval(300); 
    	
    	
    	connect(temporizador,SIGNAL(timeout()),this,
    		SLOT(slotTemporizador()));
    	temporizador->start();
	
	
	
	bolas = vector;
	
	//SERIE
    	series = new QPieSeries();
	
	

	for(int i = 0; i<vector.size(); i++){
		series->append(QString("Bola ")+QString::number(vector.at(i)->id)+QString(":")+QString::number(vector.at(i)->colisiones),vector.at(i)->colisiones);
	}

	

	//SLICE
	
	for(int i = 0; i<vector.size(); i++){
		slice = series->slices().at(i);
		slice->setLabelVisible();
	}
	
	
	/*
	slice = series->slices().at(1);
	slice->setExploded();
   	slice->setLabelVisible();
    	slice->setPen(QPen(Qt::darkGreen, 2));
    	slice->setBrush(Qt::green);
	*/    	

    	//QCHART
	chart = new QChart();
	chart->addSeries(series);
    	chart->setTitle("Grafico pastel");
	chart->setAnimationOptions(QChart::SeriesAnimations);
    	chart->legend()->hide();

	//QCHART VIEW
	QChartView *chartView = new QChartView(chart);
    	chartView->setRenderHint(QPainter::Antialiasing);
	chartView->chart()->setTheme(QChart::ChartThemeDark);
    	chartView->chart()->legend()->setFont(QFont("Arial", 7));
    	
	QVBoxLayout* vLayout = new QVBoxLayout(this);
	vLayout->addWidget(chartView);

    	this->setLayout(vLayout);
	
	connect(series,SIGNAL(hovered(QPieSlice *, bool )),this,
    		SLOT(slotHover(QPieSlice *, bool)));
    	temporizador->start();
}



void DPieChart::slotTemporizador(){
	

	for(int i = 0; i<bolas.size(); i++){
		
		series->slices().at(i)->setValue(bolas.at(i)->colisiones);
		series->slices().at(i)->setLabel(QString("Bola ")+QString::number(bolas.at(i)->id)+QString(":")+QString::number(bolas.at(i)->colisiones));
	}

	//for(auto slice : series->slices())
    	//	slice->setLabel(QString("%1%").arg(100*slice->percentage(), 0, 'f', 1));

	//series->setLabelsVisible();
	//series->setLabelsPosition(QPieSlice::LabelInsideHorizontal);

	

	
}

void DPieChart::slotHover(QPieSlice * slice, bool state){
	
	if(state){
		slice->setExploded(true);
		//slice->setPen(QPen(Qt::darkGreen, 2));
    		//slice->setBrush(Qt::green);
	}else{
		slice->setExploded(false);
	}
	

	
}


















