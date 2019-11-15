#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QAction>
#include <QMenu>
#include <QLabel>
#include <QFile>

class VentanaPrincipal : public QMainWindow {
Q_OBJECT
public:
        VentanaPrincipal(QWidget * parent = 0, Qt::WindowFlags flags = 0);


private:
        QTextEdit *editorCentral;
        QAction * accionSalir;
        QAction * accionCopiar;
        QAction * accionCortar;
        QAction * accionPegar;
        QAction * accionNuevo;
        QAction * accionGuardar;
        QAction * accion1;
        QAction * accion2;
        QAction * accion3;
        QAction * accionAbrir;
        QAction * accionGuardarComo;
        QAction * accionDialogo;
        QMenu * menuArchivo;
        QMenu * menuEditar;
        QToolBar * barraPrincipal;
        QList<QLabel*> labels;
        QLabel * parrafo;
        QLabel * fila;
        QLabel * columna;
        QFile * fichero;
        QString * nombreFichero;
        void crearBarraEstado();
        void crearQActions();
        void crearMenus();
        void crearBarras();
        void closeEvent(QCloseEvent *event);
        bool guardar;
        bool archivoAbierto;
        
        
public slots:
	void slotCerrar();
	void slotCopiar();
	void slotCortar();
	void slotPegar();
	void slotNuevo();
	void slotComprobar();
	void slotGuardar();
	void slotGuardarComo();
	void slotMostrarIcono();
	void slotCambioEstado();
	void slotEncontrarPalabra();
	void slotAbrir();
	void slotDialogo();
	

};

#endif 
