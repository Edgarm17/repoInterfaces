######################################################################
# Automatically generated by qmake (3.1) Fri Jan 31 13:24:11 2020
######################################################################

TEMPLATE = app
TARGET = bolasTreeView
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += bola.h \
           DChartColisiones.h \
           DControlBolas.h \
           DExamenDAM.h \
           DialogoTabla.h \
           DTreeView.h \
           InfoDialog.h \
           mainwindow.h \
           PowerUp.h \
           widgetBola.h
FORMS += DChartColisiones.ui \
         DControlBolas.ui \
         DExamenDAM.ui \
         DialogoTabla.ui \
         DTreeView.ui \
         InfoDialog.ui \
         widgetBola.ui
SOURCES += bola.cpp \
           DChartColisiones.cpp \
           DControlBolas.cpp \
           DExamenDAM.cpp \
           DialogoTabla.cpp \
           DTreeView.cpp \
           InfoDialog.cpp \
           main.cpp \
           mainwindow.cpp \
           PowerUp.cpp \
           widgetBola.cpp
QT += widgets charts
