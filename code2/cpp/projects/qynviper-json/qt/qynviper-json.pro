
QT += widgets


DEFINES += QString_null=QString{}

SRC_ROOT = ../../../src/prelim/qynviper-json

INCLUDEPATH += ../../../src/prelim


SOURCES += $$SRC_ROOT/main.cpp



HEADERS += \
  $$SRC_ROOT/vm/qynviper-json-vm.h \



SOURCES += \
  $$SRC_ROOT/vm/qynviper-json-vm.cpp \


DESTDIR = ../dest



