TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        disparo_defensivo.cpp \
        disparo_ofensivo.cpp \
        main.cpp

HEADERS += \
    Funciones.h \
    disparo_defensivo.h \
    disparo_ofensivo.h \
    neutralizacion.h
