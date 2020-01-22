#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QChartView>
#include <QLineSeries>
#include <QChart>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

class VentanaPrincipal : public QMainWindow {

	Q_OBJECT
public:
        VentanaPrincipal(QWidget * parent = 0, Qt::WindowFlags flags = 0);
        
        QLineSeries * serie;
        QChart * chart;

                
public slots:
	
	void slotResaltar(const QPointF &, bool);
	void slotTemporizador();
	
};

#endif 
