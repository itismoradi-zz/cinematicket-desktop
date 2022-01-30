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

SOURCES += \
        main.cpp \
        login.cpp \
    signup.cpp \
    cinemamovie.cpp \
    profile.cpp

HEADERS += \
        login.hpp \
    signup.hpp \
    cinemamovie.hpp \
    profile.hpp

FORMS += \
        login.ui \
    signup.ui \
    cinemamovie.ui \
    profile.ui

RESOURCES += \
    assets.qrc
