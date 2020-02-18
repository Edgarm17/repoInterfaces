######################################################################
# Automatically generated by qmake (3.1) Tue Feb 18 16:48:51 2020
######################################################################

TEMPLATE = app
TARGET = examenBolasPRE
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
           DExamenTab.h \
           DialogInfo.h \
           DTablaPRE.h \
           mainwindow.h \
           PowerUp.h \
           ui_widgetBola.h \
           widgetBola.h \
           WidgetPRE.h
FORMS += DExamenTab.ui \
         DialogInfo.ui \
         DialogoTabla.ui \
         DialogSegon.ui \
         DTablaPRE.ui \
         WidgetPRE.ui
SOURCES += bola.cpp \
           DExamenTab.cpp \
           DialogInfo.cpp \
           DTablaPRE.cpp \
           main.cpp \
           mainwindow.cpp \
           PowerUp.cpp \
           widgetBola.cpp \
           WidgetPRE.cpp
QT += widgets charts
