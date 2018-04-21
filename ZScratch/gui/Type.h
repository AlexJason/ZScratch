#pragma once
#ifndef GUI_TYPE
#define GUI_TYPE
#include "CompileOption.h"
struct Unused {};

typedef std::wstring	String;
#if defined(ZSCRATCH_COMPILE_WIN32)
#include <Windows.h>
typedef Unused			Application;
typedef HWND			Window;
typedef HINSTANCE		Instance;
#elif defined(ZSCRATCH_COMPILE_QT)
#include <QApplication>
#include <QWindow>
typedef QApplication	Application;
typedef QWindow			Window;
typedef Unused			Instance;
#endif
#endif
