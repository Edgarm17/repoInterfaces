
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QAction>
#include <QLabel>
class VentanaPrincipal : public QMainWindow {
Q_OBJECT
public:
        VentanaPrincipal(QWidget * parent = 0, Qt::WindowFlags flags = 0);


private:
	QAction *accionSalir,
		*accionPegar,
		*accionCortar,
		*accionCopiar;
	QAction *accionGuardar;
	QAction *accionAbrir;
	QAction *accionNuevo;
	QLabel  *etiquetaEstado;
	QAction *accionBuscarReemplazar;

	QAction *accCara,*accCruz, *accCanto;

	bool hayCambios;

        QTextEdit *editorCentral;
	void crearAcciones();
	void crearMenus();
	void crearBarrasHerramientas();
	void crearBarraEstado();
	void closeEvent(QCloseEvent *event);
   
public slots:
	void slotCerrar();
	void slotCopiar();
	void slotCortar();
	void slotPegar();

	void slotNuevo();
	void slotGuardar();
	void slotTextoCambiado();
	void slotCambioEstado();
	void slotAbrir();
	void slotBuscarReemplazar();

	void slotAnyadirTexto();
};


#endif 

