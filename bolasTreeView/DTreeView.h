#ifndef DTREEVIEW_H
#define DTREEVIEW_H
#include "ui_DTreeView.h"
#include <QDialog>
#include "bola.h"
#include <QVariant>
#include <QVector>

class ModelTree;

class DTreeView : public QDialog, public Ui::DTreeView {

	Q_OBJECT
	
public:

	
	DTreeView(QVector<Bola*> *,QWidget * parent = 0);
	QVector<Bola*> * bolas;
	ModelTree * modelo;
	
	
	
	
public slots:

	void slotTemporizador();
	void slotBoton();
	
private: 

	
	
};

class ModelTree : public QAbstractItemModel{
	
	Q_OBJECT

public:
	
	QVector<Bola*> * bolas;
	ModelTree(QVector<Bola*> *,QObject *parent = nullptr);
	int rowCount(const QModelIndex &)const;
	int columnCount(const QModelIndex &)const;
	QVariant data(const QModelIndex &, int) const;
	bool setData(const QModelIndex & , const QVariant & , int );
	int topBolasCount() const;
	Bola * topBola(int) const;
	
	QModelIndex index ( int row, int column, const QModelIndex & parent  ) const; 
	QModelIndex parent ( const QModelIndex & index ) const; 
	
	
	
	
};

#endif
