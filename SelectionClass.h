#pragma once

#include <QWidget>
#include "ui_SelectionClass.h"
#include "qhostaddress.h"
#include "qdebug.h"
#include "qstring.h"
#include "qfile.h"
#include "qcombobox.h"
#include "qhostinfo.h"
#include "qmessagebox.h"
#include "qprocess.h"
#include "qfiledialog.h"

#include "LoginClass.h"
#include "CheckeClass.h"
#include "qmenu.h"
#include "qmenubar.h"
#include "qaction.h"

class SelectionClass : public QWidget
{
	Q_OBJECT

public:
	SelectionClass(QWidget *parent = Q_NULLPTR);
	~SelectionClass();

private:
	Ui::SelectionClass ui;

public slots:
	void Initialstart();
	QHostAddress getHostAddress();
	void on_choiceButton_clicked();
	void on_ConnectButton_clicked();
	void lookedUp(const QHostInfo& host);
	void changeLanguage(QString language);
	void closethispage();
	void about(bool arg);
};
