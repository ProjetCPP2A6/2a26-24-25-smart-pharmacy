QT       += core gui charts
QT       += core gui sql serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
   congee.cpp \
   connexion.cpp \
   employee.cpp \
   employeeui.cpp \
   login.cpp \
   main.cpp \
   mainwindow.cpp

HEADERS += \
   congee.h \
   connexion.h \
   employee.h \
   employeeui.h \
   login.h \
   mainwindow.h

FORMS += \
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
   img_login.qrc \
   log.qrc
