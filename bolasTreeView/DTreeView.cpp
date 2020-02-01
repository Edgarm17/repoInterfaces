#include "DTreeView.h"
#include "bola.h"
#include <QVector>
#include <QDebug>


DTreeView::DTreeView(QVector<Bola*> * bolas,QWidget * parent) : QDialog(parent){

	setupUi(this);
	

	this->bolas = bolas;
	modelo = new ModelTree(bolas);
	treeBolas->setModel(modelo);
	

	
}

ModelTree::ModelTree(QVector<Bola*> * bolas,QObject *parent) : QAbstractItemModel(parent){

	this->bolas = bolas;

		
}

int ModelTree::rowCount(const QModelIndex &parent)const{
	//qDebug() << topBolasCount() << endl;
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

QVariant ModelTree::data(const QModelIndex &index, int role) const{

	
	if(!index.isValid()){
		return QVariant(QString("Raiz"));
		
	}

	Bola * b = static_cast<Bola*> (index.internalPointer());

	if( role == Qt::DisplayRole ) {
		
		if(b == NULL){
			//qDebug() << "La bola b es nula" << endl;
		}
		
		if(index.column() == 0){

			//qDebug() << "hola 1" << endl;
			return QVariant(QString::number(b->id));
			
		}else if(index.column() == 1){
			//qDebug() << "hola 2" << endl;
			return QVariant(QString::number(b->x));
		}else if(index.column() == 2){
			//qDebug() << "hola 3" << endl;
			return QVariant(QString::number(b->y));
		}
	
	}

	if (role ==Qt::DecorationRole && b != NULL){ 
		//qDebug()<< "Ha entrat a data i el role es decoration" << endl;
		if(index.column() == 0){

			//qDebug() << "hola 1" << endl;
			
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
















