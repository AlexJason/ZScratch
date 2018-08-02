/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	qt.h
 * @author	Alex Cui
 * @date	April, 2018
 * @details	This file defines the class of QMainWindow.
*/

#ifndef QTC_H
#define QTC_H
#include <QApplication>
#include <QMainWindow>
#include <QWidget>

#include "gui.h"

class qtMainWindow :public QMainWindow {
	Q_OBJECT
public:
	explicit qtMainWindow(QWidget *parent = nullptr);
	//virtual void paintEvent(QPaintEvent *event);
public:
	//PaintFunc* func;
signals:

public slots:
};

class qtWidget :public QWidget {
	Q_OBJECT
public:
	explicit qtWidget(QWidget *parent = nullptr);
	//virtual void paintEvent(QPaintEvent *event);
public:
	//PaintFunc* func;
signals:

public slots:
};


#endif // QTC_H
