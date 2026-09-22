
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
INCLUDEPATH += $$SRC_GROUP_DIR/oflog/include



DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/dcmdata/cmdlnarg.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcbytstr.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcchrstr.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dccodec.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdatset.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdatutl.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcddirif.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdefine.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdeftag.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdicdir.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdicent.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdict.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcdirrec.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcelem.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcencdoc.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcerror.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcfcache.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcfilefo.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcfilter.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dchashdi.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcistrma.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcistrmb.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcistrmf.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcistrmz.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcitem.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcjson.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dclist.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcmatch.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcmetinf.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcobject.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcofsetl.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcostrma.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcostrmb.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcostrmf.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcostrmz.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcovlay.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcpath.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcpcache.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcpixel.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcpixseq.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcpxitem.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrleccd.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrlecce.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrlecp.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrledec.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrledrg.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrleenc.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrleerg.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcrlerp.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcsequen.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcspchrs.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcstack.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcswap.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dctag.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dctagkey.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dctk.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dctypes.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcuid.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvr.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrae.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvras.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrat.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrcs.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrda.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrds.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrdt.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrfd.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrfl.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvris.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrlo.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrlt.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrobow.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrod.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrof.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrol.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrov.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrpn.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrpobw.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrsh.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrsl.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrss.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrst.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrsv.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrtm.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvruc.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrui.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrul.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrulup.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrur.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrus.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvrut.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcvruv.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcwcache.h \
  $$SRC_DIR/include/dcmtk/dcmdata/dcxfer.h \
  $$SRC_DIR/include/dcmtk/dcmdata/vrscan.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2d.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2dbmps.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2define.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2dimgs.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2djpgs.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2doutpl.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2dplnsc.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2dplsc.h \
  $$SRC_DIR/include/dcmtk/dcmdata/libi2d/i2dplvlp.h \
  $$SRC_DIR/libsrc/vrscani.h \
  $$SRC_DIR/libsrc/vrscanl.h \


