
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
INCLUDEPATH += $$SRC_GROUP_DIR/dcmdata/include
INCLUDEPATH += $$SRC_GROUP_DIR/oflog/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmnet/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmqrdb/dcmqrcbf.h \
  $$SRC_DIR/include/dcmtk/dcmqrdb/dcmqrcbg.h \
  $$SRC_DIR/include/dcmtk/dcmqrdb/dcmqrcbm.h \
  $$SRC_DIR/include/dcmtk/dcmqrdb/dcmqrcbs.h \
  $$SRC_DIR/include/dcmtk/dcmqrdb/dcmqrcnf.h \
  $$SRC_DIR/include/dcmtk/dcmqrdb/dcmqrdba.h \
  $$SRC_DIR/include/dcmtk/dcmqrdb/dcmqrdbi.h \
  $$SRC_DIR/include/dcmtk/dcmqrdb/dcmqrdbs.h \
  $$SRC_DIR/include/dcmtk/dcmqrdb/dcmqridx.h \
  $$SRC_DIR/include/dcmtk/dcmqrdb/dcmqropt.h \
  $$SRC_DIR/include/dcmtk/dcmqrdb/dcmqrptb.h \
  $$SRC_DIR/include/dcmtk/dcmqrdb/dcmqrsrv.h \
  $$SRC_DIR/include/dcmtk/dcmqrdb/dcmqrtis.h \
  $$SRC_DIR/include/dcmtk/dcmqrdb/qrdefine.h \


SOURCES += \
  $$SRC_DIR/libsrc/dcmqrcbf.cc \
  $$SRC_DIR/libsrc/dcmqrcbg.cc \
  $$SRC_DIR/libsrc/dcmqrcbm.cc \
  $$SRC_DIR/libsrc/dcmqrcbs.cc \
  $$SRC_DIR/libsrc/dcmqrcnf.cc \
  $$SRC_DIR/libsrc/dcmqrdbi.cc \
  $$SRC_DIR/libsrc/dcmqrdbs.cc \
  $$SRC_DIR/libsrc/dcmqropt.cc \
  $$SRC_DIR/libsrc/dcmqrptb.cc \
  $$SRC_DIR/libsrc/dcmqrsrv.cc \
  $$SRC_DIR/libsrc/dcmqrtis.cc \

#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

