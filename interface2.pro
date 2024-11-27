TARGET = your_project_name
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql multimedia multimediawidgets charts printsupport

CONFIG += c++17

SOURCES += \
    connexion.cpp \
    m4player.cpp \
    main.cpp \
    mainwindow.cpp \
    mplayer.cpp \
    ordonnance.cpp \
    ordonnanceui.cpp \
    statistique.cpp

HEADERS += \
    connexion.h \
    m4player.h \
    mainwindow.h \
    mplayer.h \
    ordonnance.h \
    ordonnanceui.h \
    statistique.h

FORMS += \
    m4player.ui \
    mainwindow.ui \
    mplayer.ui \
    ordonnanceui.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
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
