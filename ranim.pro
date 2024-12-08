QT       += core gui network
QT += core gui charts
QT += core serialport
QT += serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    fournisseur.cpp \
    fournisseurui.cpp \
    main.cpp \
    mainwindow.cpp \
    qrcode.cpp \
    sms.cpp \
    statranim.cpp

HEADERS += \
    connexion.h \
    fournisseur.h \
    fournisseurui.h \
    mainwindow.h \
    qrcode.h \
    sms.h \
    statranim.h

FORMS += \
    fournisseurui.ui \
    mainwindow.ui \
    statranim.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
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
    image9.qrc

DISTFILES += \
    libeay32.dll \
    libssl32.dll \
    ssleay32.dll
android {
  ANDROID_EXTRA_LIBS += $$PWD/../../android-openssl-qt/prebuilt/armeabi-v7a/libcrypto.so
  ANDROID_EXTRA_LIBS += $$PWD/../../android-openssl-qt/prebuilt/armeabi-v7a/libssl.so
}
