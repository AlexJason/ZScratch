/**
 * This file is part of ZScratch.
 * ZScratch is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.
 * ZScratch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ZScratch. If not, see <http://www.gnu.org/licenses/>.
 *
 * @file	class.cpp
 * @author	Alex Cui
 * @date	April, 2018
 * @details	This file defines the utilities for painting.
*/

#include "class.h"

#include <cmath>

#include "qt.h"

Color::Color(byte r, byte g, byte b, float a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

Rect::Rect(Point tl, Point br) {
	this->tl = tl;
	this->br = br;
}

Application::Application(int argc, char **argv) {
	this->qApplication = (void*)new QApplication(argc, argv);
}

Application::~Application() {
	delete this->qApplication;
}

int Application::exec() {
	return static_cast<QApplication*>(this->qApplication)->exec();
}

BaseWidget::BaseWidget(Rect rc) {
	this->rc = rc;
	this->qWidget = new qtWidget();
}

void BaseWidget::Show() {
	static_cast<QWidget*>(this->qWidget)->show();
}

Window::Window(Rect rc) :BaseWidget(rc) {

}

Window& Window::SetWindowShowMode(WindowShowMode ws) {
	this->ws = ws;
	return *this;
}

/*Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

Color::Color(long r, long g, long b, byte a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Rect::Rect(Point x, Point y) {
	this->x = x;
	this->y = y;
}

int Rect::getWidth() {
	return std::abs(this->y.x - this->x.x);
}

int Rect::getHeight() {
	return std::abs(this->y.y - this->x.y);
}

Application::Application(int argc, char **argv) {
	auto app = new QApplication(argc, argv);
	this->qtObj = (void*)app;
}

Application::~Application() {
	delete (QApplication*)this->qtObj;
}

int Application::exec() {
	QApplication *app = (QApplication*)this->qtObj;
	return app->exec();
}

BaseWidget::BaseWidget() {

}

Window::Window() {
	auto wnd = new qtmainwindow();
	wnd->func = &this->paintEventFunc;
	this->qtObj = (void*)wnd;
}

Window::Window(Rect rc) :Window() {
	this->area = rc;
}

Window::~Window() {
	delete (qtmainwindow*)this->qtObj;
}

char* BaseWidget::getTitle() { return this->title; }
Rect BaseWidget::getArea() { return this->area; }
Handle BaseWidget::getHandle() { return this->qtObj; }
PaintFunc BaseWidget::getPaintEvent() { return this->paintEventFunc; }
PaintFunc BaseWidget::getClickEvent() { return this->clickEventFunc; }
PaintFunc BaseWidget::getMoveEvent() { return this->moveEventFunc; }
BaseWidget& BaseWidget::setTitle(const char *title, size_t l) { strcpy_s(this->title, l, title); Update(TITLE); return *this; }
BaseWidget& BaseWidget::setArea(Rect rc) { this->area = rc; Update(AREA); return *this; }
BaseWidget& BaseWidget::setPaintEvent(PaintFunc func) { this->paintEventFunc = func; return *this; }
BaseWidget& BaseWidget::setClickEvent(PaintFunc func) { this->clickEventFunc = func; return *this; }
BaseWidget& BaseWidget::setMoveEvent(PaintFunc func) { this->moveEventFunc = func; return *this; }

void BaseWidget::Update(UpdateType ut) {
	auto t = (qtmainwindow*)this->qtObj;
	if(ut & AREA)
		t->setGeometry(QRect(area.x.x, area.x.y, area.getWidth(), area.getHeight()));
	if(ut & TITLE)
		t->setWindowTitle(QString(this->title));
}

void Window::Show(WindowShowMode showmode) {
	WidgetShow(this->qtObj, showmode);
}

void Window::Destroy(int exitcode) {
}

Widget::Widget(Window *parent) {
	auto wnd = new qtwidget((QWidget*)parent->getHandle());
	wnd->func = &this->paintEventFunc;
	this->qtObj = (void*)wnd;
}

Widget::Widget(Window *parent, Rect rc) :Widget(parent) {
	this->area = rc;
}

Widget::~Widget() {
	delete (qtwidget*)this->qtObj;
}

void Widget::Show(WindowShowMode showmode) {

}

void Widget::Destroy(int exitcode) {

}*/

