#pragma once
#ifdef _LIBOUT
#define PDK __declspec(dllexport)
#else
#define PDK __declspec(dllimport)
#endif

#define EXPORT __declspec(dllexport)

#if defined(_MSC_VER) && defined(SCWIN32)
#define ZSCRATCH_COMPILE_WIN32
#else
#define ZSCRATCH_COMPILE_QT
#endif
