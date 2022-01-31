#-------------------------------------------------
#
# Project created by QtCreator 2022-01-30T14:30:05
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cinemaTicket
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += include

SOURCES += \
        src/main.cpp \
        src/login.cpp \
    	src/signup.cpp \
    	src/cinemamovie.cpp \
    	src/profile.cpp

HEADERS += \
        include/login.hpp \
   	include/signup.hpp \
    	include/cinemamovie.hpp \
    	include/profile.hpp

FORMS += \
        form/login.ui \
    	form/signup.ui \
    	form/cinemamovie.ui \
    	form/profile.ui

RESOURCES += \
    	assets.qrc \
