
#           Copyright Nathaniel Christen 2026.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


PROJECT_NAME = dcm2ro-vm-generator-console

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

DEFINES += ROOT_FOLDER=\\\"$$ROOT_DIR\\\"

DEFINES += DEFAULT_VM_FOLDER=\\\"$$ROOT_DIR/../dev/nre/vm\\\"

CONFIG += no_keywords

DEFINES += USE_OTNS


HEADERS += \



SOURCES += \
  $$SRC_DIR/main.cpp \





message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

