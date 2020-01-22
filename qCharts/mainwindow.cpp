#include "mainwindow.h"
#include <QDebug>

VentanaPrincipal::VentanaPrincipal(QWidget * parent ,Qt::WindowFlags flags ) : QMainWindow(parent,flags) {

    	
    	QTimer * temporizador = new QTimer();
    	temporizador->setSingleShot(false);
    	temporizador->setInterval(1000); 
    	
    	
    	connect(temporizador,SIGNAL(timeout()),this,
    		SLOT(slotTemporizador()));
    	temporizador->start();
    	
    	chart = new QChart();
    	QChartView * chartView = new QChartView(chart);
    	
    	setCentralWidget(chartView);
    	
    	serie = new QLineSeries();
    	
    	serie->append(1,1);
    	serie->append(2,0);
    	serie->append(4,6);
    	chart->addSeries(serie);
    	
    	QValueAxis * axisY = new QValueAxis;
    	axisY->setRange(0,7);
    	axisY->setTitleText("Goles");
    	
    	QValueAxis * axisX = new QValueAxis;
    	axisX->setRange(0,5);
    	axisX->setTitleText("Dias");
    	
    	chart->addAxis(axisY,Qt::AlignLeft);
    	chart->addAxis(axisX,Qt::AlignBottom);
    	
    	serie->attachAxis(axisX);
    	serie->attachAxis(axisY);
    	
    	//chart->legend->hide();
    	serie->setName(QString("Prova"));
    	
    	chartView->setRenderHint(QPainter::Antialiasing);
    	
    	connect(serie,SIGNAL(hovered(const QPointF &, bool)),this,
    		SLOT(slotResaltar(const QPointF &, bool)));
    	
    	resize(800,600);
}

void VentanaPrincipal::slotResaltar(const QPointF & point, bool estado){
	
	QPen pen;
	
	if(estado){
		pen.setColor(Qt::red);
		pen.setWidth(3);	
	}else{
		pen.setColor(Qt::blue);
		pen.setWidth(2);
	}
	
	serie->setPen(pen);
	
	
}

void VentanaPrincipal::slotTemporizador(void){
	
	int tamanyoSerie = serie->count();
	double coordX = serie->at(tamanyoSerie - 1).x();
	double coordY = serie->at(tamanyoSerie - 1).y();
	
	serie->replace(tamanyoSerie - 1, coordX, coordY + 0.5 );
	
	QList<QAbstractAxis *> listaEjes = chart->axes(Qt::Vertical);
	
	foreach( QAbstractAxis * eje, listaEjes){
		serie->detachAxis(eje);
		chart->removeAxis(eje);
		delete eje;
	}
	
	QValueAxis * axisY = new QValueAxis;
	axisY->setRange(0,coordY + 1.5);
	axisY->setTitleText("Goles");
	
	chart->addAxis(axisY, Qt::AlignLeft);
	serie->attachAxis(axisY);
}







