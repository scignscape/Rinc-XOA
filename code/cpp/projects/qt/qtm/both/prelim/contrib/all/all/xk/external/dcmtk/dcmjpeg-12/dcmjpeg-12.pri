
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR


#INCLUDEPATH += $$SRC_DIR/libsrc/libijg8 $$SRC_DIR/libsrc/libijg12 $$SRC_DIR/libsrc/libijg16


INCLUDEPATH += $$SRC_GROUP_DIR/ofstd/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcm-config/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmimgle/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmdata/include
INCLUDEPATH += $$SRC_GROUP_DIR/oflog/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jchuff12.h \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jconfig12.h \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdhuff12.h \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdct12.h \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jerror12.h \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jinclude12.h \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jlossls12.h \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jlossy12.h \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jmemsys12.h \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jmorecfg12.h \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jpegint12.h \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jpeglib12.h \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jversion12.h \

SOURCES += \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jaricom.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcapimin.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcapistd.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcarith.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jccoefct.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jccolor.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcdctmgr.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcdiffct.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jchuff.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcinit.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jclhuff.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jclossls.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jclossy.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcmainct.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcmarker.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcmaster.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcodec.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcomapi.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcparam.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcphuff.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcpred.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcprepct.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcsample.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcscale.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jcshuff.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jctrans.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdapimin.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdapistd.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdarith.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdatadst.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdatasrc.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdcoefct.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdcolor.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jddctmgr.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jddiffct.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdhuff.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdinput.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdlhuff.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdlossls.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdlossy.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdmainct.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdmarker.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdmaster.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdmerge.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdphuff.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdpostct.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdpred.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdsample.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdscale.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdshuff.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jdtrans.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jerror.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jfdctflt.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jfdctfst.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jfdctint.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jidctflt.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jidctfst.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jidctint.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jidctred.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jmemmgr.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jmemnobs.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jquant1.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jquant2.c \
  $$SRC_GROUP_DIR/dcmjpeg/libijg12/jutils.c \


#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

