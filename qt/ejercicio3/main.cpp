#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>

  int main(int argc, char *argv[])
  {
      QApplication app(argc, argv);

      QWidget *window = new QWidget;
      window->setWindowTitle("Enter Your Age");

     QSpinBox *spinBox = new QSpinBox;
     QSlider *slider = new QSlider(Qt::Horizontal);
     QPushButton *buttonMas = new QPushButton("+");
     QPushButton *buttonMenos = new QPushButton("-");
     spinBox->setRange(0, 130);
     slider->setRange(0, 130);

     QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                      slider, SLOT(setValue(int)));
     QObject::connect(slider, SIGNAL(valueChanged(int)),
                      spinBox, SLOT(setValue(int)));
     QObject::connect(buttonMas, SIGNAL(clicked()),
      			spinBox, SLOT(stepUp()));
     QObject::connect(buttonMenos, SIGNAL(clicked()),
      			spinBox, SLOT(stepDown()));
     spinBox->setValue(35);

     QHBoxLayout *layout = new QHBoxLayout;
     layout->addWidget(spinBox);
     layout->addWidget(slider);
     layout->addWidget(buttonMas);
     layout->addWidget(buttonMenos);
     window->setLayout(layout);

     window->show();

     return app.exec();
 }

