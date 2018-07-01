/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	class.h
 * @author	Alex Cui
 * @date	April, 2018
 * @details	This file defines the utilities for painting.
*/
#pragma once
#ifndef GUI_CLASS_H
#define GUI_CLASS_H
#include "dlldef.h"

#include <string>

#include "gui.h"


class DLLAPI Color {
public:
	Color(byte r = 0, byte g = 0, byte b = 0, float a = 1);
public:
	byte b;
	byte g;
	byte r;
	float a;
};

class DLLAPI Point {
public:
	Point(int x = 0, int y = 0);
public:
	int x;
	int y;
};

class DLLAPI Rect {
public:
	Rect(Point tl = Point(0, 0), Point br = Point(0, 0));
public:
	Point tl;//Top-Left
	Point br;//Bottom-Right
};

class DLLAPI Application {
public:
	Application(int argc, char **argv);
	~Application();
	int exec();
public:
	QtObject qApplication;
};

class DLLAPI BaseWidget {
public:
	BaseWidget(Rect rc);
	void Show();
public:
	QtObject qWidget;
	Rect rc;
};

class DLLAPI Window :public BaseWidget {
public:
	Window(Rect rc);
	Window& SetWindowShowMode(WindowShowMode ws);
public:
	WindowShowMode ws;
};

class DLLAPI Widget :public BaseWidget {
public:

};

class DLLAPI Button :public BaseWidget {
public:

};

class DLLAPI Label :public BaseWidget {
public:

};

class DLLAPI Input :public BaseWidget {
public:

};


/*class DLLAPI Point {
public:
	Point() = default;
	Point(int x, int y);
public:
	int x;
	int y;
};

class DLLAPI Color {
public:
	using byte = unsigned char;
public:
	Color() = default;
	Color(long r, long g, long b, byte a = 255);
public:
	long r;
	long g;
	long b;
	byte a;
};

class DLLAPI Rect {
public:
	Rect() = default;
	Rect(Point x, Point y);
	int getHeight();
	int getWidth();
public:
	Point x;
	Point y;
};

class DLLAPI Application {
public:
	Application(int argc, char **argv);
	~Application();
	int exec();
protected:
	Handle qtObj;
};

class DLLAPI BaseWidget {
public:
	enum UpdateType { AREA = 0x01, TITLE = 0x02 };
public:
	BaseWidget();
public:
	//Get-Function
	char* getTitle();
	Rect getArea();
	Handle getHandle();
	PaintFunc getPaintEvent();
	PaintFunc getClickEvent();
	PaintFunc getMoveEvent();
	//Set-Function
	BaseWidget& setTitle(const char *title, size_t l);
	BaseWidget& setArea(Rect rc);
	BaseWidget& setPaintEvent(PaintFunc func);
	BaseWidget& setClickEvent(PaintFunc func);
	BaseWidget& setMoveEvent(PaintFunc func);
	//Undefined-Function
	virtual void Update(UpdateType t);
	virtual void Show(WindowShowMode showmode) = 0;
	virtual void Destroy(int exitcode) = 0;
protected:
	//Action-Function
	//virtual inline void paintEvent(Handle h) { this->paintEventFunc(h); }
	//virtual inline void clickEvent(Handle h) { this->clickEventFunc(h); }
	//virtual inline void moveEvent(Handle h) { this->moveEventFunc(h); }
protected:
	Handle qtObj;
	char title[512];
	Rect area;
	PaintFunc paintEventFunc;
	PaintFunc clickEventFunc;
	PaintFunc moveEventFunc;
};

class DLLAPI Window :public BaseWidget {
public:
	Window();
	Window(Rect rc);
	~Window();
	virtual void Show(WindowShowMode showmode = WindowShowMode::NORMAL) override final;
	virtual void Destroy(int exitcode) override final;
};

class DLLAPI Widget :public BaseWidget {
public:
	Widget(Window *parent);
	Widget(Window *parent, Rect rc);
	~Widget();
	virtual void Show(WindowShowMode showmode = WindowShowMode::NORMAL) override final;
	virtual void Destroy(int exitcode) override final;
};*/

#endif // GUI_CLASS_H


