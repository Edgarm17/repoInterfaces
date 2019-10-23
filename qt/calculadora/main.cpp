#include <QApplication>

 #include "calculadora.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     Calculadora *calc = new Calculadora();
     
     
     return app.exec();
}
