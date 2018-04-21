#ifndef QWINDOW_H
#define QWINDOW_H

#include <QMainWindow>

class QWindow : public QMainWindow
{
	Q_OBJECT

public:
	QWindow(QWidget *parent = 0);
	~QWindow();
};

#endif // QWINDOW_H
