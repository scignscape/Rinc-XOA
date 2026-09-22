
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_DIR/include
INCLUDEPATH += $$SRC_DIR/libsrc/libcharls/

INCLUDEPATH += $$SRC_GROUP_DIR/ofstd/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcm-config/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmimgle/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmdata/include
INCLUDEPATH += $$SRC_GROUP_DIR/oflog/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmjpls/djcodecd.h \
  $$SRC_DIR/include/dcmtk/dcmjpls/djcodece.h \
  $$SRC_DIR/include/dcmtk/dcmjpls/djcparam.h \
  $$SRC_DIR/include/dcmtk/dcmjpls/djdecode.h \
  $$SRC_DIR/include/dcmtk/dcmjpls/djencode.h \
  $$SRC_DIR/include/dcmtk/dcmjpls/djlsutil.h \
  $$SRC_DIR/include/dcmtk/dcmjpls/djrparam.h \
  $$SRC_DIR/include/dcmtk/dcmjpls/dldefine.h \
  $$SRC_DIR/libsrc/djerror.h \
  $$SRC_DIR/libsrc/libcharls/clrtrans.h \
  $$SRC_DIR/libsrc/libcharls/config.h \
  $$SRC_DIR/libsrc/libcharls/context.h \
  $$SRC_DIR/libsrc/libcharls/ctxtrmod.h \
  $$SRC_DIR/libsrc/libcharls/decodstr.h \
  $$SRC_DIR/libsrc/libcharls/deftrait.h \
  $$SRC_DIR/libsrc/libcharls/encodstr.h \
  $$SRC_DIR/libsrc/libcharls/header.h \
  $$SRC_DIR/libsrc/libcharls/intrface.h \
  $$SRC_DIR/libsrc/libcharls/lltraits.h \
  $$SRC_DIR/libsrc/libcharls/lokuptbl.h \
  $$SRC_DIR/libsrc/libcharls/procline.h \
  $$SRC_DIR/libsrc/libcharls/pubtypes.h \
  $$SRC_DIR/libsrc/libcharls/scan.h \
  $$SRC_DIR/libsrc/libcharls/streams.h \
  $$SRC_DIR/libsrc/libcharls/util.h \


SOURCES += \
  $$SRC_DIR/libsrc/djcodecd.cc \
  $$SRC_DIR/libsrc/djcodece.cc \
  $$SRC_DIR/libsrc/djcparam.cc \
  $$SRC_DIR/libsrc/djdecode.cc \
  $$SRC_DIR/libsrc/djencode.cc \
  $$SRC_DIR/libsrc/djrparam.cc \
  $$SRC_DIR/libsrc/djutils.cc \
  $$SRC_DIR/libsrc/libcharls/header.cc \
  $$SRC_DIR/libsrc/libcharls/intrface.cc \
  $$SRC_DIR/libsrc/libcharls/jpegls.cc \

#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

