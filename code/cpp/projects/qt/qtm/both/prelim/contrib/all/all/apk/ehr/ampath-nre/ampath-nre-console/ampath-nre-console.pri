
#           Copyright Nathaniel Christen 2026.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


PROJECT_NAME = ampath-nre-console

QT += widgets

include(../build-group.pri)

greaterThan(QT_MAJOR_VERSION, 5) {
 DEFINES += USING_QT_6
}

TEMPLATE = app


exists($$ROOT_DIR/../preferred/sysr.pri): include($$ROOT_DIR/../preferred/sysr.pri)
exists($$ROOT_DIR/../preferred/sysr-c.pri): include($$ROOT_DIR/../preferred/sysr-c.pri)
exists($$ROOT_DIR/../preferred/compiler.pri): include($$ROOT_DIR/../preferred/compiler.pri)


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR $$SRC_ROOT_DIR


CONFIG += no_keywords

DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"


HEADERS += \
  $$SRC_DIR/vm/qynviper-json-vm.h \



SOURCES += \
  $$SRC_DIR/main.cpp \
  $$SRC_DIR/vm/qynviper-json-vm.cpp \





message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

