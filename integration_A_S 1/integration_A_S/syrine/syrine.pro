 QT       += core gui charts
 QT       += core gui sql serialport
 QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql
QT += widgets sql charts multimedia multimediawidgets printsupport widgets axcontainer serialport
CONFIG += c++17
INCLUDEPATH += $$PWD/../abdou/libs/qrcodegen
INCLUDEPATH += $$PWD/../ranim
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    $$PWD/../abdou/arduino.cpp \
    $$PWD/../abdou/medicament.cpp \
    $$PWD/../abdou/medicament_ui.cpp \
    $$PWD/../abdou/qrcodedialog.cpp \
    $$PWD/../abdou/statistique.cpp \
    $$PWD/../abdou/libs/qrcodegen/qrcodegen.cpp \
    $$PWD/../ranim/fournisseur.cpp \
    $$PWD/../ranim/fournisseurui.cpp \
    $$PWD/../ranim/statranim.cpp \
    $$PWD/../ranim/sms.cpp \
    congee.cpp \
    connexion.cpp \
    employee.cpp \
    employeeui.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    $$PWD/../abdou/arduino.h \
    $$PWD/../abdou/medicament.h \
    $$PWD/../abdou/medicament_ui.h \
    $$PWD/../abdou/qrcodedialog.h \
    $$PWD/../abdou/statistique.h \
    $$PWD/../abdou/libs/qrcodegen/qrcodegen.hpp \
    $$PWD/../ranim/fournisseur.h \
    $$PWD/../ranim/fournisseurui.h \
    $$PWD/../ranim/statranim.h \
    $$PWD/../ranim/sms.h \
    congee.h \
    connexion.h \
    employee.h \
    employeeui.h \
    login.h \
    mainwindow.h

FORMS += \
    $$PWD/../abdou/medicament_ui.ui \
    $$PWD/../abdou/statistique.ui \
    $$PWD/../ranim/fournisseurui.ui \
    $$PWD/../ranim/statranim.ui \
    congee.ui \
    employeeui.ui \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    avatar.qrc \
    iconMed.qrc \
    image.qrc \
    image1.qrc \
    image10.qrc \
    image15.qrc \
    image16.qrc \
    image18.qrc \
    image2.qrc \
    image20.qrc \
    image21.qrc \
    image22.qrc \
    image23.qrc \
    image24.qrc \
    image25.qrc \
    image26.qrc \
    image27.qrc \
    image28.qrc \
    image3.qrc \
    image30.qrc \
    image4.qrc \
    image5.qrc \
    image6.qrc \
    image7.qrc \
    image8.qrc \
    image9.qrc \
    imagee.qrc \
    img34.qrc \
    img_login.qrc \
    log.qrc \
    new.qrc
