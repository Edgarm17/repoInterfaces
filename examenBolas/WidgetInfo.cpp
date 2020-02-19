#include "WidgetInfo.h"
#include "bola.h"
#include <QTimer>
#include <QVBoxLayout>
#include <QChartView>

int WidgetInfo::contWidFIN;

WidgetInfo::WidgetInfo(Bola * bola,QWidget * parent) : QWidget(parent){

	setupUi(this);
	this->bola = bola;
	
	contWidFIN++;
	
	connect(botonNext,SIGNAL(clicked()),this,SLOT(slotBotonNext()));
	connect(botonPrevious,SIGNAL(clicked()),this,SLOT(slotBotonPrev()));
	
	labelNumBola->setText("Bola Número "+QString::number(bola->id));
	
	QTimer * temporizador = new QTimer();
    	temporizador->setSingleShot(false);
    	temporizador->setInterval(1000); 
    	
    	
    	connect(temporizador,SIGNAL(timeout()),this,
    		SLOT(slotTemporizador()));
    	temporizador->start();
	
	seriesFIN = new QPieSeries();
	
	seriesFIN->append(QString("Bolas"), bola->colisionesBolas);
	
	sliceBolasFIN = seriesFIN->slices().at(0);
	sliceBolasFIN->setLabelVisible();
	
	seriesFIN->append(QString("Pared"), bola->colisionesPared);
	
	sliceParedFIN = seriesFIN->slices().at(1);
	sliceParedFIN->setLabelVisible();
	
	
	chartFIN = new QChart();
	chartFIN->addSeries(seriesFIN);
    	chartFIN->setTitle("Grafico pastel");
	chartFIN->setAnimationOptions(QChart::SeriesAnimations);
    	
	
	
	QChartView *chartView = new QChartView(chartFIN);
    	chartView->setRenderHint(QPainter::Antialiasing);
	chartView->chart()->setTheme(QChart::ChartThemeDark);
    	chartView->chart()->legend()->setFont(QFont("Arial", 7));
    
	
	QVBoxLayout * layout = new QVBoxLayout();
	
	layout->addWidget(chartView);
	
	
	frameChart->setLayout(layout);
	
	
	
}

void WidgetInfo::slotBotonNext(){
	
	emit botonNuevoWidgetClicked(bola->id,true);
	if(!chBNoCerrar->isChecked()) close();
}

void WidgetInfo::slotBotonPrev(){
	emit botonNuevoWidgetClicked(bola->id,false);
	if(!chBNoCerrar->isChecked()) close();
}

void WidgetInfo::slotTemporizador(){
	

		
	seriesFIN->slices().at(0)->setValue(bola->colisionesBolas);
	
	
	
	seriesFIN->slices().at(1)->setValue(bola->colisionesPared);
	

}

void WidgetInfo::closeEvent(QCloseEvent *event){
      
	if(chBNoCerrar->isChecked()){
		event->ignore();
		
	}
	
	
	
      
}


