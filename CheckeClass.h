#pragma once

#include <QWidget>
#include "ui_CheckeClass.h"
#include "qdebug.h"
#include "qstring.h"
#include "qstringlist.h"
#include "qtcpsocket.h"
#include "qhostaddress.h"
#include "qaction.h"
#include "qlistwidget.h"
#include "qgridlayout.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "mainwindow.h"

#define port1 23245

class CheckeClass : public QWidget, public Ui::CheckeClass
{
	Q_OBJECT

public:
	CheckeClass(QString payam, QHostAddress hostaddress, QString Username, QWidget *parent = Q_NULLPTR);
	~CheckeClass();
public:
	QStringList classlist1;
	QList<QString> classid;
	QList<QString> classname;

public slots:
	void Sendselection(int i);
	QHostAddress getHostaddress();
	QString getUsername();
	bool getsituation();
	QTcpSocket* getSocket();
	QString getclassid();
signals:
	void connec();
};
