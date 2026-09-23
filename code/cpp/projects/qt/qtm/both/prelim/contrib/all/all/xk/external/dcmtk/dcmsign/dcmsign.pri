
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




DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmsign/dcsignat.h
  $$SRC_DIR/include/dcmtk/dcmsign/sialgo.h
  $$SRC_DIR/include/dcmtk/dcmsign/siautopr.h
  $$SRC_DIR/include/dcmtk/dcmsign/sibrsapr.h
  $$SRC_DIR/include/dcmtk/dcmsign/sicert.h
  $$SRC_DIR/include/dcmtk/dcmsign/sicertvf.h
  $$SRC_DIR/include/dcmtk/dcmsign/sicreapr.h
  $$SRC_DIR/include/dcmtk/dcmsign/sidefine.h
  $$SRC_DIR/include/dcmtk/dcmsign/sidsa.h
  $$SRC_DIR/include/dcmtk/dcmsign/simac.h
  $$SRC_DIR/include/dcmtk/dcmsign/simaccon.h
  $$SRC_DIR/include/dcmtk/dcmsign/simd5.h
  $$SRC_DIR/include/dcmtk/dcmsign/sinullpr.h
  $$SRC_DIR/include/dcmtk/dcmsign/siprivat.h
  $$SRC_DIR/include/dcmtk/dcmsign/siripemd.h
  $$SRC_DIR/include/dcmtk/dcmsign/sirsa.h
  $$SRC_DIR/include/dcmtk/dcmsign/sisha1.h
  $$SRC_DIR/include/dcmtk/dcmsign/sisha256.h
  $$SRC_DIR/include/dcmtk/dcmsign/sisha384.h
  $$SRC_DIR/include/dcmtk/dcmsign/sisha512.h
  $$SRC_DIR/include/dcmtk/dcmsign/sisprof.h
  $$SRC_DIR/include/dcmtk/dcmsign/sitstamp.h
  $$SRC_DIR/include/dcmtk/dcmsign/sitypes.h


SOURCES += \
  $$SRC_DIR/libsrc/dcsignat.cc \
  $$SRC_DIR/libsrc/siautopr.cc \
  $$SRC_DIR/libsrc/sibrsapr.cc \
  $$SRC_DIR/libsrc/sicert.cc \
  $$SRC_DIR/libsrc/sicertvf.cc \
  $$SRC_DIR/libsrc/sicreapr.cc \
  $$SRC_DIR/libsrc/sidsa.cc \
  $$SRC_DIR/libsrc/simaccon.cc \
  $$SRC_DIR/libsrc/simd5.cc \
  $$SRC_DIR/libsrc/sinullpr.cc \
  $$SRC_DIR/libsrc/siprivat.cc \
  $$SRC_DIR/libsrc/siripemd.cc \
  $$SRC_DIR/libsrc/sirsa.cc \
  $$SRC_DIR/libsrc/sisha1.cc \
  $$SRC_DIR/libsrc/sisha256.cc \
  $$SRC_DIR/libsrc/sisha384.cc \
  $$SRC_DIR/libsrc/sisha512.cc \
  $$SRC_DIR/libsrc/sisprof.cc \
  $$SRC_DIR/libsrc/sitypes.cc \


#LIBS += -L$$TARGETSDIR

 # in preferred? 
LIBS += -lssl

message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

