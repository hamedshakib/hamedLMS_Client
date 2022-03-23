#include "CheckeClass.h"

QString Username12;
QTcpSocket* permitsocket;
bool Professor = false;
QHostAddress hostadderss1;
QString classid1;

CheckeClass::CheckeClass(QString payam, QHostAddress hostaddress, QString Username, QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	this->setWindowTitle("Hamed Lms");
	this->setWindowIcon(QIcon(":/mainwindow/icon_ha/28-512.png"));
	Username12 = Username;
	hostadderss1 = hostaddress;
	if (payam.at(0) == '+')
		Professor = true;
	payam.remove(0, 1);

	while (payam.indexOf("@@") != -1) {
		classlist1 << payam.mid(0, payam.indexOf("@@"));
		payam.remove(0, payam.indexOf("@@") + 2);
	}

	for (int i = 0; i < classlist1.count(); i++) {
		classid.append(classlist1[i].mid(3, classlist1[i].indexOf(",") - 3));
		classlist1[i].remove(0, classlist1[i].indexOf(",") + 1);
		classname.append(classlist1[i].mid(5, classlist1[i].indexOf("@@") - 5));
	}


	for (int i = 0; i < classlist1.count(); ++i) {

		QWidget* widget = new QWidget(this);
		QGridLayout* grid1 = new QGridLayout(this);
		QLabel* lable1 = new QLabel(classname[i], this);
		QPushButton* btn1 = new QPushButton(tr("Enter"), this);
		connect(btn1, &QPushButton::clicked, this, [&, i](int i) {Sendselection(i); });
		btn1->setFixedSize(75, 50);
		grid1->addWidget(lable1, 0, 1);
		grid1->addWidget(btn1, 0, 0);

		widget->setLayout(grid1);




		QListWidgetItem* item = new QListWidgetItem;
		item->setSizeHint(QSize(150, 80));
		Ui::CheckeClass::listWidget->addItem(item);
		Ui::CheckeClass::listWidget->setItemWidget(item, widget);
	}

}

CheckeClass::~CheckeClass()
{
}

void CheckeClass::Sendselection(int i) {
	permitsocket = new QTcpSocket();
	classid1 = classid[i];
	QString payam = "0 U:" + Username12 + ",C:id=" + classid[i] + ",";
	mainwindow* mainwindow1 = new mainwindow();
	permitsocket->connectToHost(hostadderss1, port1);
	permitsocket->waitForConnected(1500);
	permitsocket->write(QByteArray(payam.toUtf8()));
	permitsocket->waitForBytesWritten(1500);
	mainwindow1->show();


	this->close();
}


QHostAddress CheckeClass::getHostaddress() {

	return hostadderss1;

}
QString CheckeClass::getUsername() {

	return Username12;
}

bool CheckeClass::getsituation() {

	return Professor;
}

QTcpSocket* CheckeClass::getSocket() {
	return permitsocket;
}

QString CheckeClass::getclassid() {

	return classid1;
}


