/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	PluginError.h
 * @author	Alex Cui
 * @date	May, 2018
 * @details	Define errors.
*/

#pragma once
#ifndef ZSCRATCH_PLUGINLOADER_PLUGINERROR
#define ZSCRATCH_PLUGINLOADER_PLUGINERROR

#include "../util/Error.h"

DEFINE_ERROR(PLError_JsonError)
DEFINE_ERROR(PLError_ApiError)

#endif
