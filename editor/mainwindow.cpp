#include "mainwindow.h"
#include <QStatusBar>
#include <QMenuBar>
#include <QMessageBox>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QLabel>
#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QTextBlock>

#include "DBuscarReemplazar.h"
#include "DialogExamen.h"

VentanaPrincipal::VentanaPrincipal(QWidget * parent ,Qt::WindowFlags flags ) : QMainWindow(parent,flags) {

	guardar = false;
        editorCentral = new QTextEdit(this);
        setCentralWidget(editorCentral);
        crearQActions();
        fichero = new QFile("");
        nombreFichero = new QString(fichero->fileName());
        archivoAbierto = false;
        
        crearMenus();
        crearBarras();
        crearBarraEstado();
        
        
    	setWindowIcon(QIcon(":/images/icon.png"));
    
    
}

void VentanaPrincipal::crearQActions(){
	
        accionSalir = new QAction("Cerrar",this);
        accionSalir -> setShortcut(QKeySequence::Close);
        
        
        accionCopiar = new QAction("Copiar",this);
        accionCopiar -> setShortcut(QKeySequence::Copy);
        
       	
        accionCortar = new QAction("Cortar",this);
        accionCopiar -> setShortcut(QKeySequence::Cut);
        
        
        accionPegar = new QAction("Pegar",this);
        accionPegar -> setShortcut(QKeySequence::Paste);
        
        accionNuevo = new QAction("Nuevo",this);
        accionNuevo -> setShortcut(QKeySequence::New);
        
        accionGuardar = new QAction("Guardar",this);
        accionGuardar -> setShortcut(QKeySequence::Save);
        
        accionGuardarComo = new QAction("Guardar Como",this);
        accionGuardarComo -> setShortcut(QKeySequence::SaveAs);
        
        accion1 = new QAction("icon",this);
        accion1->setIcon(QIcon(":/images/icon.png"));
        
        accion2 = new QAction("new",this);
        accion2->setIcon(QIcon(":/images/new.png"));
        
        accion3 = new QAction("cara",this);
        accion3->setIcon(QIcon(":/images/cara.png"));
        
        accionAbrir = new QAction("Abrir archivo",this);
        accionAbrir->setShortcut(QKeySequence::Open);
        
        accionDialogo = new QAction("Buscar y reemplazar",this);
        
        accionExamen = new QAction("Examen",this);
        
        
        
        
        
        connect(accionSalir, SIGNAL(triggered()),this, SLOT(slotCerrar()));
        connect(accionCopiar, SIGNAL(triggered()),this, SLOT(slotCopiar()));
        connect(accionCortar, SIGNAL(triggered()),this, SLOT(slotCortar()));
        connect(accionPegar, SIGNAL(triggered()),this, SLOT(slotPegar()));
        connect(accionNuevo, SIGNAL(triggered()),this,SLOT(slotNuevo()));
        connect(editorCentral, SIGNAL(textChanged()),this,SLOT(slotComprobar()));
        connect(accionGuardar, SIGNAL(triggered()),this, SLOT(slotGuardar()));
        connect(accion1, SIGNAL(triggered()),this,SLOT(slotMostrarIcono()));
        connect(accion2, SIGNAL(triggered()),this,SLOT(slotMostrarIcono()));
        connect(accion3, SIGNAL(triggered()),this,SLOT(slotMostrarIcono()));
        connect(editorCentral, SIGNAL(cursorPositionChanged()),this,SLOT(slotCambioEstado()));
        connect(editorCentral, SIGNAL(textChanged()),this,SLOT(slotEncontrarPalabra()));
        connect(accionAbrir, SIGNAL(triggered()),this,SLOT(slotAbrir()));
        connect(accionGuardarComo, SIGNAL(triggered()),this, SLOT(slotGuardarComo()));
        connect(accionDialogo, SIGNAL(triggered()),this, SLOT(slotDialogo()));
        connect(accionExamen, SIGNAL(triggered()),this, SLOT(slotExamen()));
        
        
}

void VentanaPrincipal::crearMenus(){

	menuArchivo = menuBar()->addMenu("Archivo");
        menuArchivo ->addAction(accionSalir);
        menuArchivo ->addAction(accionNuevo);
        menuArchivo -> addAction(accionGuardar);
        menuArchivo -> addAction(accionAbrir);
        menuArchivo -> addAction(accionGuardarComo);
        menuArchivo -> addAction(accionDialogo);
        
        menuEditar = menuBar()->addMenu("Editar");
	menuEditar->addAction(accionCopiar);
	menuEditar->addAction(accionCortar);
	menuEditar->addAction(accionPegar);
	menuEditar->addAction(accionExamen);
	
	editorCentral->addAction(accionNuevo);
	editorCentral->setContextMenuPolicy(Qt::ActionsContextMenu);
	
	
	
}

void VentanaPrincipal::crearBarras(){
	
	
	
	barraPrincipal = this->addToolBar("Barra");
	barraPrincipal -> addAction(accion1);
	barraPrincipal -> addAction(accion2);
	barraPrincipal -> addAction(accion3);

}

