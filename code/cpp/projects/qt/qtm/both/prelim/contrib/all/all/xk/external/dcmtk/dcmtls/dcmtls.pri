
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_DIR/include

INCLUDEPATH += $$SRC_GROUP_DIR/ofstd/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcm-config/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmnet/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmdata/include
INCLUDEPATH += $$SRC_GROUP_DIR/oflog/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmtls/tlsciphr.h \
  $$SRC_DIR/include/dcmtk/dcmtls/tlscond.h \
  $$SRC_DIR/include/dcmtk/dcmtls/tlsdefin.h \
  $$SRC_DIR/include/dcmtk/dcmtls/tlslayer.h \
  $$SRC_DIR/include/dcmtk/dcmtls/tlsopt.h \
  $$SRC_DIR/include/dcmtk/dcmtls/tlsscu.h \
  $$SRC_DIR/include/dcmtk/dcmtls/tlstrans.h \


SOURCES += \
  $$SRC_DIR/libsrc/tlsciphr.cc \
  $$SRC_DIR/libsrc/tlscond.cc \
  $$SRC_DIR/libsrc/tlslayer.cc \
  $$SRC_DIR/libsrc/tlsopt.cc \
  $$SRC_DIR/libsrc/tlsscu.cc \
  $$SRC_DIR/libsrc/tlstrans.cc \




#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

