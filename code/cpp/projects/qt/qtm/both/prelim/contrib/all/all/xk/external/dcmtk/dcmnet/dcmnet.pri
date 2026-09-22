
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
INCLUDEPATH += $$SRC_GROUP_DIR/dcmimgle/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmdata/include
INCLUDEPATH += $$SRC_GROUP_DIR/oflog/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmtls/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmnet/assoc.h \
  $$SRC_DIR/include/dcmtk/dcmnet/cond.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dcasccff.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dcasccfg.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dccfenmp.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dccfpcmp.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dccfprmp.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dccfrsmp.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dccftsmp.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dccfuidh.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dcmlayer.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dcmsmap.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dcmtrans.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dcompat.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dcuserid.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dfindscu.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dicom.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dimse.h \
  $$SRC_DIR/include/dcmtk/dcmnet/diutil.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dndefine.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dntypes.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dstorscp.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dstorscu.h \
  $$SRC_DIR/include/dcmtk/dcmnet/dul.h \
  $$SRC_DIR/include/dcmtk/dcmnet/extneg.h \
  $$SRC_DIR/include/dcmtk/dcmnet/lst.h \
  $$SRC_DIR/include/dcmtk/dcmnet/scp.h \
  $$SRC_DIR/include/dcmtk/dcmnet/scpcfg.h \
  $$SRC_DIR/include/dcmtk/dcmnet/scppool.h \
  $$SRC_DIR/include/dcmtk/dcmnet/scpthrd.h \
  $$SRC_DIR/include/dcmtk/dcmnet/scu.h \
  $$SRC_DIR/libsrc/dimcmd.h \
  $$SRC_DIR/libsrc/dulfsm.h \
  $$SRC_DIR/libsrc/dulpriv.h \
  $$SRC_DIR/libsrc/dulstruc.h \


SOURCES += \
  $$SRC_DIR/libsrc/assoc.cc \
  $$SRC_DIR/libsrc/cond.cc \
  $$SRC_DIR/libsrc/dcasccff.cc \
  $$SRC_DIR/libsrc/dcasccfg.cc \
  $$SRC_DIR/libsrc/dccfenmp.cc \
  $$SRC_DIR/libsrc/dccfpcmp.cc \
  $$SRC_DIR/libsrc/dccfprmp.cc \
  $$SRC_DIR/libsrc/dccfrsmp.cc \
  $$SRC_DIR/libsrc/dccftsmp.cc \
  $$SRC_DIR/libsrc/dccfuidh.cc \
  $$SRC_DIR/libsrc/dcmlayer.cc \
  $$SRC_DIR/libsrc/dcmtrans.cc \
  $$SRC_DIR/libsrc/dcompat.cc \
  $$SRC_DIR/libsrc/dcuserid.cc \
  $$SRC_DIR/libsrc/dfindscu.cc \
  $$SRC_DIR/libsrc/dimcancl.cc \
  $$SRC_DIR/libsrc/dimcmd.cc \
  $$SRC_DIR/libsrc/dimdump.cc \
  $$SRC_DIR/libsrc/dimecho.cc \
  $$SRC_DIR/libsrc/dimfind.cc \
  $$SRC_DIR/libsrc/dimget.cc \
  $$SRC_DIR/libsrc/dimmove.cc \
  $$SRC_DIR/libsrc/dimse.cc \
  $$SRC_DIR/libsrc/dimstore.cc \
  $$SRC_DIR/libsrc/diutil.cc \
  $$SRC_DIR/libsrc/dstorscp.cc \
  $$SRC_DIR/libsrc/dstorscu.cc \
  $$SRC_DIR/libsrc/dul.cc \
  $$SRC_DIR/libsrc/dulconst.cc \
  $$SRC_DIR/libsrc/dulextra.cc \
  $$SRC_DIR/libsrc/dulfsm.cc \
  $$SRC_DIR/libsrc/dulparse.cc \
  $$SRC_DIR/libsrc/dulpres.cc \
  $$SRC_DIR/libsrc/dwrap.c \
  $$SRC_DIR/libsrc/extneg.cc \
  $$SRC_DIR/libsrc/lst.cc \
  $$SRC_DIR/libsrc/scp.cc \
  $$SRC_DIR/libsrc/scpcfg.cc \
  $$SRC_DIR/libsrc/scppool.cc \
  $$SRC_DIR/libsrc/scpthrd.cc \
  $$SRC_DIR/libsrc/scu.cc \


#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

