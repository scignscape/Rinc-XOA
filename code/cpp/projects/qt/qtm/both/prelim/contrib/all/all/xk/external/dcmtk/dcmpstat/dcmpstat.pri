
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
INCLUDEPATH += $$SRC_GROUP_DIR/dcmqrdb/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmnet/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmimgle/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmsign/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmsr/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmtls/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmpstat/dcmpstat.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dpdefine.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvcache.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dviface.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsab.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsabl.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsal.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsall.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpscf.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpscu.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpscul.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsda.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsdal.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsdef.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsfs.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsga.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsgal.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsgl.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsgll.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsgr.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsgrl.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpshlp.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsib.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsibl.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsmsg.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsov.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsovl.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpspl.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpspll.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpspr.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsprt.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsri.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsril.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsrs.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsrsl.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpssp.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsspl.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpssv.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpssvl.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpstat.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpstx.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpstxl.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpstyp.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsvl.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsvll.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsvw.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvpsvwl.h \
  $$SRC_DIR/include/dcmtk/dcmpstat/dvsighdl.h \


SOURCES += \
  $$SRC_DIR/libsrc/dcmpstat.cc \
  $$SRC_DIR/libsrc/dviface.cc \
  $$SRC_DIR/libsrc/dvpsab.cc \
  $$SRC_DIR/libsrc/dvpsabl.cc \
  $$SRC_DIR/libsrc/dvpsal.cc \
  $$SRC_DIR/libsrc/dvpsall.cc \
  $$SRC_DIR/libsrc/dvpscf.cc \
  $$SRC_DIR/libsrc/dvpscu.cc \
  $$SRC_DIR/libsrc/dvpscul.cc \
  $$SRC_DIR/libsrc/dvpsda.cc \
  $$SRC_DIR/libsrc/dvpsdal.cc \
  $$SRC_DIR/libsrc/dvpsfs.cc \
  $$SRC_DIR/libsrc/dvpsga.cc \
  $$SRC_DIR/libsrc/dvpsgal.cc \
  $$SRC_DIR/libsrc/dvpsgl.cc \
  $$SRC_DIR/libsrc/dvpsgll.cc \
  $$SRC_DIR/libsrc/dvpsgr.cc \
  $$SRC_DIR/libsrc/dvpsgrl.cc \
  $$SRC_DIR/libsrc/dvpshlp.cc \
  $$SRC_DIR/libsrc/dvpsib.cc \
  $$SRC_DIR/libsrc/dvpsibl.cc \
  $$SRC_DIR/libsrc/dvpsmsg.cc \
  $$SRC_DIR/libsrc/dvpsov.cc \
  $$SRC_DIR/libsrc/dvpsovl.cc \
  $$SRC_DIR/libsrc/dvpspl.cc \
  $$SRC_DIR/libsrc/dvpspl2.cc \
  $$SRC_DIR/libsrc/dvpspll.cc \
  $$SRC_DIR/libsrc/dvpspr.cc \
  $$SRC_DIR/libsrc/dvpsprt.cc \
  $$SRC_DIR/libsrc/dvpsri.cc \
  $$SRC_DIR/libsrc/dvpsril.cc \
  $$SRC_DIR/libsrc/dvpsrs.cc \
  $$SRC_DIR/libsrc/dvpsrsl.cc \
  $$SRC_DIR/libsrc/dvpssp.cc \
  $$SRC_DIR/libsrc/dvpsspl.cc \
  $$SRC_DIR/libsrc/dvpssv.cc \
  $$SRC_DIR/libsrc/dvpssvl.cc \
  $$SRC_DIR/libsrc/dvpstat.cc \
  $$SRC_DIR/libsrc/dvpstx.cc \
  $$SRC_DIR/libsrc/dvpstxl.cc \
  $$SRC_DIR/libsrc/dvpsvl.cc \
  $$SRC_DIR/libsrc/dvpsvll.cc \
  $$SRC_DIR/libsrc/dvpsvw.cc \
  $$SRC_DIR/libsrc/dvpsvwl.cc \
  $$SRC_DIR/libsrc/dvsighdl.cc \

#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

