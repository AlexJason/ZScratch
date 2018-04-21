#-------------------------------------------------
#
# Project created by QtCreator 2018-04-21T07:15:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZScratch
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    command/EditorCommand.cpp \
    gui/qt/MainWindow.cpp \
    gui/qt/QWindow.cpp \
    gui/win32/MainWindow.cpp \
    interface/cpp_interface/IScratchBlock.cpp \
    interface/cpp_interface/IScratchBlockItem.cpp \
    interface/cpp_interface/IScratchEvent.cpp \
    interface/cpp_interface/IScratchGui.cpp \
    interface/cpp_interface/IScratchValue.cpp \
    interface/cpp_interface/ScratchBlock.cpp \
    interface/cpp_interface/ScratchEvent.cpp \
    interface/cpp_interface/ScratchGui.cpp \
    interface/cpp_interface/ScratchValue.cpp \
    scratch/Scratch.cpp \
    scratch/ScratchCostume.cpp \
    scratch/ScratchInfo.cpp \
    scratch/ScratchObject.cpp \
    scratch/ScratchRuntime.cpp \
    scratch/ScratchScript.cpp \
    scratch/ScratchScriptPart.cpp \
    scratch/ScratchSound.cpp \
    scratch/ScratchSpec.cpp \
    scratch/ScratchSprite.cpp \
    scratch/ScratchStage.cpp \
    scratch/ScratchVariable.cpp \
    translate/Translate.cpp \
    util/AppArgu.cpp \
    util/Color.cpp \
    util/Console.cpp \
    util/FileIO.cpp \
    util/Json.cpp \
    util/Paint.cpp \
    util/Rect.cpp \
    util/String.cpp \
    util/Time.cpp \
    main.cpp \
    gui/qt/MainWindow.cpp \
    gui/qt/qwindow.cpp \
    gui/win32/MainWindow.cpp \
    gui/win32/MainWindow.cpp

HEADERS += \
    command/EditorCommand.h \
    gui/qt/QWindow.h \
    gui/CompileOption.h \
    gui/MainWindow.h \
    gui/Type.h \
    interface/cpp_interface/IScratchBlock.h \
    interface/cpp_interface/IScratchBlockItem.h \
    interface/cpp_interface/IScratchEvent.h \
    interface/cpp_interface/IScratchExtension.h \
    interface/cpp_interface/IScratchGui.h \
    interface/cpp_interface/IScratchValue.h \
    interface/cpp_interface/pdk.h \
    interface/cpp_interface/RegisterInfo.h \
    interface/cpp_interface/ScratchBlock.h \
    interface/cpp_interface/ScratchBlockItem.h \
    interface/cpp_interface/ScratchEvent.h \
    interface/cpp_interface/ScratchGui.h \
    interface/cpp_interface/ScratchGuiStruct.h \
    interface/cpp_interface/ScratchValue.h \
    scratch/Scratch.h \
    scratch/ScratchCostume.h \
    scratch/ScratchInfo.h \
    scratch/ScratchObject.h \
    scratch/ScratchRuntime.h \
    scratch/ScratchScript.h \
    scratch/ScratchScriptPart.h \
    scratch/ScratchSound.h \
    scratch/ScratchSpec.h \
    scratch/ScratchSprite.h \
    scratch/ScratchStage.h \
    scratch/ScratchVariable.h \
    translate/Translate.h \
    util/AppArgu.h \
    util/Color.h \
    util/Console.h \
    util/FileIO.h \
    util/Json.h \
    util/Paint.h \
    util/Rect.h \
    util/String.h \
    util/Time.h \
    resource.h \
    gui/qt/qwindow.h \
    gui/CompileOption.h \
    gui/MainWindow.h \
    gui/Type.h \
    gui/win32/WPaint.h

DISTFILES += \
    config/style.json \
    Debug/vc141.idb \
    Debug/ZScratch.res \
    Debug/vc141.pdb \
    cpp_interface.lib \
    cpp_interface.dll \
    config/locale.xml \
    config/path.xml \
    config/plugin.xml \
    locale/en-us/lang.cfg \

