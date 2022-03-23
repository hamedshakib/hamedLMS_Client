#pragma once

#include <QWidget>
#include "ui_LoginClass.h"
#include "SelectionClass.h"
#include "qtcpsocket.h"
#include "CheckeClass.h"

#define port1 23245

class LoginClass : public QWidget, public Ui::LoginClass
{
	Q_OBJECT

public:
	LoginClass(QWidget *parent = Q_NULLPTR);
	~LoginClass();

public:
	QTcpSocket* permitsocket;
	CheckeClass* checkclass1;
	QHostAddress ip;

public slots:
	void on_pushButton_clicked();
	void Login(QString Username, QString password);
	void readfirstdata();
};
