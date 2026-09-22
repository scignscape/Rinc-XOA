
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
INCLUDEPATH += $$SRC_GROUP_DIR/dcmiod/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmfg/concatenationcreator.h \
  $$SRC_DIR/include/dcmtk/dcmfg/concatenationloader.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fg.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgbase.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctacquisitiondetails.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctacquisitiontype.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctadditionalxraysource.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctexposure.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctgeometry.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctimageframetype.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctposition.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctreconstruction.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgcttabledynamics.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgctxraydetails.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgdefine.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgderimg.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgfact.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgfracon.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgframeanatomy.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgframevoilut.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgimagedatatype.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fginterface.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgirradiationeventid.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgparametricmapframetype.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgpixeltransform.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgpixmsr.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgplanor.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgplanorvol.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgplanpo.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgplanposvol.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgrealworldvaluemapping.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgseg.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgtemporalposition.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgtypes.h \
  $$SRC_DIR/include/dcmtk/dcmfg/fgusimagedescription.h \
  $$SRC_DIR/include/dcmtk/dcmfg/stack.h \
  $$SRC_DIR/include/dcmtk/dcmfg/stackinterface.h \


SOURCES += \
  $$SRC_DIR/libsrc/concatenationcreator.cc \
  $$SRC_DIR/libsrc/concatenationloader.cc \
  $$SRC_DIR/libsrc/fg.cc \
  $$SRC_DIR/libsrc/fgbase.cc \
  $$SRC_DIR/libsrc/fgctacquisitiondetails.cc \
  $$SRC_DIR/libsrc/fgctacquisitiontype.cc \
  $$SRC_DIR/libsrc/fgctadditionalxraysource.cc \
  $$SRC_DIR/libsrc/fgctexposure.cc \
  $$SRC_DIR/libsrc/fgctgeometry.cc \
  $$SRC_DIR/libsrc/fgctimageframetype.cc \
  $$SRC_DIR/libsrc/fgctposition.cc \
  $$SRC_DIR/libsrc/fgctreconstruction.cc \
  $$SRC_DIR/libsrc/fgcttabledynamics.cc \
  $$SRC_DIR/libsrc/fgctxraydetails.cc \
  $$SRC_DIR/libsrc/fgderimg.cc \
  $$SRC_DIR/libsrc/fgfact.cc \
  $$SRC_DIR/libsrc/fgfracon.cc \
  $$SRC_DIR/libsrc/fgframeanatomy.cc \
  $$SRC_DIR/libsrc/fgframevoilut.cc \
  $$SRC_DIR/libsrc/fgimagedatatype.cc \
  $$SRC_DIR/libsrc/fginterface.cc \
  $$SRC_DIR/libsrc/fgirradiationeventid.cc \
  $$SRC_DIR/libsrc/fgparametricmapframetype.cc \
  $$SRC_DIR/libsrc/fgpixeltransform.cc \
  $$SRC_DIR/libsrc/fgpixmsr.cc \
  $$SRC_DIR/libsrc/fgplanor.cc \
  $$SRC_DIR/libsrc/fgplanorvol.cc \
  $$SRC_DIR/libsrc/fgplanpo.cc \
  $$SRC_DIR/libsrc/fgplanposvol.cc \
  $$SRC_DIR/libsrc/fgrealworldvaluemapping.cc \
  $$SRC_DIR/libsrc/fgseg.cc \
  $$SRC_DIR/libsrc/fgtemporalposition.cc \
  $$SRC_DIR/libsrc/fgtypes.cc \
  $$SRC_DIR/libsrc/fgusimagedescription.cc \
  $$SRC_DIR/libsrc/stack.cc \
  $$SRC_DIR/libsrc/stackinterface.cc \

#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

