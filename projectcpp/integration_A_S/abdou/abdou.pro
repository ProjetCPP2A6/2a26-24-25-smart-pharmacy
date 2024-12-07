QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql charts multimedia multimediawidgets printsupport widgets axcontainer serialport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/libs/qrcodegen

SOURCES += \
    arduino.cpp \
    connexion.cpp \
    main.cpp \
    mainwindow.cpp \
    medicament.cpp \
    medicament_ui.cpp \
    qrcodedialog.cpp \
    statistique.cpp \
    libs/qrcodegen/qrcodegen.cpp

HEADERS += \
    arduino.h \
    connexion.h \
    mainwindow.h \
    medicament.h \
    medicament_ui.h \
    qrcodedialog.h \
    statistique.h \
    libs/qrcodegen/qrcodegen.hpp

FORMS += \
    mainwindow.ui \
    medicament_ui.ui \
    qrcodedialog.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target




RESOURCES += \
    iconMed.qrc \
    imagering1.qrc \
    imagering2.qrc \
    img.qrc \
    img1.qrc \
    img10.qrc \
    img11.qrc \
    img12.qrc \
    img13.qrc \
    img14.qrc \
    img16.qrc \
    img17.qrc \
    img19.qrc \
    img2.qrc \
    img21.qrc \
    img22.qrc \
    img24.qrc \
    img25.qrc \
    img27.qrc \
    img28.qrc \
    img29.qrc \
    img30.qrc \
    img32.qrc \
    img5.qrc \
    img6.qrc \
    img7.qrc \
    img8.qrc \
    img9.qrc
