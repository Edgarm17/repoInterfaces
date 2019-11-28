#include "mainwindow.h"
#include <QStatusBar>
#include <QMenuBar>
#include <QMessageBox>
#include <QAction>
#include <QApplication>
#include <QDebug>
#include <QMenu>
#include <QToolBar>
#include <QLabel>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTextBlock>

#include "DBuscarReemplazar.h"

VentanaPrincipal::VentanaPrincipal(
        QWidget * parent ,
        Qt::WindowFlags flags ) : QMainWindow(parent,flags) {

	hayCambios = false;

        editorCentral = new QTextEdit(this);
	connect(editorCentral,SIGNAL(textChanged()),
		this, SLOT(slotTextoCambiado()));

	connect(editorCentral,SIGNAL(cursorPositionChanged()),
	this,SLOT(slotCambioEstado()));
connect(editorCentral,SIGNAL(textChanged()),
	this,SLOT(slotCambioEstado()));


        setCentralWidget(editorCentral);
	crearAcciones();
	crearMenus();
	crearBarrasHerramientas();
	crearBarraEstado();

    setWindowIcon(QIcon(":/images/carita.png"));
	hayCambios = false;
}

void VentanaPrincipal::crearAcciones(){

//	QAction accionSalir("tanca",this);
	accionSalir = new QAction("tanca",this);
	accionSalir->setShortcut(QKeySequence::Close);
	connect(accionSalir, SIGNAL(triggered()),
		this, SLOT(slotCerrar()));

	accionGuardar = new QAction("Guarda",this);
	accionGuardar->setShortcut(QKeySequence::Save);
	connect(accionGuardar, SIGNAL(triggered()),
		this, SLOT(slotGuardar()));

	accionNuevo = new QAction("Nuevo",this);
	accionNuevo->setShortcut(QKeySequence::New);
	connect(accionNuevo, SIGNAL(triggered()),
		this, SLOT(slotNuevo()));


	accionCopiar = new QAction("copiar",this);
	accionCopiar->setShortcut(QKeySequence::Copy);
	connect(accionCopiar, SIGNAL(triggered()),
		this, SLOT(slotCopiar()));

	accionPegar = new QAction("pegar",this);
	accionPegar->setShortcut(QKeySequence::Paste);
	connect(accionPegar, SIGNAL(triggered()),
		this, SLOT(slotPegar()));

	//cortar
	accionCortar = new QAction("cortar",this);
	accionCortar->setShortcut(QKeySequence::Cut);
	connect(accionCortar, SIGNAL(triggered()),
		this, SLOT(slotCortar()));

	accCara = new QAction("Cara",this);
	accCruz =new QAction("Cruz",this);
	accCanto = new QAction("Canto",this);


	accionAbrir = new QAction("Abrir Archivo",this);
	accionAbrir->setShortcut(QKeySequence::Open);
	connect(accionAbrir,SIGNAL(triggered()),
		this, SLOT(slotAbrir()));

	accionBuscarReemplazar = new QAction("Buscar y reemplazar",this);
	connect(accionBuscarReemplazar,SIGNAL(triggered()),
		this, SLOT(slotBuscarReemplazar()));



connect(accCruz, SIGNAL(triggered()),
		this, SLOT(slotAnyadirTexto()));

connect(accCanto, SIGNAL(triggered()),
		this, SLOT(slotAnyadirTexto()));

connect(accCara, SIGNAL(triggered()),
		this, SLOT(slotAnyadirTexto()));


}
void VentanaPrincipal::crearMenus(){

	QMenu *menuArchivo;
	menuArchivo = menuBar()->addMenu("Archivo");
	menuArchivo->addAction(accionGuardar);
	menuArchivo->addAction(accionAbrir);
	menuArchivo->addAction(accionNuevo);
	menuArchivo->addAction(accionSalir);


	QMenu *menuEditar;
	menuArchivo = menuBar()->addMenu("Editar");
	menuArchivo->addAction(accionCortar);
	menuArchivo->addAction(accionPegar);
	menuArchivo->addAction(accionCopiar);
	menuArchivo->addAction(accionBuscarReemplazar);

	editorCentral->addAction(accionNuevo);
editorCentral->setContextMenuPolicy(Qt::ActionsContextMenu);

}

