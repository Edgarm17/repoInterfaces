#include <QApplication>

 #include "findDialog.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     FindDialog *dialog = new FindDialog;
     dialog->esteMetodo(8);
     dialog->show();
     return app.exec();
}
