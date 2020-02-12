#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *finestra = new MainWindow;
    finestra->show();

	QObject::connect(finestra->dialogProva,SIGNAL(bolaCreada(BolaYWidget*)),finestra,SLOT(slotCrearBola(BolaYWidget*)));


    return app.exec();

	
}


