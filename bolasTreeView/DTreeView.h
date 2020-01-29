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
	

	
	
	
	
};

#endif
