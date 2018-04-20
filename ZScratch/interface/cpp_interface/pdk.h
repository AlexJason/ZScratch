#pragma once
#ifndef SCRATCH_PLUGIN_DEVELOPMENT_KIT_H
#define SCRATCH_PLUGIN_DEVELOPMENT_KIT_H_

#define PLUGIN_SDK_VER 1.1

#pragma warning(disable:4251)

#ifdef _LIBOUT
#define PDK __declspec(dllexport)
#else
#define PDK __declspec(dllimport)
#endif

#define EXPORT __declspec(dllexport)

#include "IScratchBlock.h"
#include "IScratchBlockItem.h"
#include "IScratchEvent.h"
#include "IScratchExtension.h"
#include "IScratchGui.h"
#include "IScratchValue.h"

#endif
