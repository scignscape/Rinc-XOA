
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
INCLUDEPATH += $$SRC_GROUP_DIR/dcmimgle/include
INCLUDEPATH += $$SRC_GROUP_DIR/dcmimage/include


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid11.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid29.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid29e.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid42.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid100.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid244.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid244e.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid4020.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid4021.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid4031.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid4031e.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid5000.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid5001.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid6147.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid7021.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid7181.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid7445.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid7452.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid7453.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid7464.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid7469.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid10013.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid10013e.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid10033.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/cid10033e.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/define.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/init.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/logger.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/srnumvl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/srnumvlu.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid15def.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid300.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid1001.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid1204.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid1411.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid1419m.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid1500.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid1501.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid1600.h \
  $$SRC_DIR/include/dcmtk/dcmsr/cmr/tid4019.h \
  $$SRC_DIR/include/dcmtk/dcmsr/codes/dcm.h \
  $$SRC_DIR/include/dcmtk/dcmsr/codes/ncit.h \
  $$SRC_DIR/include/dcmtk/dcmsr/codes/sct.h \
  $$SRC_DIR/include/dcmtk/dcmsr/codes/srt.h \
  $$SRC_DIR/include/dcmtk/dcmsr/codes/ucum.h \
  $$SRC_DIR/include/dcmtk/dcmsr/codes/umls.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsdefine.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsracqcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrbascc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrc3dcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrchecc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcitem.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcodtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcodvl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcolcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcomcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcomtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcomvl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcontn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrcsidl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrctpl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrctxgr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdattn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdncsr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdnflt.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdoc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdocst.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdoctn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdoctr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrdtitn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrenhcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrimgfr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrimgse.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrimgtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrimgvl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrimpcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsriodcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsritcsr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrkeycc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrmaccc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrmamcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrnumtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrnumvl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrpficc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrplicc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrpnmtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrposcn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrprdcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrprocc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrrefin.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrreftn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrrrdcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrrsdcc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrrtpl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrsaecc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrsc3gr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrsc3tn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrsc3vl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrscogr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrscotn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrscovl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrsoprf.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrspecc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrstpl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrstrvl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtcodt.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtcosp.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtcotn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtcoto.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtcovl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtextn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtimtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtlist.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtnant.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtncsr.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtpltn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtree.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrtypes.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsruidtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrwavch.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrwavtn.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrwavvl.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrxmlc.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrxmld.h \
  $$SRC_DIR/include/dcmtk/dcmsr/dsrxrdcc.h \


