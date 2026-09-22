
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR


INCLUDEPATH += $$SRC_DIR/libsrc/libijg8 $$SRC_DIR/libsrc/libijg12 $$SRC_DIR/libsrc/libijg16


INCLUDEPATH += $$SRC_GROUP_DIR/ofstd/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcm-config/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmimgle/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmdata/include
INCLUDEPATH += $$SRC_GROUP_DIR/oflog/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/libsrc/libijg12/jchuff12.h \
  $$SRC_DIR/libsrc/libijg12/jconfig12.h \
  $$SRC_DIR/libsrc/libijg12/jdhuff12.h \
  $$SRC_DIR/libsrc/libijg12/jdct12.h \
  $$SRC_DIR/libsrc/libijg12/jerror12.h \
  $$SRC_DIR/libsrc/libijg12/jinclude12.h \
  $$SRC_DIR/libsrc/libijg12/jlossls12.h \
  $$SRC_DIR/libsrc/libijg12/jlossy12.h \
  $$SRC_DIR/libsrc/libijg12/jmemsys12.h \
  $$SRC_DIR/libsrc/libijg12/jmorecfg12.h \
  $$SRC_DIR/libsrc/libijg12/jpegint12.h \
  $$SRC_DIR/libsrc/libijg12/jpeglib12.h \
  $$SRC_DIR/libsrc/libijg12/jversion12.h \



SOURCES += \
  $$SRC_DIR/libsrc/libijg12/jaricom.c \
  $$SRC_DIR/libsrc/libijg12/jcapimin.c \
  $$SRC_DIR/libsrc/libijg12/jcapistd.c \
  $$SRC_DIR/libsrc/libijg12/jcarith.c \
  $$SRC_DIR/libsrc/libijg12/jccoefct.c \
  $$SRC_DIR/libsrc/libijg12/jccolor.c \
  $$SRC_DIR/libsrc/libijg12/jcdctmgr.c \
  $$SRC_DIR/libsrc/libijg12/jcdiffct.c \
  $$SRC_DIR/libsrc/libijg12/jchuff.c \
  $$SRC_DIR/libsrc/libijg12/jcinit.c \
  $$SRC_DIR/libsrc/libijg12/jclhuff.c \
  $$SRC_DIR/libsrc/libijg12/jclossls.c \
  $$SRC_DIR/libsrc/libijg12/jclossy.c \
  $$SRC_DIR/libsrc/libijg12/jcmainct.c \
  $$SRC_DIR/libsrc/libijg12/jcmarker.c \
  $$SRC_DIR/libsrc/libijg12/jcmaster.c \
  $$SRC_DIR/libsrc/libijg12/jcodec.c \
  $$SRC_DIR/libsrc/libijg12/jcomapi.c \
  $$SRC_DIR/libsrc/libijg12/jcparam.c \
  $$SRC_DIR/libsrc/libijg12/jcphuff.c \
  $$SRC_DIR/libsrc/libijg12/jcpred.c \
  $$SRC_DIR/libsrc/libijg12/jcprepct.c \
  $$SRC_DIR/libsrc/libijg12/jcsample.c \
  $$SRC_DIR/libsrc/libijg12/jcscale.c \
  $$SRC_DIR/libsrc/libijg12/jcshuff.c \
  $$SRC_DIR/libsrc/libijg12/jctrans.c \
  $$SRC_DIR/libsrc/libijg12/jdapimin.c \
  $$SRC_DIR/libsrc/libijg12/jdapistd.c \
  $$SRC_DIR/libsrc/libijg12/jdarith.c \
  $$SRC_DIR/libsrc/libijg12/jdatadst.c \
  $$SRC_DIR/libsrc/libijg12/jdatasrc.c \
  $$SRC_DIR/libsrc/libijg12/jdcoefct.c \
  $$SRC_DIR/libsrc/libijg12/jdcolor.c \
  $$SRC_DIR/libsrc/libijg12/jddctmgr.c \
  $$SRC_DIR/libsrc/libijg12/jddiffct.c \
  $$SRC_DIR/libsrc/libijg12/jdhuff.c \
  $$SRC_DIR/libsrc/libijg12/jdinput.c \
  $$SRC_DIR/libsrc/libijg12/jdlhuff.c \
  $$SRC_DIR/libsrc/libijg12/jdlossls.c \
  $$SRC_DIR/libsrc/libijg12/jdlossy.c \
  $$SRC_DIR/libsrc/libijg12/jdmainct.c \
  $$SRC_DIR/libsrc/libijg12/jdmarker.c \
  $$SRC_DIR/libsrc/libijg12/jdmaster.c \
  $$SRC_DIR/libsrc/libijg12/jdmerge.c \
  $$SRC_DIR/libsrc/libijg12/jdphuff.c \
  $$SRC_DIR/libsrc/libijg12/jdpostct.c \
  $$SRC_DIR/libsrc/libijg12/jdpred.c \
  $$SRC_DIR/libsrc/libijg12/jdsample.c \
  $$SRC_DIR/libsrc/libijg12/jdscale.c \
  $$SRC_DIR/libsrc/libijg12/jdshuff.c \
  $$SRC_DIR/libsrc/libijg12/jdtrans.c \
  $$SRC_DIR/libsrc/libijg12/jerror.c \
  $$SRC_DIR/libsrc/libijg12/jfdctflt.c \
  $$SRC_DIR/libsrc/libijg12/jfdctfst.c \
  $$SRC_DIR/libsrc/libijg12/jfdctint.c \
  $$SRC_DIR/libsrc/libijg12/jidctflt.c \
  $$SRC_DIR/libsrc/libijg12/jidctfst.c \
  $$SRC_DIR/libsrc/libijg12/jidctint.c \
  $$SRC_DIR/libsrc/libijg12/jidctred.c \
  $$SRC_DIR/libsrc/libijg12/jmemmgr.c \
  $$SRC_DIR/libsrc/libijg12/jmemnobs.c \
  $$SRC_DIR/libsrc/libijg12/jquant1.c \
  $$SRC_DIR/libsrc/libijg12/jquant2.c \
  $$SRC_DIR/libsrc/libijg12/jutils.c \


#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

