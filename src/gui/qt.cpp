/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	qt.cpp
 * @author	Alex Cui
 * @date	April, 2018
 * @details	This file defines the class of QMainWindow.
*/

#include "qt.h"

#include <QPainter>

qtmainwindow::qtmainwindow(QWidget *parent): QMainWindow(parent) {

}

void qtmainwindow::paintEvent(QPaintEvent *event) {
	QPainter *p = new QPainter(this);
	(*this->func)((void*)p);
	//delete p;
}

qtwidget::qtwidget(QWidget *parent) : QWidget(parent)
{

}

void qtwidget::paintEvent(QPaintEvent *event) {
	QPainter *p = new QPainter(this);
	(*this->func)((void*)p);
	//delete p;
}

void WidgetShow(Handle h, WindowShowMode s) {
	qtwidget *w = (qtwidget*)h;
	switch(s) {
	case WindowShowMode::MAX:
		w->showMaximized();
		break;
	case WindowShowMode::MIN:
		w->showMinimized();
		break;
	case WindowShowMode::NORMAL:
		w->showNormal();
		break;
	case WindowShowMode::FULLSCREEN:
		w->showFullScreen();
		break;
	default:
		w->show();
	}
}
