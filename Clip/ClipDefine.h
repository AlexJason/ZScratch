/**
*	Copyright(C) 2017-2018 Alex Cui
*
*	This program is free software : you can redistribute it and/or modify
*	it under the terms of the GNU Affero General Public License as
*	published by the Free Software Foundation, either version 3 of the
*	License, or (at your option) any later version.
*
*	This program is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
*	GNU Affero General Public License for more details.
*
*	You should have received a copy of the GNU Affero General Public License
*	along with this program.If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#ifndef CLIP_DEFINE
#define CLIP_DEFINE

//Customs:
#define allow_api				1
#define allow_winapi			0
#define allow_clip				1
#define allow_clipscript		0
#define allow_c					0
#define allow_keyword			1
#define allow_memory			1
#define allow_token				1
#define allow_statement			1
#define allow_type				1
#define allow_type_longlong		0
#define allow_type_byte			1
#define allow_type_bit			0
#define allow_type_bool			1
#define allow_type_char			1

#ifdef EXPORT
#undef EXPORT
#endif

#if (allow_c == 1)
#define C
#ifdef __cplusplus
#define EXPORT extern "C"
#else
#define EXPORT
#endif
#else
#define EXPORT
#endif

#ifndef _STD
#define _STD ::std::
#endif

#if (allow_api == 1)
#ifndef CLIPAPI
#ifdef CLIP_EXPORTS
#define CLIPAPI __declspec(dllexport) EXPORT
#else
#define CLIPAPI __declspec(dllimport) EXPORT
#endif
#endif
#endif

#if (allow_clip == 1)
#define Clip 201803L
#define __clip 201803L
#endif

#if (allow_clipscript == 1)
#define ClipScript 201803L
#define __clipscript 201803L
#else
#define CLIP_SCRIPT
#endif

#ifdef C
#ifndef __cplusplus
#define bool int
#define true 1
#define false 0
#endif
#endif

#if (allow_type_longlong == 1)
#define CLIP_TYPE_LONGLONG
#endif

#endif
