#include "DTreeView.h"
#include "bola.h"
#include <QVector>


DTreeView::DTreeView(QVector<Bola*> * bolas,QWidget * parent) : QDialog(parent){

	setupUi(this);
	

	this->bolas = bolas;
	
	

	
}

ModelTree::ModelTree(QVector<Bola*> * bolas,QObject *parent) : QAbstractItemModel(parent){

	this->bolas = bolas;

		
}

int ModelTree::rowCount(const QModelIndex &parent)const{
	
		
	return bolas->size();
	
}

int ModelTree::columnCount(const QModelIndex &parent)const{
	
		
	return 4;
	
}

QVariant ModelTree::data(const QModelIndex &index, int role) const{
	


	
}
