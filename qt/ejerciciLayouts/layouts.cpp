#include <QCheckBox>
#include <QSlider>
#include <QPushButton>
#include <QLCDNumber>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "layouts.h"

Layout::Layout(QWidget *parent): QDialog(parent){

	slider1 = new QSlider();
	slider2 = new QSlider();
	slider3 = new QSlider();
	
	check1 = new QCheckBox("Activo");
	check2 = new QCheckBox("Activo");
	check3 = new QCheckBox("Activo");
	
	btn1 = new QPushButton("1");
	btn2 = new QPushButton("2");
	btn3 = new QPushButton("Ok");
	btn4 = new QPushButton("Cancel");
	
	qlcd = new QLCDNumber();
	
	
	QVBoxLayout *mainLayout = new QVBoxLayout;
	QHBoxLayout *topLayout = new QHBoxLayout;
	QHBoxLayout *bottomLayout = new QHBoxLayout;
	QVBoxLayout *topLeftLayout = new QVBoxLayout;
	QVBoxLayout *topMidLayout = new QVBoxLayout;
	QVBoxLayout *topRightLayout = new QVBoxLayout;
	QHBoxLayout *topRightTopLayout = new QHBoxLayout;
	
	//TOP RIGHT TOP LAYOUT
	topRightTopLayout->addWidget(btn1);
	topRightTopLayout->addWidget(btn2);
	
	//TOP RIGHT LAYOUT
	topRightLayout->addLayout(topRightTopLayout);
	topRightLayout->addWidget(qlcd);
	
	//TOP MID LAYOUT
	topMidLayout->addWidget(check1);
	topMidLayout->addWidget(check2);
	topMidLayout->addWidget(check3);
	
	//TOP LEFT LAYOUT
	topLeftLayout->addWidget(slider1);
	topLeftLayout->addWidget(slider2);
	topLeftLayout->addWidget(slider3);
	
	//BOTTOM LAYOUT
	bottomLayout->addWidget(btn3);
	bottomLayout->addStretch();
	bottomLayout->addWidget(btn4);
	
	//TOP LAYOUT
	topLayout->addLayout(topLeftLayout);
	topLayout->addLayout(topMidLayout);
	topLayout->addLayout(topRightLayout);
	
	//MAIN LAYOUT
	mainLayout->addLayout(topLayout);
	mainLayout->addLayout(bottomLayout);
	
	setLayout(mainLayout);
	
	slider1->setOrientation(Qt::Horizontal);
	slider2->setOrientation(Qt::Horizontal);
	slider3->setOrientation(Qt::Horizontal);
	
	slider1->setTickInterval(100);
	slider2->setTickInterval(100);
	slider3->setTickInterval(100);
	
	connect(btn4, SIGNAL(clicked()),
           this, SLOT(close()));
	
	connect(slider1, SIGNAL(valueChanged(int)),
          this, SLOT(mostrar(int)));
        connect(slider2, SIGNAL(valueChanged(int)),
          this, SLOT(mostrar(int)));
        connect(slider3, SIGNAL(valueChanged(int)),
          this, SLOT(mostrar(int)));
          
       	
	

}

void Layout::mostrar(int num){
	int suma = slider1->value() + slider2->value() +slider3->value();
     qlcd->display(suma);
 }
