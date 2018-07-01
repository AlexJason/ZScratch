/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	gui.cpp
 * @author	Alex Cui
 * @date	April, 2018
 * @details	This file defines and instanses some useful class for painting.
*/

#include "gui.h"

#include <QApplication>
#include <QMainWindow>
#include <QPainter>

#include "qt.h"

/*void SetFillFrameColor(QPainter &p, Color frame, Color fill) {
	p.setPen(QColor(frame.r, frame.g, frame.b, frame.a));
	p.setBrush(QColor(fill.r, fill.g, fill.b, fill.a));
}

DLLAPI void DrawRectangle(Handle ph, Point x, Point y, Color fill) {
	DrawRectangle(ph, x, y, fill, fill);
}

DLLAPI void DrawRectangle(Handle ph, Point x, Point y, Color frame, Color fill) {
	QPainter* p = (QPainter*)ph;
	SetFillFrameColor(*p, frame, fill);
	p->drawRect(QRect(QPoint(x.x, x.y), QPoint(y.x, y.y)));
}

DLLAPI void DrawShape(Handle ph, Point point[], size_t s, Color fill) {
	DrawShape(ph, point, s, fill, fill);
}

DLLAPI void DrawShape(Handle ph, Point point[], size_t s, Color frame, Color fill) {
	QPainter* p = (QPainter*)ph;
	SetFillFrameColor(*p, frame, fill);
	QPoint *points = new QPoint[s]();
	for(size_t i = 0; i < s; i++) {
		points[i].setX(point[i].x);
		points[i].setY(point[i].y);
	}
	p->drawPolygon(points, static_cast<int>(s));
}*/
