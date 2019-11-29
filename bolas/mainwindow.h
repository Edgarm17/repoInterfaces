#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <bola.h>
#include <iostream>
#include <stdio.h>
#include <QVector>
class MainWindow : public QMainWindow {
Q_OBJECT
public:
        MainWindow(QWidget * parent = 0, Qt::WindowFlags flags = 0);
	void paintEvent(QPaintEvent * );
	

private:
        int posX;
	int posY;
	float velX;
	float velY;

	QVector<Bola*> bolas;
	void cargarBolas(QVector<Bola*> bolas);
        
public slots:

	void slotRepintar();
	
};

#endif 
