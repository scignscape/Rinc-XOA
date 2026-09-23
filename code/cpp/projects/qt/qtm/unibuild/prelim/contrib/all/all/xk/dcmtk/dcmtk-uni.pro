
#           Copyright Nathaniel Christen 2026.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


TEMPLATE = subdirs


SUBDIRS = \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/oflog \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/ofstd \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmimgle \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcm-config \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmdata \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmfg \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmimage \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmiod \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmjpeg \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmjpeg-12 \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmjpeg-16 \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmjpls \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmnet \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmpmap \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmpstat \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmqrdb \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmrt \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmseg \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmsign \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmsr \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmtls \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmtract \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmtk/dcmwlm \


# deprecated?
#   ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/cda2dcm \

# just these for now

SUBDIRS += \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcm2xml \
  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dsr2xml \


#SUBDIRS += \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcm2json \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcm2pdf \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcm2pnm \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcm2xml \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmcjpeg \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmcjpls \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmconv \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmcrle \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmdjpeg \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmdjpls \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmdrle \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmdspfn \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmdump \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmftest \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmgpdir \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmicmp \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmj2pnm \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcml2pnm \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmmkcrv \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmmkdir \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmmklut \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmodify \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmp2pgm \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmprscp \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmprscu \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmpschk \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmpsmk \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmpsprt \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmpsrcv \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmpssnd \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmqridx \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmqrscp \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmqrti \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmquant \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmrecv \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmscale \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmsend \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcmsign-app \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dcod2lum \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dconvlum \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/drtdump \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dsr2html \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dsr2xml \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dsrdump \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/dump2dcm \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/echoscu \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/findscu \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/getscu \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/img2dcm \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/movescu \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/pdf2dcm \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/stl2dcm \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/storescp \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/storescu \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/termscu \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/wlmscpfs \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/xml2dcm \
#  ../../../../../../../isobuild-u/prelim/contrib/all/all/xk/external/dcmapps/xml2dsr \



CONFIG += ordered

