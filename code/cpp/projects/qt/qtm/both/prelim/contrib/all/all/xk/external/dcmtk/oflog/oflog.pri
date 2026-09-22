
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

#?
DEFINES += DCMTK_INSIDE_LOG4CPLUS


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords


HEADERS += \
  $$SRC_DIR/include/dcmtk/oflog/appender.h \
  $$SRC_DIR/include/dcmtk/oflog/asyncap.h \
  $$SRC_DIR/include/dcmtk/oflog/clfsap.h \
  $$SRC_DIR/include/dcmtk/oflog/clogger.h \
  $$SRC_DIR/include/dcmtk/oflog/config.h \
  $$SRC_DIR/include/dcmtk/oflog/configrt.h \
  $$SRC_DIR/include/dcmtk/oflog/consap.h \
  $$SRC_DIR/include/dcmtk/oflog/fileap.h \
  $$SRC_DIR/include/dcmtk/oflog/fstreams.h \
  $$SRC_DIR/include/dcmtk/oflog/hierarchy.h \
  $$SRC_DIR/include/dcmtk/oflog/hierlock.h \
  $$SRC_DIR/include/dcmtk/oflog/layout.h \
  $$SRC_DIR/include/dcmtk/oflog/log4judp.h \
  $$SRC_DIR/include/dcmtk/oflog/logger.h \
  $$SRC_DIR/include/dcmtk/oflog/loglevel.h \
  $$SRC_DIR/include/dcmtk/oflog/logmacro.h \
  $$SRC_DIR/include/dcmtk/oflog/mdc.h \
  $$SRC_DIR/include/dcmtk/oflog/ndc.h \
  $$SRC_DIR/include/dcmtk/oflog/ntelogap.h \
  $$SRC_DIR/include/dcmtk/oflog/nullap.h \
  $$SRC_DIR/include/dcmtk/oflog/oflog.h \
  $$SRC_DIR/include/dcmtk/oflog/socketap.h \
  $$SRC_DIR/include/dcmtk/oflog/streams.h \
  $$SRC_DIR/include/dcmtk/oflog/syslogap.h \
  $$SRC_DIR/include/dcmtk/oflog/tchar.h \
  $$SRC_DIR/include/dcmtk/oflog/tracelog.h \
  $$SRC_DIR/include/dcmtk/oflog/tstring.h \
  $$SRC_DIR/include/dcmtk/oflog/version.h \
  $$SRC_DIR/include/dcmtk/oflog/winconap.h \
  $$SRC_DIR/include/dcmtk/oflog/windebap.h \
  $$SRC_DIR/include/dcmtk/oflog/config/defines.h \
  $$SRC_DIR/include/dcmtk/oflog/config/macosx.h \
  $$SRC_DIR/include/dcmtk/oflog/config/win32.h \
  $$SRC_DIR/include/dcmtk/oflog/config/windowsh.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/apndimpl.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/fileinfo.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/lloguser.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/lockfile.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/loglog.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/pointer.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/property.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/queue.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/sleep.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/snprintf.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/sockbuff.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/socket.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/strhelp.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/threadcf.h \
  $$SRC_DIR/include/dcmtk/oflog/helpers/timehelp.h \
  $$SRC_DIR/include/dcmtk/oflog/internal/cygwin32.h \
  $$SRC_DIR/include/dcmtk/oflog/internal/env.h \
  $$SRC_DIR/include/dcmtk/oflog/internal/internal.h \
  $$SRC_DIR/include/dcmtk/oflog/internal/socket.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/apndatch.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/factory.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/filter.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/logevent.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/logfact.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/logimpl.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/objreg.h \
  $$SRC_DIR/include/dcmtk/oflog/spi/rootlog.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/syncprim.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/syncpub.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/threads.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/impl/syncimpl.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/impl/syncpmsm.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/impl/syncpthr.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/impl/syncwin.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/impl/thredimp.h \
  $$SRC_DIR/include/dcmtk/oflog/thread/impl/tls.h \


# don't need?
#? $$SRC_DIR/libsrc/clfsap.cc \


SOURCES += \
  $$SRC_DIR/libsrc/apndimpl.cc \
  $$SRC_DIR/libsrc/appender.cc \
  $$SRC_DIR/libsrc/asyncap.cc \
  $$SRC_DIR/libsrc/clogger.cc \
  $$SRC_DIR/libsrc/config.cc \
  $$SRC_DIR/libsrc/consap.cc \
  $$SRC_DIR/libsrc/cygwin32.cc \
  $$SRC_DIR/libsrc/env.cc \
  $$SRC_DIR/libsrc/factory.cc \
  $$SRC_DIR/libsrc/fileap.cc \
  $$SRC_DIR/libsrc/fileinfo.cc \
  $$SRC_DIR/libsrc/filter.cc \
  $$SRC_DIR/libsrc/globinit.cc \
  $$SRC_DIR/libsrc/hierarchy.cc \
  $$SRC_DIR/libsrc/hierlock.cc \
  $$SRC_DIR/libsrc/layout.cc \
  $$SRC_DIR/libsrc/lloguser.cc \
  $$SRC_DIR/libsrc/lockfile.cc \
  $$SRC_DIR/libsrc/log4judp.cc \
  $$SRC_DIR/libsrc/logevent.cc \
  $$SRC_DIR/libsrc/logger.cc \
  $$SRC_DIR/libsrc/logimpl.cc \
  $$SRC_DIR/libsrc/loglevel.cc \
  $$SRC_DIR/libsrc/loglog.cc \
  $$SRC_DIR/libsrc/logmacro.cc \
  $$SRC_DIR/libsrc/mdc.cc \
  $$SRC_DIR/libsrc/ndc.cc \
  $$SRC_DIR/libsrc/ntelogap.cc \
  $$SRC_DIR/libsrc/nullap.cc \
  $$SRC_DIR/libsrc/objreg.cc \
  $$SRC_DIR/libsrc/oflog.cc \
  $$SRC_DIR/libsrc/patlay.cc \
  $$SRC_DIR/libsrc/pointer.cc \
  $$SRC_DIR/libsrc/property.cc \
  $$SRC_DIR/libsrc/queue.cc \
  $$SRC_DIR/libsrc/rootlog.cc \
  $$SRC_DIR/libsrc/sleep.cc \
  $$SRC_DIR/libsrc/snprintf.cc \
  $$SRC_DIR/libsrc/sockbuff.cc \
  $$SRC_DIR/libsrc/socket.cc \
  $$SRC_DIR/libsrc/socketap.cc \
  $$SRC_DIR/libsrc/strccloc.cc \
  $$SRC_DIR/libsrc/strcloc.cc \
  $$SRC_DIR/libsrc/strhelp.cc \
  $$SRC_DIR/libsrc/striconv.cc \
  $$SRC_DIR/libsrc/syncprims.cc \
  $$SRC_DIR/libsrc/syslogap.cc \
  $$SRC_DIR/libsrc/threads.cc \
  $$SRC_DIR/libsrc/timehelp.cc \
  $$SRC_DIR/libsrc/tls.cc \
  $$SRC_DIR/libsrc/unixsock.cc \
  $$SRC_DIR/libsrc/version.cc \
  $$SRC_DIR/libsrc/winconap.cc \
  $$SRC_DIR/libsrc/windebap.cc \
  $$SRC_DIR/libsrc/winsock.cc \

#LIBS += -L$$TARGETSDIR

message(T $$TARGETSDIR)

message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

