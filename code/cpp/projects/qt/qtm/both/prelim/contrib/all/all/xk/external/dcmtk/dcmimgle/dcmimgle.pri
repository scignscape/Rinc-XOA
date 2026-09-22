
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
  $$SRC_DIR/include/dcmtk/dcmimgle/dcmimage.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dibaslut.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diciefn.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dicielut.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dicrvfit.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/didefine.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/didislut.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/didispfn.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/didocu.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diflipt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/digsdfn.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/digsdlut.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diimage.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diinpx.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diinpxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diluptab.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimo1img.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimo2img.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimocpt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimoflt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimoimg.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimoipxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimomod.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimoopx.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimoopxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimopx.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimopxt.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimorot.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dimosct.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diobjcou.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diovdat.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diovlay.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diovlimg.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diovpln.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dipixel.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diplugin.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dipxrept.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diregbas.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/dirotat.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/discalet.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/displint.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/ditranst.h \ 
  $$SRC_DIR/include/dcmtk/dcmimgle/diutils.h \ 


SOURCES += \
  $$SRC_DIR/libsrc/dcmimage.cc \ 
  $$SRC_DIR/libsrc/dibaslut.cc \ 
  $$SRC_DIR/libsrc/diciefn.cc \ 
  $$SRC_DIR/libsrc/dicielut.cc \ 
  $$SRC_DIR/libsrc/didislut.cc \ 
  $$SRC_DIR/libsrc/didispfn.cc \ 
  $$SRC_DIR/libsrc/didocu.cc \ 
  $$SRC_DIR/libsrc/digsdfn.cc \ 
  $$SRC_DIR/libsrc/digsdlut.cc \ 
  $$SRC_DIR/libsrc/diimage.cc \ 
  $$SRC_DIR/libsrc/diinpx.cc \ 
  $$SRC_DIR/libsrc/diluptab.cc \ 
  $$SRC_DIR/libsrc/dimo1img.cc \ 
  $$SRC_DIR/libsrc/dimo2img.cc \ 
  $$SRC_DIR/libsrc/dimoimg.cc \ 
  $$SRC_DIR/libsrc/dimoimg3.cc \ 
  $$SRC_DIR/libsrc/dimoimg4.cc \ 
  $$SRC_DIR/libsrc/dimoimg5.cc \ 
  $$SRC_DIR/libsrc/dimomod.cc \ 
  $$SRC_DIR/libsrc/dimoopx.cc \ 
  $$SRC_DIR/libsrc/dimopx.cc \ 
  $$SRC_DIR/libsrc/diovdat.cc \ 
  $$SRC_DIR/libsrc/diovlay.cc \ 
  $$SRC_DIR/libsrc/diovlimg.cc \ 
  $$SRC_DIR/libsrc/diovpln.cc \ 
  $$SRC_DIR/libsrc/diutils.cc \ 


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

