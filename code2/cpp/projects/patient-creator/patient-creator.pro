
QT += widgets

INCLUDEPATH += ../../alt/patient-creator/
INCLUDEPATH += ../../alt/patient-creator/components


DEFINES += QString_null=QString{}

SOURCES += main.cpp

greaterThan(QT_MAJOR_VERSION, 5) {
DEFINES += Q_Enter_Event=QEnterEvent
} else {
DEFINES += Q_Enter_Event=QEvent
}


HEADERS += \
  forms-jsp/jsp-admission-form.h \



SOURCES += \
  forms-jsp/jsp-admission-form.cpp \


DESTDIR = ../dest


HEADERS += \
  ../../alt/patient-creator/patientcreatorwizard.h \
  ../../alt/patient-creator/identityeditorwidget.h \
  ../../alt/patient-creator/patientmodel.h \
  ../../alt/patient-creator/components/utils/widgets/moderndateeditor.h \
  ../../alt/patient-creator/components/utils/widgets/detailswidget.h \
  ../../alt/patient-creator/components/utils/widgets/detailsbutton.h \
  ../../alt/patient-creator/components/identityplugin/passwordwidget.h \
  ../../alt/patient-creator/components/zipcodesplugin/zipcodeswidget.h \
  ../../alt/patient-creator/components/utils/widgets/qbuttonlineedit.h \


SOURCES += \
  ../../alt/patient-creator/patientcreatorwizard.cpp \
  ../../alt/patient-creator/identityeditorwidget.cpp \
  ../../alt/patient-creator/patientmodel.cpp \
  ../../alt/patient-creator/temp.cpp \
  ../../alt/patient-creator/components/utils/widgets/moderndateeditor.cpp \
  ../../alt/patient-creator/components/utils/widgets/detailswidget.cpp \
  ../../alt/patient-creator/components/utils/widgets/detailsbutton.cpp \
  ../../alt/patient-creator/components/identityplugin/passwordwidget.cpp \
  ../../alt/patient-creator/components/zipcodesplugin/zipcodeswidget.cpp \
  ../../alt/patient-creator/components/utils/widgets/qbuttonlineedit.cpp \