SOURCES += \
  $$SRC_DIR/libsrc/cmdlnarg.cc \
  $$SRC_DIR/libsrc/dcbytstr.cc \
  $$SRC_DIR/libsrc/dcchrstr.cc \
  $$SRC_DIR/libsrc/dccodec.cc \
  $$SRC_DIR/libsrc/dcdatset.cc \
  $$SRC_DIR/libsrc/dcdatutl.cc \
  $$SRC_DIR/libsrc/dcddirif.cc \
  $$SRC_DIR/libsrc/dcdicdir.cc \
  $$SRC_DIR/libsrc/dcdicent.cc \
  $$SRC_DIR/libsrc/dcdict.cc \
  $$SRC_DIR/libsrc/dcdictbi.cc \
  $$SRC_DIR/libsrc/dcdirrec.cc \
  $$SRC_DIR/libsrc/dcelem.cc \
  $$SRC_DIR/libsrc/dcerror.cc \
  $$SRC_DIR/libsrc/dcfilefo.cc \
  $$SRC_DIR/libsrc/dcfilter.cc \
  $$SRC_DIR/libsrc/dchashdi.cc \
  $$SRC_DIR/libsrc/dcistrma.cc \
  $$SRC_DIR/libsrc/dcistrmb.cc \
  $$SRC_DIR/libsrc/dcistrmf.cc \
  $$SRC_DIR/libsrc/dcistrmz.cc \
  $$SRC_DIR/libsrc/dcitem.cc \
  $$SRC_DIR/libsrc/dcjson.cc \
  $$SRC_DIR/libsrc/dclist.cc \
  $$SRC_DIR/libsrc/dcmatch.cc \
  $$SRC_DIR/libsrc/dcmetinf.cc \
  $$SRC_DIR/libsrc/dcobject.cc \
  $$SRC_DIR/libsrc/dcostrma.cc \
  $$SRC_DIR/libsrc/dcostrmb.cc \
  $$SRC_DIR/libsrc/dcostrmf.cc \
  $$SRC_DIR/libsrc/dcostrmz.cc \
  $$SRC_DIR/libsrc/dcpath.cc \
  $$SRC_DIR/libsrc/dcpcache.cc \
  $$SRC_DIR/libsrc/dcpixel.cc \
  $$SRC_DIR/libsrc/dcpixseq.cc \
  $$SRC_DIR/libsrc/dcpxitem.cc \
  $$SRC_DIR/libsrc/dcrleccd.cc \
  $$SRC_DIR/libsrc/dcrlecce.cc \
  $$SRC_DIR/libsrc/dcrlecp.cc \
  $$SRC_DIR/libsrc/dcrledrg.cc \
  $$SRC_DIR/libsrc/dcrleerg.cc \
  $$SRC_DIR/libsrc/dcrlerp.cc \
  $$SRC_DIR/libsrc/dcsequen.cc \
  $$SRC_DIR/libsrc/dcspchrs.cc \
  $$SRC_DIR/libsrc/dcstack.cc \
  $$SRC_DIR/libsrc/dcswap.cc \
  $$SRC_DIR/libsrc/dctag.cc \
  $$SRC_DIR/libsrc/dctagkey.cc \
  $$SRC_DIR/libsrc/dctypes.cc \
  $$SRC_DIR/libsrc/dcuid.cc \
  $$SRC_DIR/libsrc/dcvr.cc \
  $$SRC_DIR/libsrc/dcvrae.cc \
  $$SRC_DIR/libsrc/dcvras.cc \
  $$SRC_DIR/libsrc/dcvrat.cc \
  $$SRC_DIR/libsrc/dcvrcs.cc \
  $$SRC_DIR/libsrc/dcvrda.cc \
  $$SRC_DIR/libsrc/dcvrds.cc \
  $$SRC_DIR/libsrc/dcvrdt.cc \
  $$SRC_DIR/libsrc/dcvrfd.cc \
  $$SRC_DIR/libsrc/dcvrfl.cc \
  $$SRC_DIR/libsrc/dcvris.cc \
  $$SRC_DIR/libsrc/dcvrlo.cc \
  $$SRC_DIR/libsrc/dcvrlt.cc \
  $$SRC_DIR/libsrc/dcvrobow.cc \
  $$SRC_DIR/libsrc/dcvrod.cc \
  $$SRC_DIR/libsrc/dcvrof.cc \
  $$SRC_DIR/libsrc/dcvrol.cc \
  $$SRC_DIR/libsrc/dcvrpn.cc \
  $$SRC_DIR/libsrc/dcvrpobw.cc \
  $$SRC_DIR/libsrc/dcvrsh.cc \
  $$SRC_DIR/libsrc/dcvrsl.cc \
  $$SRC_DIR/libsrc/dcvrss.cc \
  $$SRC_DIR/libsrc/dcvrst.cc \
  $$SRC_DIR/libsrc/dcvrtm.cc \
  $$SRC_DIR/libsrc/dcvruc.cc \
  $$SRC_DIR/libsrc/dcvrui.cc \
  $$SRC_DIR/libsrc/dcvrul.cc \
  $$SRC_DIR/libsrc/dcvrulup.cc \
  $$SRC_DIR/libsrc/dcvrur.cc \
  $$SRC_DIR/libsrc/dcvrus.cc \
  $$SRC_DIR/libsrc/dcvrut.cc \
  $$SRC_DIR/libsrc/dcwcache.cc \
  $$SRC_DIR/libsrc/dcxfer.cc \
  $$SRC_DIR/libsrc/vrscan.cc \
  $$SRC_DIR/libsrc/vrscanl.c \
  $$SRC_DIR/libi2d/i2d.cc \
  $$SRC_DIR/libi2d/i2dbmps.cc \
  $$SRC_DIR/libi2d/i2djpgs.cc \
  $$SRC_DIR/libi2d/i2dplnsc.cc \
  $$SRC_DIR/libi2d/i2dplsc.cc \
  $$SRC_DIR/libi2d/i2dplvlp.cc \

#? deprecated
#  $$SRC_DIR/libsrc/dcencdoc.cc \
#  $$SRC_DIR/libsrc/dcvrov.cc \
#  $$SRC_DIR/libsrc/dcvrsv.cc \
#  $$SRC_DIR/libsrc/dcvruv.cc \


LIBS += -L$$TARGETSDIR -loflog


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

