#include <QApplication>

 #include "mainDialog.h"
 #include "findDialog.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     MainDialog *probador = new MainDialog();
     FindDialog *dialog = new FindDialog();
     dialog->show();
     probador->show();
     
     //Al declarar els connect en el main, hi ha que llevar els noms del parametres
     QObject::connect(dialog, SIGNAL(findNext(const QString &, Qt::CaseSensitivity )),
     probador,SLOT(slotFordward(const QString &, Qt::CaseSensitivity ))); 
     
     QObject::connect(dialog, SIGNAL(findPrevious(const QString &, 			Qt::CaseSensitivity )),
     probador,SLOT(slotBackward(const QString &, Qt::CaseSensitivity ))); 
     
     return app.exec();
}
