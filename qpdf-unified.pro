
include(qpdfview.pri)

TARGET = qpdfview
TEMPLATE = app

OBJECTS_DIR = objects
MOC_DIR = moc
RCC_DIR = rcc
UI_DIR = ui

# Core Qt modules (adds 'xml' needed by Poppler/PDF backend)
QT += core gui widgets xml


### added ...
QT += printsupport concurrent


DEFAULT_DOCUMENTS_DIR = $$clean_path($$_PRO_FILE_PWD_/docs)

DEFINES += DEFAULT_DOCUMENTS_FOLDER=\\\"$${DEFAULT_DOCUMENTS_DIR}\\\"

PARENT_DIR = $$clean_path($$_PRO_FILE_PWD_/..)

# or replace with some other install path, like $$(HOME)/poppler/install
POPPLER_PREFIX = $$PARENT_DIR/poppler/install


INCLUDEPATH += $$POPPLER_PREFIX/include/poppler/qt5 \
              $$POPPLER_PREFIX/include/poppler \

LIBS += -L$$POPPLER_PREFIX/lib \
        -Wl,-rpath,$$POPPLER_PREFIX/lib \
        -lpoppler-qt5 \
        -lpoppler

DEFINES += PLUGIN_INSTALL_PATH=\\\"$${PLUGIN_INSTALL_PATH}\\\"
DEFINES += DATA_INSTALL_PATH=\\\"$${DATA_INSTALL_PATH}\\\"
DEFINES += APP_DIR_DATA_PATH=\\\"$${APP_DIR_DATA_PATH}\\\"
DEFINES += APPLICATION_VERSION=\\\"$${APPLICATION_VERSION}\\\"

###


!without_svg {
    QT += svg
    DEFINES += WITH_SVG
}

!without_sql {
    QT += sql
    DEFINES += WITH_SQL
}

!without_dbus {
    QT += dbus
    DEFINES += WITH_DBUS
}


## extensions

QT += 3dcore 3drender 3dinput 3dextras

INCLUDEPATH += extensions/utils \
  extensions/QtColorWidgets \
  extensions


HEADERS += \
  extensions/cube-9-grid.h \
  extensions/cube-universe-3d.h \
  extensions/QtColorWidgets/color_wheel.hpp \
  extensions/QtColorWidgets/color_utils.hpp \
  extensions/QtColorWidgets/color_selector.hpp \
  extensions/QtColorWidgets/color_preview.hpp \
  extensions/QtColorWidgets/color_dialog.hpp \
  extensions/QtColorWidgets/color_line_edit.hpp \
  extensions/QtColorWidgets/gradient_slider.hpp \
  extensions/QtColorWidgets/hue_slider.hpp \
  extensions/QtColorWidgets/color_names.hpp \


SOURCES += \
  extensions/cube-universe-3d.cpp \
  extensions/cube-9-grid.cpp \
  extensions/QtColorWidgets/src/color_wheel.cpp \
  extensions/QtColorWidgets/src/color_utils.cpp \
  extensions/QtColorWidgets/src/color_selector.cpp \
  extensions/QtColorWidgets/src/color_preview.cpp \
  extensions/QtColorWidgets/src/color_dialog.cpp \
  extensions/QtColorWidgets/src/color_line_edit.cpp \
  extensions/QtColorWidgets/src/gradient_slider.cpp \
  extensions/QtColorWidgets/src/hue_slider.cpp \
  extensions/QtColorWidgets/src/color_names.cpp \


FORMS += \
  extensions/QtColorWidgets/src/color_dialog.ui \
  extensions/QtColorWidgets/src/color_palette_widget.ui


RESOURCES += \
  extensions/QtColorWidgets/resources/color_widgets.qrc \


# Merged Headers: Application + PDF Plugin
HEADERS += \
    sources/application.h \
    sources/global.h \
    sources/model.h \
    sources/pdfmodel.h \
    sources/annotationwidgets.h \
    sources/formfieldwidgets.h \
    sources/settings.h \
    sources/pluginhandler.h \
    sources/shortcuthandler.h \
    sources/rendertask.h \
    sources/tileitem.h \
    sources/pageitem.h \
    sources/thumbnailitem.h \
    sources/presentationview.h \
    sources/searchmodel.h \
    sources/searchitemdelegate.h \
    sources/searchtask.h \
    sources/miscellaneous.h \
    sources/documentlayout.h \
    sources/documentview.h \
    sources/printdialog.h \
    sources/settingsdialog.h \
    sources/fontsdialog.h \
    sources/helpdialog.h \
    sources/recentlyusedmenu.h \
    sources/recentlyclosedmenu.h \
    sources/bookmarkmenu.h \
    sources/bookmarkmodel.h \
    sources/bookmarkdialog.h \
    sources/database.h \
    sources/mainwindow.h \
    sources/main.h

# Merged Sources: Application + PDF Plugin
SOURCES += \
    sources/application.cpp \
    sources/pdfmodel.cpp \
    sources/annotationwidgets.cpp \
    sources/formfieldwidgets.cpp \
    sources/settings.cpp \
    sources/pluginhandler.cpp \
    sources/shortcuthandler.cpp \
    sources/rendertask.cpp \
    sources/tileitem.cpp \
    sources/pageitem.cpp \
    sources/thumbnailitem.cpp \
    sources/presentationview.cpp \
    sources/searchmodel.cpp \
    sources/searchitemdelegate.cpp \
    sources/searchtask.cpp \
    sources/miscellaneous.cpp \
    sources/documentlayout.cpp \
    sources/documentview.cpp \
    sources/printdialog.cpp \
    sources/settingsdialog.cpp \
    sources/fontsdialog.cpp \
    sources/helpdialog.cpp \
    sources/recentlyusedmenu.cpp \
    sources/recentlyclosedmenu.cpp \
    sources/bookmarkmenu.cpp \
    sources/bookmarkmodel.cpp \
    sources/bookmarkdialog.cpp \
    sources/database.cpp \
    sources/mainwindow.cpp \
    sources/main.cpp

RESOURCES += \
    icons.qrc \
    help.qrc \
    translations.qrc \

# Poppler Dependencies (from pdf-plugin.pro)
!without_pkgconfig {
    CONFIG += link_pkgconfig
    equals(QT_MAJOR_VERSION, 6) {
        PKGCONFIG += poppler-qt6
    } else:equals(QT_MAJOR_VERSION, 5) {
        PKGCONFIG += poppler-qt5
    } else {
        PKGCONFIG += poppler-qt4
    }
} else {
    INCLUDEPATH += $$PDF_PLUGIN_INCLUDEPATH
    LIBS += $$PDF_PLUGIN_LIBS
}

# Optional Application Dependencies (from application.pro)
with_cups {
    DEFINES += WITH_CUPS
    LIBS += -lcups
}

with_synctex {
    DEFINES += WITH_SYNCTEX
    !without_pkgconfig {
        PKGCONFIG += synctex
    } else {
        INCLUDEPATH += $$SYNCTEX_INCLUDEPATH
        LIBS += $$SYNCTEX_LIBS
    }
}

# Installation rules (from application.pro)
target.path = $$TARGET_INSTALL_PATH
INSTALLS += target
