#ifndef DIALOGOTABLA_H
#define DIALOGOTABLA_H
#include "ui_DialogoTabla.h"
#include <QDialog>
#include <QVariant>
#include "bola.h"
#include <QVector>
#include <BolaYWidget.h>
#include <QFile>
class MiModelo;

class DialogoTabla : public QDialog, public Ui::DialogoTabla {

	Q_OBJECT
	
public:

	
	DialogoTabla(QVector<BolaYWidget*> *,QWidget * parent = 0);
	QVector<BolaYWidget*> * bolas;
	MiModelo * modelo;
	QFile * fichero;
	
public slots:

	void slotTablaClicked(const QModelIndex &); 

	
	
};

class MiModelo : public QAbstractTableModel{
	
	Q_OBJECT

public:
	
	QVector<BolaYWidget*> * bolas;
	
	MiModelo(QVector<BolaYWidget*> *,QObject *parent = nullptr);
	int rowCount(const QModelIndex &)const;
	int columnCount(const QModelIndex &)const;
	QVariant data(const QModelIndex &, int) const;
	QVariant headerData(int , Qt::Orientation , int ) const;

	Qt::ItemFlags flags(const QModelIndex &) const;
	
	
};


#endif
