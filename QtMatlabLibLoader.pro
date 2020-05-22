QT += core
QT -= gui

CONFIG += c++11

TARGET = QtMatlabLibLoader
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

win32 {
  INCLUDEPATH += $$(MATLABPATH_DMMS)/extern/include
#  LIBS += -L$$(MATLABPATH_DMMS)/'extern/lib/win64/mingw64/' -llibmx -llibeng

}

SOURCES += main.cpp \
    MainObject.cpp \
    Util/DynamicLinkLib/DynamicLoadLibrary.cpp \
    Util/DynamicLinkLib/ILibrary.cpp \
    Matlab/MatlabDynamicLoadLibrary.cpp \
    Matlab/MatlabEngineInterface.cpp \
    Matlab/MatlabEngineManager.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    MainObject.h \
    Util/DynamicLinkLib/DynamicLoadLibrary.h \
    Util/DynamicLinkLib/ILibrary.h \
    Matlab/MatlabDynamicLoadLibrary.h \
    Matlab/MatlabEngineInterface.h \
    Matlab/MatlabEngineManager.h