void VentanaPrincipal::crearBarraEstado(){
	parrafo = new QLabel("Parrafo: 1");
	fila = new QLabel("Fila: 1");
	columna = new QLabel("Columna: 1");
	labels.append(parrafo);
	labels.append(fila);
	labels.append(columna);
	
	for(int i = 0; i < labels.size(); i++){
		statusBar() -> addWidget(labels.value(i));
	}
	
	
}

void VentanaPrincipal::slotCerrar(void){
	
	if(!guardar){
      		slotGuardar();
      		this->close();
      	}else{
      		this->close();
      	}

	
}

void VentanaPrincipal::slotCopiar(void){
	editorCentral -> copy();
}

void VentanaPrincipal::slotCortar(void){
	editorCentral -> cut();
}

void VentanaPrincipal::slotPegar(void){
	editorCentral -> paste();
}


void VentanaPrincipal::slotNuevo(void){

	
	
	
		
	
	if(guardar){
		delete fichero;
		fichero = new QFile("");
		editorCentral -> clear();
		
	}else{
		int r = QMessageBox::warning(this,
		"EditorClase",
		"El document ha sigut modificat.\nVols guardar els canvis?",
		QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
		
		if (r == QMessageBox::Yes ){
			guardar = true;
		}
		if( r == QMessageBox::No){
			guardar = false;
			editorCentral -> clear();
		}
		if ( r == QMessageBox::Cancel ){
			return;
		}
	}
}

void VentanaPrincipal::slotGuardar(void){

	
	if(!fichero->exists()){
		QString ruta = QFileDialog::getSaveFileName(this,QString("Guardar documentillo"));
		delete fichero;
		fichero = new QFile(ruta);
	}
	
	QTextStream stream(fichero);
	if(!fichero->open(QIODevice::WriteOnly)){
		qDebug() << "Algo va mal en el fichero";
		return;
	}

	for(int i = 0; i< editorCentral->document()->blockCount();i++){
	
		stream << editorCentral->document()->findBlockByNumber(i).text() << endl;
	}
	
	guardar = true;
	fichero->close();
	
	
}

void VentanaPrincipal::slotGuardarComo(void){
	
	QString ruta = QFileDialog::getSaveFileName(this,QString("Guardar documentillo"));
	delete fichero;
	fichero = new QFile(ruta);
	
	QTextStream stream(fichero);
	if(!fichero->open(QIODevice::WriteOnly)){
		qDebug() << "Algo va mal en el fichero";
		return;
	}

	for(int i = 0; i< editorCentral->document()->blockCount();i++){
	
		stream << editorCentral->document()->findBlockByNumber(i).text() << endl;
	}
	
	
	guardar = true;
	fichero->close();
}

void VentanaPrincipal::slotComprobar(void){
	
	guardar = false;
}

void VentanaPrincipal::slotMostrarIcono(void){
	QAction * accionRecogida = qobject_cast<QAction*>(sender());

	editorCentral -> append(accionRecogida->text());
}

void VentanaPrincipal::slotCambioEstado(void){
	QTextCursor cursor = editorCentral -> textCursor();

	parrafo->setText("Parrafo: "+QString::number(editorCentral->document()->blockCount()));
	columna->setText("Columna: "+QString::number(cursor.columnNumber()+1));
	fila->setText("Fila: "+QString::number(cursor.blockNumber()+1));
	
}

void VentanaPrincipal::slotEncontrarPalabra(void){
	QTextCursor cursor = editorCentral->document()->find("coche",0);
	QAction * coche = new QAction(this);
	if(!cursor.isNull()){
		
		coche->setIcon(QIcon(":/images/coche.png"));
		barraPrincipal->addAction(coche);
	}else{
		coche->setVisible(false);
	}
}

void VentanaPrincipal::slotAbrir(void){
	qDebug() << "Antes de abrir el dialogo";
	QString ruta = QFileDialog::getOpenFileName(this,QString("abrir documentillo"));
	
	qDebug() << "Fichero: " << ruta;
	
	
	editorCentral ->  clear();
	
	fichero = new QFile(ruta);
	
	if(!fichero->open(QIODevice::ReadOnly)){
		qDebug() << "Algo va mal en el fichero";
		return;
	}
	
	
	
	QTextStream stream(fichero);
	QString linea;
	while (stream.readLineInto(&linea)){
		editorCentral->append(linea);
	}
	
	archivoAbierto = true;
	
	fichero->close();
	
	
	
}

void VentanaPrincipal::closeEvent(QCloseEvent *event){
      if(!guardar && archivoAbierto){
      	slotGuardar();
      	this->close();
      }else{
      	this->close();
      }
      
}

void VentanaPrincipal::slotDialogo(void){
	QString palabra = editorCentral ->textCursor().selectedText();
	DBuscarReemplazar * dialogo = new DBuscarReemplazar(palabra);
	
	dialogo->show();
}

void VentanaPrincipal::slotExamen(void){
	DialogExamen * dialogo1 = new DialogExamen();
	
	dialogo1->show();
}






