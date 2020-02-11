#include "DialogoTabla.h"
#include "bola.h"
#include "BolaYWidget.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
DialogoTabla::DialogoTabla(QVector<BolaYWidget*> * bolas,QWidget * parent) : QDialog(parent){

	setupUi(this);
	

	this->bolas = bolas;
	modelo = new MiModelo(bolas);
	tableView->setModel(modelo);
	this->adjustSize();
	fichero = new QFile("bolas.txt");

	connect(tableView,SIGNAL(clicked(const QModelIndex &)),this,SLOT(slotTablaClicked(const QModelIndex &)));
	
	
}

MiModelo::MiModelo(QVector<BolaYWidget*> * bolas,QObject *parent) : QAbstractTableModel(parent){

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
	
		if(index.column() == 0){
			
			return QString::number(bolas->at(index.row())->Bola::x);
			
		}else if(index.column() == 1){
			
			return QString::number(bolas->at(index.row())->Bola::y);
		}else if(index.column() == 2){
			
			return QString::number(bolas->at(index.row())->vX);
		}else if(index.column() == 3){
			
			return QString::number(bolas->at(index.row())->vY);
		}
		
	
	
	
	
	
}

QVariant MiModelo::headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const{

	if(role != Qt::DisplayRole ) return QVariant();

	if(orientation == Qt::Horizontal){
		if(section == 0) return QString("PosX");
		if(section == 1) return QString("PosY");
		if(section == 2) return QString("VelX");
		if(section == 3) return QString("VelY");
	}else if(orientation == Qt::Vertical){
		if(section == 0) return QString("Bola 1");
		if(section == 1) return QString("Bola 2");
		if(section == 2) return QString("Bola 3");
		if(section == 3) return QString("Bola 4");
		if(section == 4) return QString("Bola 5");
	}

}

Qt::ItemFlags MiModelo::flags(const QModelIndex &index) const {


	return Qt::ItemIsEditable| Qt::ItemIsEnabled;


}

void DialogoTabla::slotTablaClicked(const QModelIndex &index){
	
	if(!index.isValid())return;

	int r = QMessageBox::warning(this,
		"Guardar bola",
		"Vas a guardar la bola "+QString::number(bolas->at(index.row())->Bola::id)+".\nVols continuar?",
		QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
		
		if (r == QMessageBox::Yes ){
			
			if(!fichero->exists()){
				QString ruta = QFileDialog::getSaveFileName(this,QString("Guardar documentillo"));
				delete fichero;
				fichero = new QFile(ruta);
				QTextStream stream(fichero);
				if(!fichero->open(QIODevice::WriteOnly)){
					qDebug() << "Algo va mal en el fichero";
					return;
				}

				stream << "Bola " << bolas->at(index.row())->Bola::id << endl;
				fichero->close();
			}else{
				QTextStream stream(fichero);
				if(!fichero->open(QIODevice::Append)){
					qDebug() << "Algo va mal en el fichero";
					return;
				}

				stream << "Bola " << bolas->at(index.row())->Bola::id << endl;
				fichero->close();
			}
			
			
			
		}
		if( r == QMessageBox::No){
			return;
		}
		if ( r == QMessageBox::Cancel ){
			return;
	}

	qDebug() << "Bola " << QString::number(bolas->at(index.row())->Bola::id) << endl; 

}

















