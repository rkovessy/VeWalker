#-------------------------------------------------
#
# Project created by QtCreator 2011-06-10T17:20:52
#
#-------------------------------------------------

QT       += core gui

TARGET = VeWalker
TEMPLATE = app


SOURCES += \
    startwindow.cpp \
    mainwindow.cpp \
    main.cpp \
    demographics.cpp \
    trafficcontrol.cpp \
    tilt.cpp \
    sonar.cpp \
    sensor.cpp \
    rcx21.cpp \
    path.cpp \
    mywindow.cpp \
    motor.cpp \
    legoThread.cpp \
    io_8574.cpp \
    i2c.cpp \
    glwidget.cpp \
    filesystem.cpp \
    error.cpp \
    draw.cpp \
    compass.cpp \
    color.cpp \
    collectdata.cpp \
    car.cpp \
    brick.cpp \
    bluetooth.cpp \
    adc_8591.cpp \
    ve.cpp \
    data.cpp \
    popupscreen.cpp

HEADERS  += \
    startwindow.h \
    mainwindow.h \
    demographics.h \
    trafficcontrol.h \
    touch.h \
    tilt.h \
    temperature.h \
    sound.h \
    sonar.h \
    sensor.h \
    rotation.h \
    rcx21.h \
    rcx_light.h \
    path.h \
    nxt.h \
    mywindow.h \
    motor.h \
    light.h \
    legoThread.h \
    io_8574.h \
    i2c.h \
    gyro.h \
    glwidget.h \
    filesystem.h \
    error.h \
    draw.h \
    connection.h \
    compass.h \
    color.h \
    collectdata.h \
    car.h \
    brick.h \
    bluetooth.h \
    adc_8591.h \
    ve.h \
    network.h \
    data.h \
    popupscreen.h

FORMS    += \
    startwindow.ui \
    mainwindow.ui \
    demographics.ui \
    popupscreen.ui

QT           += opengl

CONFIG += console debug

RESOURCES =

# install
#target.path = $$[QT_INSTALL_EXAMPLES]/opengl/hellogl
#sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS hellogl.pro
#sources.path = $$[QT_INSTALL_EXAMPLES]/opengl/hellogl
#INSTALLS += target sources



#TEMPLATE = app
#HEADERS = \
#	curvewidget.h \
#	datathread.h
#SOURCES = \
#	run.cpp \
#	curvewidget.cpp \
#	datathread.cpp
#CONFIG += console release
#
#LIBS += C:\Qt\4.4.2\externals\qwt-5.1.1\lib\qwt5.dll
#INCLUDEPATH += C:\Qt\4.4.2\externals\qwt-5.1.1\src
