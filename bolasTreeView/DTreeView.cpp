#include "DTreeView.h"
#include "bola.h"
#include <QVector>
#include <QDebug>
#include <QTimer>

DTreeView::DTreeView(QVector<Bola*> * bolas,QWidget * parent) : QDialog(parent){

	setupUi(this);
	

	this->bolas = bolas;
	modelo = new ModelTree(bolas);
	treeBolas->setModel(modelo);
	
	QTimer * temporizador = new QTimer();
    	temporizador->setSingleShot(false);
    	temporizador->setInterval(300);

	connect(temporizador,SIGNAL(timeout()),this,
    	SLOT(slotTemporizador()));
    	temporizador->start();

	connect(btnTreeview,SIGNAL(clicked()),this,SLOT(slotBoton()));

}

void DTreeView::slotTemporizador(){
	
}

void DTreeView::slotBoton(){
	modelo = new ModelTree(bolas);
	treeBolas->setModel(modelo);
}

ModelTree::ModelTree(QVector<Bola*> * bolas,QObject *parent) : QAbstractItemModel(parent){

	this->bolas = bolas;

		
}

int ModelTree::rowCount(const QModelIndex &parent)const{
	if(!parent.isValid()){
		return topBolasCount();
	}

	Bola * b = static_cast<Bola*>(parent.internalPointer());

	if(b == NULL){
		qDebug() << "La bola parent es valida pero es nula" << endl;
	}

	return b->hijas.size();

}

int ModelTree::columnCount(const QModelIndex &parent)const{
	
	
	
	return 3;
	
}

bool ModelTree::setData(const QModelIndex & index, const QVariant & value, int role){

	
	if(!index.isValid())	return false;	
	
	if( role == Qt::EditRole){

		//Bola * b = qvariant_cast<Bola*>(value);
		//bolas->replace(index.row(), value);
		//emit dataChanged(index,index);
		//return true;

		//Bola * b = static_cast<Bola*> (index.internalPointer());
		//
		//if(index.column() == 0){
		//	
		//}else if(index.column() == 1){
		//	b->x = value.toFloat();
		//	return true;
		//}else if(index.column() == 2){
		//	b->y = value.toFloat();
		//	return true;
		//}
	}

	return false;


}

QVariant ModelTree::data(const QModelIndex &index, int role) const{

	
	if(!index.isValid()){
		return QVariant(QString("Raiz"));
		
	}

	Bola * b = static_cast<Bola*> (index.internalPointer());

	if( role == Qt::DisplayRole ) {
		
		if(b == NULL){
		}
		
		if(index.column() == 0){

			return QVariant(QString::number(b->id));
			
		}else if(index.column() == 1){
			return QVariant(QString::number(b->x));
		}else if(index.column() == 2){
			return QVariant(QString::number(b->y));
		}
	
	}

	if (role ==Qt::DecorationRole && b != NULL){ 
		if(index.column() == 0){

			
			
			return QVariant(b->color);
			
		}
		
	
	}
        	
    	return QVariant();


	
}

QModelIndex ModelTree::index ( int row, int column, const QModelIndex & parent  ) const {

	if(!parent.isValid() && (row < topBolasCount())){
		
		Bola * b = topBola(row);
		if(b == NULL){
			qDebug() << "La bola de topBola es nula" << endl;
		}
		return createIndex(row,column,b);
	}

	Bola * pare = static_cast<Bola*> (parent.internalPointer());
	
	if(row < pare->hijas.size()){
		return createIndex(row,column,pare->hijas.at(row));
	}

	return QModelIndex();

}

QModelIndex ModelTree::parent ( const QModelIndex & index ) const{

	if(!index.isValid()) return QModelIndex();
	
	Bola * bola = static_cast<Bola*>(index.internalPointer());
	if(bola->pare == NULL) return QModelIndex();

	return createIndex(0,0,bola->pare);
}

int ModelTree::topBolasCount() const{

	
	
	int cont = 0;
	
	for(int i = 0; i<bolas->size(); i++){
		if(bolas->at(i)->pare == NULL){
			
			cont++;
			
		}
	}
	
	
	return cont;
	
}

Bola * ModelTree::topBola(int posicion) const{
	
	int cont = 0;
	
	for(int i = 0; i < bolas->size(); i++){
		if(cont == posicion){
			
			return bolas->at(i);
		}
		if(bolas->at(i)->pare == NULL){
			cont++;
		}
		
		
	}
	
	return NULL;

	
}
