SOURCES += \
  $$SRC_DIR/libsrc/dsracqcc.cc \
  $$SRC_DIR/libsrc/dsrbascc.cc \
  $$SRC_DIR/libsrc/dsrc3dcc.cc \
  $$SRC_DIR/libsrc/dsrchecc.cc \
  $$SRC_DIR/libsrc/dsrcitem.cc \
  $$SRC_DIR/libsrc/dsrcodtn.cc \
  $$SRC_DIR/libsrc/dsrcodvl.cc \
  $$SRC_DIR/libsrc/dsrcolcc.cc \
  $$SRC_DIR/libsrc/dsrcomcc.cc \
  $$SRC_DIR/libsrc/dsrcomtn.cc \
  $$SRC_DIR/libsrc/dsrcomvl.cc \
  $$SRC_DIR/libsrc/dsrcontn.cc \
  $$SRC_DIR/libsrc/dsrcsidl.cc \
  $$SRC_DIR/libsrc/dsrctpl.cc \
  $$SRC_DIR/libsrc/dsrctxgr.cc \
  $$SRC_DIR/libsrc/dsrdattn.cc \
  $$SRC_DIR/libsrc/dsrdncsr.cc \
  $$SRC_DIR/libsrc/dsrdnflt.cc \
  $$SRC_DIR/libsrc/dsrdoc.cc \
  $$SRC_DIR/libsrc/dsrdocst.cc \
  $$SRC_DIR/libsrc/dsrdoctn.cc \
  $$SRC_DIR/libsrc/dsrdoctr.cc \
  $$SRC_DIR/libsrc/dsrdtitn.cc \
  $$SRC_DIR/libsrc/dsrenhcc.cc \
  $$SRC_DIR/libsrc/dsrimgfr.cc \
  $$SRC_DIR/libsrc/dsrimgse.cc \
  $$SRC_DIR/libsrc/dsrimgtn.cc \
  $$SRC_DIR/libsrc/dsrimgvl.cc \
  $$SRC_DIR/libsrc/dsrimpcc.cc \
  $$SRC_DIR/libsrc/dsriodcc.cc \
  $$SRC_DIR/libsrc/dsritcsr.cc \
  $$SRC_DIR/libsrc/dsrkeycc.cc \
  $$SRC_DIR/libsrc/dsrmaccc.cc \
  $$SRC_DIR/libsrc/dsrmamcc.cc \
  $$SRC_DIR/libsrc/dsrnumtn.cc \
  $$SRC_DIR/libsrc/dsrnumvl.cc \
  $$SRC_DIR/libsrc/dsrpficc.cc \
  $$SRC_DIR/libsrc/dsrplicc.cc \
  $$SRC_DIR/libsrc/dsrpnmtn.cc \
  $$SRC_DIR/libsrc/dsrposcn.cc \
  $$SRC_DIR/libsrc/dsrprdcc.cc \
  $$SRC_DIR/libsrc/dsrprocc.cc \
  $$SRC_DIR/libsrc/dsrrefin.cc \
  $$SRC_DIR/libsrc/dsrreftn.cc \
  $$SRC_DIR/libsrc/dsrrrdcc.cc \
  $$SRC_DIR/libsrc/dsrrsdcc.cc \
  $$SRC_DIR/libsrc/dsrrtpl.cc \
  $$SRC_DIR/libsrc/dsrsaecc.cc \
  $$SRC_DIR/libsrc/dsrsc3gr.cc \
  $$SRC_DIR/libsrc/dsrsc3tn.cc \
  $$SRC_DIR/libsrc/dsrsc3vl.cc \
  $$SRC_DIR/libsrc/dsrscogr.cc \
  $$SRC_DIR/libsrc/dsrscotn.cc \
  $$SRC_DIR/libsrc/dsrscovl.cc \
  $$SRC_DIR/libsrc/dsrsoprf.cc \
  $$SRC_DIR/libsrc/dsrspecc.cc \
  $$SRC_DIR/libsrc/dsrstpl.cc \
  $$SRC_DIR/libsrc/dsrstrvl.cc \
  $$SRC_DIR/libsrc/dsrtcodt.cc \
  $$SRC_DIR/libsrc/dsrtcosp.cc \
  $$SRC_DIR/libsrc/dsrtcotn.cc \
  $$SRC_DIR/libsrc/dsrtcoto.cc \
  $$SRC_DIR/libsrc/dsrtcovl.cc \
  $$SRC_DIR/libsrc/dsrtextn.cc \
  $$SRC_DIR/libsrc/dsrtimtn.cc \
  $$SRC_DIR/libsrc/dsrtpltn.cc \
  $$SRC_DIR/libsrc/dsrtree.cc \
  $$SRC_DIR/libsrc/dsrtypes.cc \
  $$SRC_DIR/libsrc/dsruidtn.cc \
  $$SRC_DIR/libsrc/dsrwavch.cc \
  $$SRC_DIR/libsrc/dsrwavtn.cc \
  $$SRC_DIR/libsrc/dsrwavvl.cc \
  $$SRC_DIR/libsrc/dsrxmlc.cc \
  $$SRC_DIR/libsrc/dsrxmld.cc \
  $$SRC_DIR/libsrc/dsrxrdcc.cc \


#LIBS += -L$$TARGETSDIR


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

