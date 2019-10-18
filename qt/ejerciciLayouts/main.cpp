#include <QApplication>

 #include "layouts.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     Layout *ventana = new Layout;
     ventana->show();
     
     return app.exec();
}
