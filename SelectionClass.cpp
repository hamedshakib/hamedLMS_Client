#include "SelectionClass.h"

QHostAddress hostaddress;
LoginClass* login1;

SelectionClass::SelectionClass(QWidget *parent)
	: QWidget(parent)
{
	this->setWindowTitle("Hamed Lms");
	this->setWindowIcon(QIcon(":/mainwindow/icon_ha/28-512.png"));
	ui.setupUi(this);
	QMenuBar* menuBar1 = new QMenuBar(this);
	QMenu* About = new QMenu(tr("About"));
	menuBar1->addMenu(About);
	QAction* Action = new QAction(QIcon(":/mainwindow/icon_ha/icons8-about-96.png"), tr("About Application"), this);
	About->addAction(Action);
	connect(Action, &QAction::triggered, this, &SelectionClass::about);
	QFile file("loglan");
	if (file.open(QIODevice::ReadOnly))
		if (file.readAll() == "1") {
			ui.comboBox->setCurrentIndex(1);
		}
	Initialstart();
}

SelectionClass::~SelectionClass()
{
}

void SelectionClass::Initialstart() {
	QFile file1("addresssaved");
	if (file1.exists())
	{
		file1.open(QIODevice::ReadOnly);
		ui.lineEdit->setText(file1.readAll());
		file1.close();
	}

	connect(ui.comboBox, &QComboBox::currentTextChanged, this, &SelectionClass::changeLanguage);
}


void SelectionClass::on_ConnectButton_clicked() {
	if (ui.checkBox->isChecked()) {
		QFile file1;
		file1.setFileName("addresssaved");
		if (file1.open(QIODevice::ReadWrite))
		{
			file1.resize(0);
			QTextStream stream(&file1);
			stream << ui.lineEdit->text();

			file1.close();
		}
		QHostInfo::lookupHost(ui.lineEdit->text(),this, SLOT(lookedUp(QHostInfo)));
	}

	if (ui.lineEdit->text() != "") {
		if (hostaddress == QHostAddress(""))
			hostaddress = ui.lineEdit->text();
		login1 = new LoginClass();
		login1->show();
		this->hide();
	}

}

QHostAddress SelectionClass::getHostAddress() {
	return hostaddress;
}

void SelectionClass::lookedUp(const QHostInfo& host)
{
	if (host.error() != QHostInfo::NoError) {
		qDebug() << "Lookup failed:" << host.errorString();
		return;
	}

	const auto addresses = host.addresses();
	for (const QHostAddress& address : addresses)
		hostaddress = QHostAddress(address.toString());
}

void SelectionClass::changeLanguage(QString language) {

	QMessageBox msgBox;
	msgBox.setIcon(QMessageBox::Icon::Question);
	msgBox.setWindowTitle("change language");
	msgBox.setText(tr("Do you want Now Restart Program for applying change language?"));
	QPushButton* ok = msgBox.addButton(tr("Yes"), QMessageBox::ButtonRole::YesRole);
	QPushButton* no = msgBox.addButton(tr("No"), QMessageBox::ButtonRole::NoRole);

	QFile* ma = new QFile("loglan");
	ma->open(QIODevice::ReadWrite);
	if (ui.comboBox->currentText() == "English")
		ma->write("0");
	else if (ui.comboBox->currentText() == "Persian")
		ma->write("1");
	ma->close();

	msgBox.exec();

	if (msgBox.clickedButton() == ok) {
		QProcess::startDetached("lmsAZ.exe");
		qApp->closeAllWindows();
	}
}

void SelectionClass::on_choiceButton_clicked() {
	QString filename = QFileDialog::getOpenFileName(this, QString(tr("chooce a hshvc file")), "", "hamed shakib vc file(*.hshvc)");
	//badan
	if (filename != "") {
		//playback1 = new PlaybackClass();
		//playback1->show();
	}
}

void SelectionClass::closethispage() {
	this->close();
}

void SelectionClass::about(bool arg) {
	QMessageBox mesabou1;
	QPixmap pic(":/mainwindow/icon_ha/icon_Qt_78x78px.png");
	mesabou1.setWindowTitle("About");
	mesabou1.setIconPixmap(pic);
	QString mes(tr("this app wrote by hamed shakib"));
	mes = mes + u8"\nhamed shakib Copyright ©2020";
	mesabou1.setText(mes);
	mesabou1.exec();

}