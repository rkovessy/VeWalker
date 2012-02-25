#-------------------------------------------------
#
# Project created by QtCreator 2011-06-10T17:20:52
#
#-------------------------------------------------

QT       += core gui

TARGET = VeWalker
TEMPLATE = app

SOURCES += \
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
    popupscreen.cpp \
    vuzixthread.cpp \
    arduino.cpp

HEADERS  += \
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
    popupscreen.h \
    iweardrv.h \
    iweardrv.h \
    vuzixthread.h \
    arduino.h \
    serialportinfo.h \
    serialport.h

FORMS    += \
    mainwindow.ui \
    demographics.ui \
    popupscreen.ui

LIBS += -L C:\OpenCVNew\install\bin \
-llibopencv_core231d \
-llibopencv_highgui231d \
-llibopencv_calib3d231d \
-llibopencv_contrib231d \
-llibopencv_features2d231d \
-llibopencv_flann231d \
-llibopencv_gpu231d \
-llibopencv_imgproc231d \
-llibopencv_legacy231d \
-llibopencv_ml231d \
-llibopencv_objdetect231d \
-llibopencv_video231d \
-lopencv_ffmpeg

#INCLUDEPATH += C:\Users\Nulogy\Downloads\qserialdevice-qserialdevice-2.0\qserialdevice-qserialdevice\src
#LIBS += -L "C:\Users\Nulogy\Downloads\qserialdevice-qserialdevice-2.0\qserialdevice-qserialdevice\src\release"
#LIBS += -qserialdevice

INCLUDEPATH += C:\OpenCVNew\install\include \
C:\OpenCVNew\install\include\opencv \


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


win32: LIBS += -L$$PWD/ -liweardrv

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

win32: PRE_TARGETDEPS += $$PWD/iweardrv.lib

OTHER_FILES += \
    wilhelm.wav

INCLUDEPATH += \
    C:/qserialport/qserialdevice-qserialdevice/include \
    C:/qserialport/qserialdevice-qserialdevice/src

include(C:/qserialport/qserialdevice-qserialdevice/src/src.pri)









