#-------------------------------------------------
#
# Project created by QtCreator 2018-01-27T22:49:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = alena-studio
TEMPLATE = app


SOURCES += main.cpp\
        main_window.cpp \
    new_project_dialog.cpp \
    project.cpp \
    characters_dialog.cpp \
    map_manager_dialog.cpp

HEADERS  += main_window.h \
    new_project_dialog.h \
    project.h \
    characters_dialog.h \
    map_manager_dialog.h

FORMS    += main_window.ui \
    new_project_dialog.ui \
    characters_dialog.ui \
    map_manager_dialog.ui
