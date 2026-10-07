
#           Copyright Nathaniel Christen 2026.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


PROJECT_NAME = dcm2ro-vm

include(../build-group.pri)

QT -= gui

exists($$ROOT_DIR/../preferred/sysr.pri): include($$ROOT_DIR/../preferred/sysr.pri)
exists($$ROOT_DIR/../preferred/sysr-c.pri): include($$ROOT_DIR/../preferred/sysr-c.pri)
exists($$ROOT_DIR/../preferred/compiler.pri): include($$ROOT_DIR/../preferred/compiler.pri)


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR $$SRC_ROOT_DIR

greaterThan(QT_MAJOR_VERSION, 5) {
 DEFINES += USING_QT_6
 DEFINES += QVList=QList
} else {
 DEFINES += QVList=QVector
}

CONFIG += debug

CONFIG += no_keywords

CONFIG+=c++2a

DEFINES += USE_OTNS
DEFINES += USE_KANS

HEADERS += \
  $$SRC_DIR/vm-interpreter.h \
  $$SRC_DIR/vm-opmethods.h \
  $$SRC_DIR/vm-dispatcher.h \
  $$SRC_DIR/vm-reader.h \
  $$SRC_DIR/vm-opstatement.h \
  $$SRC_DIR/modules/module-macros.h \
  $$SRC_DIR/modules/module-base.h \
  $$SRC_DIR/modules/implementations/asa-module.h \
  $$SRC_DIR/modules/implementations/kim-module.h \
  $$SRC_DIR/modules/implementations/tia-module.h \
  $$SRC_DIR/modules/implementations/tia-module/tia-compound-graphic.h \
  $$SRC_DIR/modules/implementations/tia-module/tia-fill-pattern.h \
  $$SRC_DIR/modules/implementations/tia-module/tia-graphic-fill-style.h \
  $$SRC_DIR/modules/implementations/tia-module/tia-graphic-layer.h \


SOURCES += \
  $$SRC_DIR/vm-interpreter.cpp \
  $$SRC_DIR/vm-opmethods.cpp \
  $$SRC_DIR/vm-dispatcher.cpp \
  $$SRC_DIR/vm-reader.cpp \
  $$SRC_DIR/vm-opstatement.cpp \
  $$SRC_DIR/modules/implementations/asa-module.cpp \
  $$SRC_DIR/modules/implementations/kim-module.cpp \
  $$SRC_DIR/modules/implementations/tia-module.cpp \
  $$SRC_DIR/modules/implementations/tia-module/tia-compound-graphic.cpp \
  $$SRC_DIR/modules/implementations/tia-module/tia-fill-pattern.cpp \
  $$SRC_DIR/modules/implementations/tia-module/tia-graphic-fill-style.cpp \
  $$SRC_DIR/modules/implementations/tia-module/tia-graphic-layer.cpp \



DISTFILES += \
  $$SRC_DIR/modules/implementations/asa-module.cxx \
  $$SRC_DIR/modules/implementations/kim-module.cxx \
  $$SRC_DIR/modules/implementations/tia-module.cxx \



message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

