#ifndef DTABLAPRE_H
#define DTABLAPRE_H
#include "ui_DTablaPRE.h"
#include <QDialog>
#include <QVariant>
#include "bola.h"
#include <QVector>
#include <QFile>
class MiModelo;

class DTablaPre : public QDialog, public Ui::DTablaPre {

	Q_OBJECT
	
public:

	
	DTablaPre(QVector<Bola*> *,QWidget * parent = 0);
	QVector<Bola*> * bolas;
	MiModelo * modelo;
	
	
public slots:

	

	
	
};

class MiModelo : public QAbstractTableModel{
	
	Q_OBJECT

public:
	
	QVector<Bola*> * bolas;
	
	MiModelo(QVector<Bola*> *,QObject *parent = nullptr);
	int rowCount(const QModelIndex &)const;
	int columnCount(const QModelIndex &)const;
	QVariant data(const QModelIndex &, int) const;
	QVariant headerData(int , Qt::Orientation , int ) const;

	Qt::ItemFlags flags(const QModelIndex &) const;
	
	
};


#endif
