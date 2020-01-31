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
	
	
	if(!parent.isValid()){
		qDebug()<< "rowCount es una bola original "<< endl;
		return topBolasCount();
	}
	
	
	Bola * b = static_cast<Bola*> (parent.internalPointer());
	if(b == NULL){
		qDebug()<< "ASDF" << endl;
	}
	
	qDebug()<< " rowCount: si que te pare " <<endl;
	return 2;
	
	
}

int ModelTree::columnCount(const QModelIndex &parent)const{
	
	qDebug()<< "columnCount fet" << endl;
	
	return 3;
	
}

QVariant ModelTree::data(const QModelIndex &index, int role) const{

	qDebug()<< "Ha entrat a data" << endl;

	if(!index.isValid()){ 
		qDebug()<< "Ha entrat a data i el index no es valid" << endl;
		return QModelIndex();
	
	}
	
	Bola * b = static_cast<Bola*> (index.internalPointer());
	qDebug()<< "Ha entrat a data i el index es valid" << endl;
	
	if( role == Qt::DisplayRole ) {
		qDebug()<< "Ha entrat a data i el rol es display" << endl;
		if(index.column() == 0){
			
			return QVariant(QString::number(b->id));
			
		}else if(index.column() == 1){
			
			return QVariant(QString::number(b->x));
		}else if(index.column() == 2){
			
			return QVariant(QString::number(b->y));
		}
	
	}
	
	if (role ==Qt::DecorationRole && b != NULL){ 
		qDebug()<< "Ha entrat a data i el role es decoration" << endl;
		return QVariant((b->color));
	
	}
	
        	
    	return QVariant();


	
}

QModelIndex ModelTree::index ( int row, int column, const QModelIndex & parent  ) const {

	qDebug()<< "Ha entrat a index" << endl;

	if(!parent.isValid() && (row < topBolasCount())){
		return createIndex(row,column,topBola(row));
	}
	qDebug()<< "index 1" << endl;
	Bola * pare = static_cast<Bola*> (parent.internalPointer());
	
	if(row < pare->hijas.size()){
		return createIndex(row,column,pare->hijas.at(row));
	}
	qDebug()<< "index 2" << endl;
	return QModelIndex();

}

QModelIndex ModelTree::parent ( const QModelIndex & index ) const{

	qDebug()<< "parent ENTRA" << endl;

	if(!index.isValid()) return QModelIndex();
	
	Bola * bola = static_cast<Bola*>(index.internalPointer());
	
	
	if(bola->pare == NULL) return QModelIndex();
	qDebug()<< "parent fet" << endl;
	
	
	return createIndex(0,0, bola->pare);
}

int ModelTree::topBolasCount() const{

	qDebug()<< "topBolasCount fet" << endl;
	
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
		qDebug()<< "topBola ha entrat al bucle" << endl;
		if(bolas->at(i)->pare == NULL){
			cont++;
		}
		if(cont == posicion){
			qDebug()<< "topBola ha retornat" << endl;
			return bolas->at(i);
		}
		
	}
	
	return NULL;
	
	qDebug()<< "topBola fet" << endl;
	
}
















