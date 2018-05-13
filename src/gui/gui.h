/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	gui.h
 * @author	Alex Cui
 * @date	April, 2018
 * @details	This file defines and instanses some useful class for painting.
*/

#ifndef GUI_H
#define GUI_H

#include <string>

#include "dlldef.h"

//The Utility Enum Classes
enum class DLLAPI WindowShowMode { NORMAL, MAX, MIN, FULLSCREEN };

//The Value Classes
typedef unsigned char Byte;
typedef void* Handle;
typedef void(*PaintFunc)(Handle);

//The Window Utility Classes
class DLLAPI Color;
class DLLAPI Point;
class DLLAPI Rect;

//The Window Form Classes
class DLLAPI Application;
class DLLAPI BaseWidget;
class DLLAPI Window;
class DLLAPI Widget;
class DLLAPI Button;

//The Window Painting Functions
DLLAPI void		DrawRectangle(Handle ph, Point x, Point y, Color fill);
DLLAPI void		DrawRectangle(Handle ph, Point x, Point y, Color frame, Color fill);
DLLAPI void		DrawShape(Handle ph, Point point[], size_t s, Color fill);
DLLAPI void		DrawShape(Handle ph, Point point[], size_t s, Color frame, Color fill);

//The Class Definition
#include "class.h"

#endif // GUI_H
