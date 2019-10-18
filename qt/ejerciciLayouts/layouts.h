#ifndef LAYOUTS_H
#define LAYOUTS_H

#include <QDialog>

class QCheckBox;
class QSlider;
class QPushButton;
class QLCDNumber;

class Layout : public QDialog{

	Q_OBJECT
	
public: 

	Layout(QWidget *parent = 0);

private: 
	QSlider * slider1;
	QSlider * slider2;
	QSlider * slider3;
	QCheckBox * check1;
	QCheckBox * check2;
	QCheckBox * check3;
	QPushButton * btn1;
	QPushButton * btn2;
	QPushButton * btn3;
	QPushButton * btn4;
	QLCDNumber * qlcd;
 private slots:
 	
 	void mostrar(int num);


};
#endif