void VentanaPrincipal::crearBarrasHerramientas() {
	QToolBar *barraPrincipal;

	barraPrincipal = this->addToolBar("Prinsipa");
	barraPrincipal->addAction(accionNuevo);

	barraPrincipal->addAction(accCara);

}
void VentanaPrincipal::crearBarraEstado() {

	etiquetaEstado = new QLabel("");

	statusBar()->addWidget(etiquetaEstado);

}


void VentanaPrincipal::slotCopiar( void ) {



}
void VentanaPrincipal::slotCortar( void ) {

}
void VentanaPrincipal::slotPegar( void ) {

}

void VentanaPrincipal::slotNuevo( void ) {


  int r = QMessageBox::warning(this,
 	 tr("EditorClase"),
  	 tr("The document has been modified.\n"
           "Do you want to save your changes?"),
            QMessageBox::Yes | QMessageBox::No
            | QMessageBox::Cancel);

   if (r == QMessageBox::Yes )  editorCentral->clear();
   if (r == QMessageBox::Cancel ) return;
   if (r == QMessageBox::No ) return;
}
void VentanaPrincipal::slotGuardar( void ) {

	QString titulo("Guardar un documentillo");

	QString rutaFichero;
	rutaFichero = QFileDialog::getSaveFileName(this,titulo);

	if (rutaFichero.isEmpty() ) return;


	QFile fichero(rutaFichero);

	if (! fichero.open( QIODevice::WriteOnly) ) {
		qDebug()<< "Algo va mal con el fichero ";
		return;
	}

	QTextStream stream(&fichero);
	for(int i=0;
	 i< editorCentral->document()->blockCount();
	i++)
		stream << editorCentral->document()->findBlockByNumber(i).text() << endl;

	
fichero.close();
	
	hayCambios = false;
}
void VentanaPrincipal::slotTextoCambiado( void ) {
	hayCambios = true;
}


void VentanaPrincipal::closeEvent(QCloseEvent *event){
	
	event->accept();
	return;
	qDebug() << "closeEvent" ;

	if (hayCambios) slotGuardar();


	event->ignore();

	


}
void VentanaPrincipal::slotCerrar( void ) {
//	this -> close();
	qDebug() << "Error" ;

	if (hayCambios) slotGuardar();


	QApplication::exit();

	
	
}

void VentanaPrincipal::slotAnyadirTexto(void) {


QAction * culpable = qobject_cast<QAction * >( sender());

	QString texto = culpable->text();
	editorCentral->append(texto);
}

void VentanaPrincipal::slotCambioEstado(){

 QString texto("");
 int numParrafos = editorCentral->document()->blockCount();
 texto = QString("parrafos: ") + QString::number(numParrafos);
	
 int col = editorCentral->textCursor().columnNumber();
 texto = texto + QString("columna ")+ QString::number(col);

 int fil = editorCentral->textCursor().blockNumber();
 texto = texto + QString(" fila ")+ QString::number(fil);

	etiquetaEstado->setText(texto);
}

void VentanaPrincipal::slotAbrir(){
	
	QString titulo("abrir un documentillo");
	qDebug() << "Antes de abrir el diálogo" ;

	QString rutaFichero;
	rutaFichero = QFileDialog::getOpenFileName(this,titulo);
	qDebug() << "Fichero = " << rutaFichero;

	if (rutaFichero.isEmpty() ) return;

	editorCentral->clear();

	QFile fichero(rutaFichero);

	if (! fichero.open( QIODevice::ReadOnly) ) {

		qDebug()<< "Algo va mal con el fichero ";
		return;
	}

	QTextStream stream(&fichero);
	while (! stream.atEnd())
		editorCentral->append(stream.readLine());

	fichero.close();
	

}


void VentanaPrincipal::slotBuscarReemplazar(){

 QString palabra = editorCentral-> 	
		textCursor().selectedText();

 DBuscarReemplazar *d = 
		new DBuscarReemplazar(palabra);;

	d->show();
	qDebug() << "estoy aquí"<< endl;


}




