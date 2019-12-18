#include "DialogoTabla.h"
#include "bola.h"

DialogoTabla::DialogoTabla(QVector<Bola*> * bolas,QWidget * parent) : QDialog(parent){

	setupUi(this);
	
	this->bolas = bolas;
	modelo = new MiModelo(bolas);
	tableView->setModel(modelo);
	
	
}

MiModelo::MiModelo(QVector<Bola*> * bolas,QObject *parent) : QAbstractTableModel(parent){

	this->bolas = bolas;

		
}

int MiModelo::rowCount(const QModelIndex &parent)const{
	
		
	return bolas->size();
	
}

int MiModelo::columnCount(const QModelIndex &parent)const{
	
		
	return 4;
	
}

QVariant MiModelo::data(const QModelIndex &index, int role) const{
	
	if( role != Qt::DisplayRole ) return QVariant();
	
	
	
	if(index.row() == 1){
		
		if(index.column() == 1){
			
			return QString::number((*bolas).at(0)->x);
			
		}else if(index.column() == 2){
			
			return QString::number(bolas->at(0)->y);
		}else if(index.column() == 3){
			
			return QString::number(bolas->at(0)->vX);
		}else if(index.column() == 4){
			
			return QString::number(bolas->at(0)->vY);
		}
		
	}
	
	
	
	
}
