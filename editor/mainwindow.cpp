#include "mainwindow.h"
#include <QStatusBar>
#include <QMenuBar>
#include <QMessageBox>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QLabel>


VentanaPrincipal::VentanaPrincipal(QWidget * parent ,Qt::WindowFlags flags ) : QMainWindow(parent,flags) {

	guardar = false;
        editorCentral = new QTextEdit(this);
        setCentralWidget(editorCentral);
        crearQActions();
        
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
        
        accion1 = new QAction("icon",this);
        accion1->setIcon(QIcon(":/images/icon.png"));
        
        accion2 = new QAction("new",this);
        accion2->setIcon(QIcon(":/images/new.png"));
        
        accion3 = new QAction("cara",this);
        accion3->setIcon(QIcon(":/images/cara.png"));
        
        
        
        
        
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
        
        
        
}

void VentanaPrincipal::crearMenus(){

	menuArchivo = menuBar()->addMenu("Archivo");
        menuArchivo ->addAction(accionSalir);
        menuArchivo ->addAction(accionNuevo);
        menuArchivo -> addAction(accionGuardar);
        
        menuEditar = menuBar()->addMenu("Editar");
	menuEditar->addAction(accionCopiar);
	menuEditar->addAction(accionCortar);
	menuEditar->addAction(accionPegar);
	
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
	

	this -> close();
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
	guardar = true;
	
	
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






