#include "LoginClass.h"

QString classpayam;
QString Username1;

LoginClass::LoginClass(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	this->setWindowTitle("Hamed Lms");
	this->setWindowIcon(QIcon(":/mainwindow/icon_ha/28-512.png"));
}

LoginClass::~LoginClass()
{

}

void LoginClass::Login(QString Username, QString password) {
	SelectionClass selectclass1;
	ip = selectclass1.getHostAddress();
	permitsocket = new QTcpSocket();
	permitsocket->connectToHost(ip, port1);
	permitsocket->waitForConnected(1500);
	QString payam = "0 U:" + Ui::LoginClass::lineEdit->text() + ",P:" + Ui::LoginClass::lineEdit_2->text() + "&&&";
	Username1 = Username;
	permitsocket->write(QByteArray(payam.toUtf8()));
	connect(permitsocket, &QTcpSocket::readyRead, this, &LoginClass::readfirstdata);
}

void LoginClass::on_pushButton_clicked() {
	Login(Ui::LoginClass::lineEdit->text(), Ui::LoginClass::lineEdit_2->text());


}

void LoginClass::readfirstdata() {
	QByteArray payam = permitsocket->readAll();
	if (payam.at(0) == 'Y' && payam.at(1) == 'o' && payam.at(2) == 'u' && payam.at(3) == ' ' && payam.at(4) == 'E' && payam.at(5) == 'n' && payam.at(6) == 't' && payam.at(7) == 'e' && payam.at(8) == 'r' && payam.at(9) == 'e' && payam.at(10) == 'd')
	{
		payam.remove(0, 11);
		classpayam = payam;
		qDebug() << classpayam;
		disconnect(permitsocket, &QTcpSocket::readyRead, this, &LoginClass::readfirstdata);
		permitsocket->deleteLater();
		checkclass1 = new CheckeClass(classpayam, ip, Username1);
		checkclass1->show();
		this->close();
	}
}

