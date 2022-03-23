#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle("Hamed Lms");
    this->setWindowIcon(QIcon(":/mainwindow/icon_ha/28-512.png"));
    ui.pushButton_2->hide();
    ui.pushButton_3->hide();
    ui.pushButton_4->hide();


    QScreen* screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int width = screenGeometry.width();
    int height = screenGeometry.height();
    ui.widget->setMinimumWidth(width * 7 / 10);
    ui.tabWidget->setMinimumWidth(width * 6 / 10);
    ui.splitter_4->setMinimumWidth(width - 10);
    ui.widget->setMinimumWidth(width * 7 / 10);
    ui.splitter_4->setMinimumHeight(height - ui.checkBox->y() - ui.checkBox->height() - 90);
    Initialstart();
    mouselab = new QLabel(this);
}


void mainwindow::Initialstart() {
    CheckeClass* checkclass2;
    permitSocket = checkclass2->getSocket();
    Username1 = checkclass2->getUsername();
    hostadderss1 = checkclass2->getHostaddress();
    Professor = checkclass2->getsituation();
    classid123 = checkclass2->getclassid();
    connect(permitSocket, &QTcpSocket::readyRead, this, &mainwindow::ReadpermitSocket, Qt::ConnectionType::QueuedConnection);
    startlisenVoice();
    Preparationwebcam();
    connect(ui.pushButton_3, &QPushButton::clicked, this, &mainwindow::sendfinish);


    chatSocket = new QTcpSocket(this);
    chatSocket->connectToHost(hostadderss1, port1);
    chatSocket->waitForConnected(1500);
    connect(chatSocket, &QTcpSocket::readyRead, this, &mainwindow::ReadchatSocket, Qt::ConnectionType::QueuedConnection);
    QString payam = "1 U:" + Username1 + ",C:id=" + classid123 + ",";
    chatSocket->write(QByteArray(payam.toUtf8()));
    chatSocket->waitForBytesWritten(1500);

    voiceSocket = new QTcpSocket(this);
    voiceSocket->connectToHost(hostadderss1, port1);
    voiceSocket->waitForConnected(1500);
    connect(voiceSocket, &QTcpSocket::readyRead, this, &mainwindow::ReadvoiceSocket, Qt::ConnectionType::QueuedConnection);
    QString payam1 = "2 U:" + Username1 + ",C:id=" + classid123 + ",";
    voiceSocket->write(QByteArray(payam1.toUtf8()));
    voiceSocket->waitForBytesWritten(1500);

    webcamSocket = new QTcpSocket(this);
    webcamSocket->connectToHost(hostadderss1, port1);
    webcamSocket->waitForConnected(1500);
    connect(webcamSocket, &QTcpSocket::readyRead, this, &mainwindow::ReadwebcamSocket, Qt::ConnectionType::QueuedConnection);
    QString payam2 = "3 U:" + Username1 + ",C:id=" + classid123 + ",";
    webcamSocket->write(QByteArray(payam2.toUtf8()));
    webcamSocket->waitForBytesWritten(1500);

    noteSocket = new QTcpSocket(this);
    noteSocket->connectToHost(hostadderss1, port1);
    noteSocket->waitForConnected(1500);
    connect(noteSocket, &QTcpSocket::readyRead, this, &mainwindow::ReadnoteSocket, Qt::ConnectionType::QueuedConnection);
    QString payam3 = "4 U:" + Username1 + ",C:id=" + classid123 + ",";
    noteSocket->write(QByteArray(payam3.toUtf8()));
    noteSocket->waitForBytesWritten(1500);

    mouseSocket = new QTcpSocket(this);
    mouseSocket->connectToHost(hostadderss1, port1);
    mouseSocket->waitForConnected(1500);
    connect(mouseSocket, &QTcpSocket::readyRead, this, &mainwindow::ReadmouseSocket, Qt::ConnectionType::QueuedConnection);
    QString payam4 = "5 U:" + Username1 + ",C:id=" + classid123 + ",";
    mouseSocket->write(QByteArray(payam4.toUtf8()));
    mouseSocket->waitForBytesWritten(1500);

    sendSocket = new QTcpSocket(this);
    sendSocket->connectToHost(hostadderss1, port1);
    sendSocket->waitForConnected(1500);
    connect(sendSocket, &QTcpSocket::readyRead, this, &mainwindow::ReadsendSocket, Qt::ConnectionType::QueuedConnection);
    QString payam6 = "7 U:" + Username1 + ",C:id=" + classid123 + ",";
    sendSocket->write(QByteArray(payam6.toUtf8()));
    sendSocket->waitForBytesWritten(1500);

    shapeSocket = new QTcpSocket(this);
    shapeSocket->connectToHost(hostadderss1, port1);
    shapeSocket->waitForConnected(1500);
    connect(shapeSocket, &QTcpSocket::readyRead, this, &mainwindow::ReadshapeSocket, Qt::ConnectionType::QueuedConnection);
    QString payam5 = "6 U:" + Username1 + ",C:id=" + classid123 + ",";
    shapeSocket->write(QByteArray(payam5.toUtf8()));
    shapeSocket->waitForBytesWritten(1500);

    attendessSocket = new QTcpSocket(this);
    attendessSocket->connectToHost(hostadderss1, port1);
    attendessSocket->waitForConnected(1500);
    connect(attendessSocket, &QTcpSocket::readyRead, this, &mainwindow::ReadattendessSocket, Qt::ConnectionType::QueuedConnection);
    QString payam7 = "8 U:" + Username1 + ",C:id=" + classid123 + ",";
    attendessSocket->write(QByteArray(payam7.toUtf8()));
    attendessSocket->waitForBytesWritten(1500);

    screenSocket = new QTcpSocket(this);
    screenSocket->connectToHost(hostadderss1, port1);
    screenSocket->waitForConnected(1500);
    connect(screenSocket, &QTcpSocket::readyRead, this, &mainwindow::ReadscreenSocket, Qt::ConnectionType::QueuedConnection);
    QString payam8 = "9 U:" + Username1 + ",C:id=" + classid123 + ",";
    screenSocket->write(QByteArray(payam8.toUtf8()));
    screenSocket->waitForBytesWritten(1500);


    if (Professor == true)
    {
        ui.pushButton_4->show();
        ui.pushButton_3->show();
        ui.pushButton_2->show();

        QPushButton* mousebtn = new QPushButton(this);
        mousebtn->setIcon(QIcon(":/mainwindow/icon_ha/Webp.net-resizeimage.png"));
        mousebtn->setIconSize(QSize(40, 40));
        mousebtn->setGeometry(ui.tabWidget->geometry().width() + 20, 80, 50, 50);
        mousebtn->setCheckable(true);
        connect(mousebtn, &QPushButton::clicked, this, [&, mousebtn]() {on_mousebtn_clicked(mousebtn); });
        //QPushButton* kahtchinbtn = new QPushButton( this);
        //kahtchinbtn->setIcon(QIcon(":/mainwindow/icon_ha/25.jpg"));
        //kahtchinbtn->setIconSize(QSize(40, 40));
        //kahtchinbtn->setGeometry(ui.tabWidget->geometry().width() + 20, 80 + 50 + 20, 50, 50);
        QPushButton* khatbtn = new QPushButton(this);
        khatbtn->setIcon(QIcon(":/mainwindow/icon_ha/Editing-Line-icon.png"));
        khatbtn->setIconSize(QSize(40, 40));
        khatbtn->setGeometry(ui.tabWidget->geometry().width() + 20, 80 + 50 + 20, 50, 50);
        khatbtn->setCheckable(1);
        connect(khatbtn, &QPushButton::clicked, this, [&, khatbtn]() {on_khatbtn_clicked(khatbtn); });
        QPushButton* morababtn = new QPushButton(this);
        morababtn->setIcon(QIcon(":/mainwindow/icon_ha/shape_square.png"));
        morababtn->setIconSize(QSize(40, 40));
        morababtn->setGeometry(ui.tabWidget->geometry().width() + 20, 220, 50, 50);
        connect(morababtn, &QPushButton::clicked, this, [&, morababtn]() {on_morababtn_clicked(morababtn); });
        QPushButton* dayerebtn = new QPushButton(this);
        dayerebtn->setIcon(QIcon(":/mainwindow/icon_ha/red-drawn-circle-png-4.png"));
        dayerebtn->setIconSize(QSize(40, 40));
        dayerebtn->setGeometry(ui.tabWidget->geometry().width() + 20, 290, 50, 50);
        connect(dayerebtn, &QPushButton::clicked, this, [&, dayerebtn]() {on_dayerebtn_clicked(dayerebtn); });
        QPushButton* medadbtn = new QPushButton(this);
        medadbtn->setIcon(QIcon(":/mainwindow/icon_ha/cell-2-0-480.png"));
        medadbtn->setIconSize(QSize(40, 40));
        medadbtn->setGeometry(ui.tabWidget->geometry().width() + 20, 360, 50, 50);
        medadbtn->setCheckable(true);
        connect(medadbtn, &QPushButton::clicked, this, [&, medadbtn]() {on_medadbtn_clicked(medadbtn); });
        QPushButton* pakkonbtn = new QPushButton(this);
        pakkonbtn->setIcon(QIcon(":/mainwindow/icon_ha/24-512.png"));
        pakkonbtn->setIconSize(QSize(40, 40));
        pakkonbtn->setGeometry(ui.tabWidget->geometry().width() + 20, 430, 50, 50);
        pakkonbtn->setCheckable(true);
        connect(pakkonbtn, &QPushButton::clicked, this, [&, pakkonbtn]() {on_pakkonbtn_clicked(pakkonbtn); });
        QPushButton* matnbtn = new QPushButton(this);
        matnbtn->setIcon(QIcon(":/mainwindow/icon_ha/Editing-Text-icon.png"));
        matnbtn->setIconSize(QSize(35, 35));
        matnbtn->setGeometry(ui.tabWidget->geometry().width() + 20, 500, 50, 50);
        //ui.tabWidget->setTabsClosable(true);
        connect(matnbtn, &QPushButton::clicked, this, [&, matnbtn]() {on_matnbtn_clicked(matnbtn); });

        newContent();
        ui.plainTextEdit->setReadOnly(false);
        connect(ui.plainTextEdit, &QPlainTextEdit::textChanged, this, &mainwindow::sendnote);
        connect(ui.tabWidget, &QTabWidget::currentChanged, this, &mainwindow::sendcurrenttabAndContent);
        ui.checkBox->hide();
    }
    else
    {
        connect(ui.checkBox, &QCheckBox::stateChanged, this, &mainwindow::changesync);
        changesync();
        ui.Screenbtn->setHidden(true);
    }


    connect(ui.comboBox, &QComboBox::currentTextChanged, this, &mainwindow::sendStatus);
    connect(ui.pushButton, &QPushButton::clicked, this, &mainwindow::sendchat);
    colorAndSize();
}

void mainwindow::ReadpermitSocket() {
    QString payam = permitSocket->readAll();
    if (payam.at(0) == 'A' && payam.at(1) == ' ')
    {
        payam.remove(0, 2);
        microphone = payam.mid(0, 1).toInt();
        payam.remove(0, 2);
        webcam = payam.mid(0, 1).toInt();
        payam.remove(0, 2);
        content = payam.mid(0, 1).toInt();
        payam.remove(0, 2);

        if (microphone == true) {
            Preparationsendvoice();
        }
        if (webcam == true) {
            Preparationwebcam();
        }
        if (content == false) {
            for (int i = 0; i < tabwidget1.count(); i++)
                if (tabwidget1[i].name == "new tab") {
                    ui.tabWidget->removeTab(i);
                    tabwidget1.remove(i);
                }
        }
        else if (content == true && Professor == false) {

            newContent();

        }
    }
    if (payam.indexOf("Duplicate entry") != -1) {
        QMessageBox::StandardButton but1 = QMessageBox::critical(this, "Duplicate Entry", tr("You entered from somewhere else!"), QMessageBox::StandardButton::Close);
        if (but1 == QMessageBox::StandardButton::Close)
            qApp->exit();
    }
    if (payam.indexOf("FinishClass") != -1)
    {
        QMessageBox::StandardButton but1 = QMessageBox::information(this, "finished class", tr("Class end with the host announced"), QMessageBox::StandardButton::Close);
        if (but1 == QMessageBox::StandardButton::Close)
            qApp->exit();
    }
}

void mainwindow::ReadchatSocket() {
    QByteArray payam = chatSocket->readAll();
    while (payam.indexOf("^@!@!#"))
    {
        QString name = payam.mid(0, payam.indexOf(","));
        payam.remove(0, payam.indexOf(",") + 1);
        QString time = payam.mid(0, payam.indexOf(","));
        payam.remove(0, payam.indexOf(",") + 1);
        QString matn = payam.mid(0, payam.indexOf("^@!@!#"));
        payam.remove(0, payam.indexOf("^@!@!#") + 6);

        QWidget* widget = new QWidget(this);
        QGridLayout* grid1 = new QGridLayout(this);
        QString nametime = name + "\n" + time;
        QLabel* lable4 = new QLabel(nametime, this);
        QTextEdit* text = new QTextEdit(this);
        text->setText(matn);
        text->setReadOnly(1);
        text->setStyleSheet("background-color: rgb(233, 255, 208)");
        grid1->addWidget(text, 0, 0);
        grid1->addWidget(lable4, 0, 1);

        widget->setLayout(grid1);

        QListWidgetItem* item = new QListWidgetItem;
        int hi = 47 + (matn.length() / 20) * 9;
        item->setSizeHint(QSize(150, hi));
        ui.listWidget->addItem(item);
        ui.listWidget->setItemWidget(item, widget);

        ui.listWidget->verticalScrollBar()->setValue(ui.listWidget->verticalScrollBar()->maximum());
        if (payam.isEmpty())
            break;
    }
}

void mainwindow::ReadvoiceSocket() {
    QByteArray payam = voiceSocket->readAll();
    output_device->write(payam);
}

void mainwindow::ReadwebcamSocket() {
    Allwebcamdata1 = Allwebcamdata1 + webcamSocket->readAll();
    while (Allwebcamdata1.indexOf("&&") != -1 && Allwebcamdata1.indexOf("$$") != -1)
    {
        int sh = Allwebcamdata1.indexOf("&&");
        int pa = Allwebcamdata1.indexOf("$$");
        QByteArray payam;
        payam = Allwebcamdata1.mid(sh + 2, pa - sh);
        QPixmap pixmap1;
        if (pixmap1.loadFromData(payam)) {
            pixmap1 = pixmap1.transformed(QTransform().scale(-1, 1));
            ui.label_3->setPixmap(pixmap1.scaled(ui.label_3->width(), ui.label_3->height(), Qt::KeepAspectRatio));
        }
        Allwebcamdata1.remove(0, pa + 2);
    }

    if (Allwebcamdata1.indexOf("##off##") != -1)
    {
        ui.label_3->setPixmap(QPixmap(":/mainwindow/icon_ha/images1.jpg"));
        Allwebcamdata1.remove(Allwebcamdata1.indexOf("##off##"), 7);
    }

}

void mainwindow::ReadnoteSocket() {
    QString payam = noteSocket->readAll();
Y:
    if (payam.at(0) == '@' && payam.at(1) == '@' && payam.at(2) == '@' && payam.at(3) == '@' && payam.at(4) == '@' && payam.at(5) == '@' && payam.at(6) == '@')
    {
        payam.remove(0, 7);
        if (payam.at(0) == 't' && payam.at(1) == ' ') {
            payam.remove(0, 2);
            QString tim = tr("Session time: ") + "<b>" + payam.mid(0, payam.indexOf(",")) + "</b>";
            ui.label_8->setText(tim);
            payam.remove(0, payam.indexOf(",") + 1);
        }
        else if (payam.at(0) == 'n' && payam.at(1) == ' ')
        {
            payam.remove(0, 2);
            ui.label_7->setText(payam.mid(0, payam.indexOf("&^&")));
            payam.remove(0, payam.indexOf("&^&") + 3);
        }
        if (payam.isEmpty() != true)
            goto Y;
    }
    else
        ui.plainTextEdit->setPlainText(payam);
}

void mainwindow::ReadmouseSocket() {
    QByteArray payam = mouseSocket->readAll();
    if (payam.at(0) == '*' && payam.at(1) == '*' && payam.at(2) == 'X' && payam.at(3) == ':')
    {
        float nesbatX = payam.mid(4, payam.indexOf("&") - 4).toFloat();
        payam.remove(0, payam.indexOf("&") + 3);
        float nesbatY = payam.mid(0, payam.indexOf("&&")).toFloat();
        payam.remove(0, payam.indexOf("&&") + 2);


        int x = nesbatX * ui.tabWidget->width();
        int y = nesbatY * ui.tabWidget->height();

        mouselab->setPixmap(QPixmap(":/mainwindow/icon_ha/Webp.net-resizeimage.png"));
        mouselab->setGeometry(x - 15, y + 35, 40, 40);
        mouselab->show();
    }
    if (payam.indexOf("##off##") != -1)
    {
        mouselab->hide();
    }
}

void mainwindow::ReadshapeSocket() {
    QString data = shapeSocket->readAll();
    if (data.indexOf("###") != -1 && data.indexOf("!&&&") != -1);
    {
        QString payam = data.mid(data.indexOf("###") + 3, data.indexOf("!&&&") - data.indexOf("###") + 1);
        payam.remove(0, 5);
        QString name = payam.mid(0, payam.indexOf("*"));
        payam.remove(0, payam.indexOf("*") + 1 + 5);
        int page = payam.mid(0, payam.indexOf("!")).toInt();
        payam.remove(0, payam.indexOf("!") + 1 + 10);
        int virScroll = payam.mid(0, payam.indexOf("horScroll")).toInt();
        payam.remove(0, payam.indexOf("horScroll") + 10);
        int horScroll = payam.mid(0, payam.indexOf("zoom")).toInt();
        payam.remove(0, payam.indexOf("zoom") + 5);
        int zoom = payam.mid(0, payam.indexOf("!&&&")).toInt();
        data.remove(data.indexOf("###"), data.indexOf("!&&&") - data.indexOf("###") + 4);


        lastContent.name = name;
        lastContent.page = page;
        lastContent.verscroll = virScroll;
        lastContent.horscroll = horScroll;
        lastContent.zoom = zoom;



        if (ui.checkBox->isChecked()) {
            for (int i = 0; i < ui.tabWidget->count(); i++)
                if (ui.tabWidget->tabText(i) == name) {
                    ui.tabWidget->setCurrentIndex(i);
                }
            for (int i = 0; i < tabwidget1.count(); i++)
                if (tabwidget1[i].name == name) {
                    tabwidget1[i].pagespin->setValue(page);
                    tabwidget1[i].scrollArea->verticalScrollBar()->setValue(virScroll);
                    tabwidget1[i].scrollArea->horizontalScrollBar()->setValue(horScroll);
                    tabwidget1[i].Sliderzoom->setValue(zoom);
                    initialEntered = 1;

                }
        }
    }


}

void mainwindow::ReadsendSocket() {
    Allsended = Allsended.append(sendSocket->readAll());

    if (Allsended.indexOf("#$#") != -1 && Allsended.indexOf("##!#") != -1)
    {
        // new file
        QString payam = Allsended.mid(Allsended.indexOf("#$#") + 3, Allsended.indexOf("##!#") - (Allsended.indexOf("#$#") + 3));
        int type = payam.mid(0, 1).toInt();
        payam.remove(0, 2);
        QString namefile = payam.mid(0, payam.indexOf("*"));
        payam.remove(0, payam.indexOf("*") + 1);
        int numberpage;
        if (type == 0)
        {
            numberpage = payam.mid(0, payam.indexOf("##!#")).toInt();

            tabwidget1.append(Tabwidget());
            PDFContent(namefile, numberpage);
        }
        payam.remove(0, payam.indexOf("##!#") + 4);



        Allsended.remove(Allsended.indexOf("#$#"), Allsended.indexOf("##!#") - Allsended.indexOf("#$#") + 4);
    }
    if (Allsended.indexOf("@@**@") != -1 && Allsended.indexOf("@*@*@") != -1)
    {
        QByteArray payam = Allsended.mid(Allsended.indexOf("@@**@") + 5, Allsended.indexOf("@*@*@") - (Allsended.indexOf("@@**@") + 5));
        QString namefile = payam.mid(0, payam.indexOf("*"));
        payam.remove(0, payam.indexOf("*") + 1);
        int page = payam.mid(0, payam.indexOf(",")).toInt();
        payam.remove(0, payam.indexOf(",") + 1);
        QByteArray data = payam.mid(0, payam.indexOf("@*@*@"));

        //kamel shavad
        lab = new QLabel(this);
        QPixmap pix1;
        pix1.loadFromData(data);
        QSize sizeSet(610, 788);


        float zarib = 0.5;
        for (int i = 0; i < tabwidget1.count(); i++) {
            if (tabwidget1[i].name == namefile) {
                if (pix1.width() < 900)
                    zarib = 1;
                lab->setPixmap(pix1.scaled(pix1.width() * zarib * (float)tabwidget1[i].Sliderzoom->value() / 100, pix1.height() * zarib * (float)tabwidget1[i].Sliderzoom->value() / 100, Qt::KeepAspectRatio));
                lab->setFixedSize(QSize(pix1.width() * zarib * (float)tabwidget1[i].Sliderzoom->value() / 100, pix1.height() * zarib * (float)tabwidget1[i].Sliderzoom->value() / 100));
                tabwidget1[i].lastlab = lab;

                tabwidget1[i].scrollArea->setWidget(lab);
                if (initialEntered == true && lastContent.name != "")
                {
                    if (lastContent.page != page)
                        tabwidget1[i].pagespin->setValue(lastContent.page);
                    tabwidget1[i].Sliderzoom->setValue(lastContent.zoom);
                    tabwidget1[i].scrollArea->verticalScrollBar()->setValue(lastContent.verscroll);
                    tabwidget1[i].scrollArea->horizontalScrollBar()->setValue(lastContent.horscroll);

                }

            }
        }


        Allsended.remove(Allsended.indexOf("@@**@"), Allsended.indexOf("@*@*@") - Allsended.indexOf("@@**@") + 5);
        if (lastContent.page == page)
            if (Allsended.indexOf("@@**@") == -1 && Allsended.indexOf("@*@*@") == -1) {
                initialEntered = false;
            }
    }



}

void mainwindow::ReadattendessSocket() {
    QString payam1 = attendessSocket->readAll();
    qDebug() << "All payam:" << payam1;
    QString payam;
    while (!payam1.isEmpty())
    {
        payam = payam1.mid(0, payam1.indexOf("%%"));
        payam1.remove(0, payam1.indexOf("%%") + 2);
    }
    qDebug() << "payam asli:" << payam;
    for (int i = 0; i < payam.length(); i++)
        ui.listWidget_2->clear();
        int numberperson = 0;

        while (payam.indexOf("@"))
        {
            bool ostad = false;
            QString Username12 = payam.mid(0, payam.indexOf("^"));
            payam.remove(0, payam.indexOf("^") + 1);
            QString name = payam.mid(0, payam.indexOf(",,"));
            payam.remove(0, payam.indexOf(",,") + 2);
            bool allow = payam.mid(0, 1).toInt();
            payam.remove(0, 2);
            bool use = payam.mid(0, 1).toInt();
            payam.remove(0, 2);
            int status = payam.mid(0, 1).toInt();
            payam.remove(0, 1);
            if (payam.at(0) == '+') {
                ostad = true;
                payam.remove(0, 1);
            }
            payam.remove(0, 1);

            QWidget* widget = new QWidget(this);
            QGridLayout* grid1 = new QGridLayout(widget);
            QLabel* lable1 = new QLabel(name, widget);
            QLabel* lable2 = new QLabel("", widget);
            QPixmap d;
            switch (status)
            {
            case 1: d = QPixmap(":/mainwindow/icon_ha/402-512.png"); break;
            case 2: d = QPixmap(":/mainwindow/icon_ha/close-512.png"); break;
            case 3: d = QPixmap(":/mainwindow/icon_ha/icons8-happy-100.png"); break;
            case 4: d = QPixmap(":/mainwindow/icon_ha/icons8-sad-100.png"); break;
            case 5: d = QPixmap(":/mainwindow/icon_ha/pngkey.com-thumb-up-icon-png-6501721.png"); break;
            case 6: d = QPixmap(":/mainwindow/icon_ha/no-headphones.png"); break;
            }
            if (Professor == true && ostad == false) {
                QPushButton* btn1 = new QPushButton("", widget);
                btn1->setIcon(QIcon(":/mainwindow/icon_ha/Gear-512.png"));
                btn1->setIconSize(QSize(30, 30));
                btn1->setFixedSize(35, 35);
                connect(btn1, &QPushButton::clicked, this, [&, Username12, name]() {btnPerson(Username12, name); });
                grid1->addWidget(btn1, numberperson, 1);
            }

            lable2->setPixmap(d.scaled(30, 30, Qt::KeepAspectRatio));
            grid1->addWidget(lable2, numberperson, 0);

            QListWidgetItem* item = new QListWidgetItem;

            if (allow == false && use == false && Username1 == Username12)
            {
                input_voice->stop();
                if (camera1 != nullptr)
                    camera1->stop();
            }

            /*az*/if (allow == false && use == false || ostad == true) {
                grid1->addWidget(lable1, numberperson, 2);
                widget->setLayout(grid1);
                item->setSizeHint(QSize(150, 50));
            }

            else if (allow == true && use == false)
            {
                if (Username1 != Username12) {
                    QString gy = "" + name + tr(" Not emittion Audio/Video");
                    QLabel* label5 = new QLabel(gy, widget);
                    label5->setWordWrap(true);
                    if (Professor != true) {
                        grid1->addWidget(lable1, numberperson, 1);
                        grid1->addWidget(label5, numberperson + 1, 0, 1, 2);
                    }
                    if (Professor == true) {
                        grid1->addWidget(lable1, numberperson, 2);
                        grid1->addWidget(label5, numberperson + 1, 0, 1, 3);
                    }

                    widget->setLayout(grid1);
                    item->setSizeHint(QSize(150, 150));
                }
                if (Username1 == Username12)
                {
                    QPushButton* pushbtn = new QPushButton(tr("Emittion"), widget);
                    QToolButton* toolbtn = new QToolButton(widget);
                    toolbtn->setIcon(QIcon(":/mainwindow/icon_ha/Gear-512.png"));
                    toolbtn->setIconSize(QSize(18, 18));
                    grid1->addWidget(lable1, numberperson, 2);
                    connect(pushbtn, &QPushButton::clicked, this, [&, Username12, name, pushbtn]() {
                        QString payamtoserver = "U ";
                        if (pushbtn->text() == tr("Emittion"))
                        {

                            input_device = input_voice->start();
                            connect(input_device, SIGNAL(readyRead()), this, SLOT(sendvoiceToServer()));
                            if (camera1 != nullptr)
                                camera1->start();
                            timerwebcam->start();

                            payamtoserver = payamtoserver + "1,";
                            if (camera1 != nullptr)
                                payamtoserver = payamtoserver + "1,";
                            else
                                payamtoserver = payamtoserver + "0,";
                            pushbtn->setText(tr("Stop"));
                        }

                        else if (pushbtn->text() == tr("Stop")) {
                            input_voice->stop();
                            if (camera1 != nullptr) {
                                camera1->stop();
                                QString pam("##off##");
                                webcamSocket->write(QByteArray(pam.toUtf8()));
                            }
                            timerwebcam->stop();

                            payamtoserver = payamtoserver + "0,0,";

                            ui.label_3->setPixmap(QPixmap(":/mainwindow/icon_ha/images1.jpg"));
                            pushbtn->setText(tr("Emittion"));

                        }
                        permitSocket->write(QByteArray(payamtoserver.toUtf8()));
                        });
                    connect(toolbtn, &QToolButton::clicked, this, [&, Username12, name, pushbtn]() {
                        QDialog* dialog1 = new QDialog(this);
                        QGridLayout* layout1 = new QGridLayout(dialog1);

                        QLabel* lable2 = new QLabel(tr("Microphone:"), dialog1);
                        QComboBox* comboxMicrophone = new QComboBox(dialog1);

                        const auto deviceInfos = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
                        for (const QAudioDeviceInfo& deviceInfo : deviceInfos)
                            if (comboxMicrophone->findText(deviceInfo.deviceName()) == -1)
                                comboxMicrophone->addItem(deviceInfo.deviceName());
                        if (microphone == true) {
                            layout1->addWidget(lable2, 1, 0);
                            layout1->addWidget(comboxMicrophone, 1, 1);

                        }

                        QLabel* lable3 = new QLabel(tr("Webcam:"), dialog1);
                        QComboBox* comboxwebcam = new QComboBox(dialog1);
                        comboxwebcam->addItem(tr("Webcam not allowed"));
                        const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
                        for (const QCameraInfo& cameraInfo : cameras)
                            comboxwebcam->addItem(cameraInfo.description());

                        QComboBox* Webcamresolution = new QComboBox(dialog1);
                        Webcamresolution->addItem(tr("Default"));
                        Webcamresolution->addItem("100*100");
                        Webcamresolution->addItem("120*100");
                        Webcamresolution->addItem("200*200");
                        Webcamresolution->addItem("250*250");
                        Webcamresolution->addItem("300*300");
                        Webcamresolution->addItem("350*350");

                        lable3->setHidden(true);
                        comboxwebcam->setHidden(true);
                        Webcamresolution->setHidden(true);
                        if (webcam == true) {
                            lable3->setHidden(false);
                            comboxwebcam->setHidden(false);
                            Webcamresolution->setHidden(false);
                            layout1->addWidget(lable3, 2, 0);
                            layout1->addWidget(comboxwebcam, 2, 1);
                            layout1->addWidget(Webcamresolution, 3, 1);

                        }

                        QPushButton* ok_btn = new QPushButton(tr("Ok"), dialog1);
                        layout1->addWidget(ok_btn, 4, 0);
                        dialog1->setLayout(layout1);
                        dialog1->show();
                        connect(ok_btn, &QPushButton::clicked, this, [&, pushbtn, dialog1, comboxMicrophone, comboxwebcam, Webcamresolution, deviceInfos, cameras]() {
                            if (pushbtn->text() == tr("Emittion"))
                            {
                                if (microphone == true)
                                {
                                    for (const QAudioDeviceInfo& deviceInfo : deviceInfos)
                                        if (deviceInfo.deviceName() == comboxMicrophone->currentText())
                                        {
                                            QAudioFormat formatofinput;
                                            formatofinput.setSampleRate(44100);
                                            formatofinput.setChannelCount(2);
                                            formatofinput.setSampleSize(16);
                                            formatofinput.setCodec("audio/pcm");
                                            formatofinput.setByteOrder(QAudioFormat::LittleEndian);
                                            formatofinput.setSampleType(QAudioFormat::SignedInt);
                                            if (!deviceInfo.isFormatSupported(formatofinput))
                                                formatofinput = deviceInfo.nearestFormat(formatofinput);
                                            input_voice = new QAudioInput(deviceInfo, formatofinput, this);
                                            input_voice->setBufferSize(16384);
                                            break;
                                        }

                                }

                                if (webcam == true) {
                                    if (comboxwebcam->currentText() != tr("Webcam not allowed")) {
                                        for (const QCameraInfo& cameraInfo : cameras)
                                            if (cameraInfo.description() == comboxwebcam->currentText())
                                            {
                                                camera1 = new QCamera(cameraInfo, this);
                                                camera1->setViewfinder(cameraviewfinder1);
                                                connect(timerwebcam, &QTimer::timeout, this, &mainwindow::sendwebcam);
                                            }
                                    }
                                    else {
                                        camera1->deleteLater();
                                        camera1 = nullptr;
                                        disconnect(timerwebcam, &QTimer::timeout, this, &mainwindow::sendwebcam);
                                    }

                                    QString resulayion = Webcamresolution->currentText();
                                    if (resulayion != tr("Default")) {
                                        camera1->stop();
                                        int with = resulayion.mid(0, resulayion.indexOf("*")).toInt();
                                        resulayion.remove(0, resulayion.indexOf("*") + 1);
                                        int height = resulayion.mid(0).toInt();
                                        cameraviewfinder1->setFixedSize(with, height);
                                    }
                                    else
                                        cameraviewfinder1->setFixedSize(ui.splitter->width(), ui.splitter->width());
                                }
                            }
                            dialog1->close();
                            });
                        });
                    grid1->addWidget(pushbtn, numberperson + 1, 0, 1, 2);
                    grid1->addWidget(toolbtn, numberperson + 1, 2);
                }
                widget->setLayout(grid1);
                item->setSizeHint(QSize(150, 150));
            }
            else if (allow == true && use == true)
            {
                if (Username1 != Username12) {
                    QLabel* label5 = new QLabel("", widget);
                    label5->setPixmap(QPixmap(":/mainwindow/icon_ha/images1.jpg"));
                    label5->setWordWrap(true);
                    if (Professor != true) {
                        grid1->addWidget(lable1, numberperson, 1);
                        grid1->addWidget(label5, numberperson + 1, 0, 1, 2);
                    }
                    if (Professor == true) {
                        grid1->addWidget(lable1, numberperson, 2);
                        grid1->addWidget(label5, numberperson + 1, 0, 1, 3);
                    }
                    widget->setLayout(grid1);
                    item->setSizeHint(QSize(150, 250));
                }

                else if (Username1 == Username12) {
                    QPushButton* pushbtn = new QPushButton(tr("Stop"), widget);
                    QToolButton* toolbtn = new QToolButton(widget);
                    toolbtn->setIcon(QIcon(":/mainwindow/icon_ha/Gear-512.png"));
                    toolbtn->setIconSize(QSize(18, 18));
                    grid1->addWidget(lable1, numberperson, 2);

                    connect(pushbtn, &QPushButton::clicked, this, [&, Username12, name, pushbtn]() {
                        QString payamtoserver = "U ";
                        if (pushbtn->text() == tr("Emittion"))
                        {

                            input_device = input_voice->start();
                            connect(input_device, SIGNAL(readyRead()), this, SLOT(sendvoiceToServer()));
                            if (camera1 != nullptr)
                                camera1->start();
                            timerwebcam->start();

                            payamtoserver = payamtoserver + "1,";
                            if (camera1 != nullptr)
                                payamtoserver = payamtoserver + "1,";
                            else
                                payamtoserver = payamtoserver + "0,";
                            pushbtn->setText(tr("Stop"));
                        }

                        else if (pushbtn->text() == tr("Stop")) {
                            input_voice->stop();
                            if (camera1 != nullptr) {
                                camera1->stop();
                                QString pam("##off##");
                                webcamSocket->write(QByteArray(pam.toUtf8()));
                            }
                            timerwebcam->stop();

                            payamtoserver = payamtoserver + "0,0,";

                            ui.label_3->setPixmap(QPixmap(":/mainwindow/icon_ha/images1.jpg"));
                            pushbtn->setText(tr("Emittion"));

                        }
                        permitSocket->write(QByteArray(payamtoserver.toUtf8()));
                        });

                    connect(toolbtn, &QToolButton::clicked, this, [&, Username12, name, pushbtn]() {
                        QDialog* dialog1 = new QDialog(this);
                        QGridLayout* layout1 = new QGridLayout(dialog1);

                        QLabel* lable2 = new QLabel(tr("Microphone:"), dialog1);
                        QComboBox* comboxMicrophone = new QComboBox(dialog1);

                        const auto deviceInfos = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
                        for (const QAudioDeviceInfo& deviceInfo : deviceInfos)
                            if (comboxMicrophone->findText(deviceInfo.deviceName()) == -1)
                                comboxMicrophone->addItem(deviceInfo.deviceName());
                        if (microphone == true) {
                            layout1->addWidget(lable2, 1, 0);
                            layout1->addWidget(comboxMicrophone, 1, 1);

                        }

                        QLabel* lable3 = new QLabel(tr("Webcam:"), dialog1);
                        QComboBox* comboxwebcam = new QComboBox(dialog1);
                        comboxwebcam->addItem(tr("Webcam not allowed"));
                        const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
                        for (const QCameraInfo& cameraInfo : cameras)
                            comboxwebcam->addItem(cameraInfo.description());

                        QComboBox* Webcamresolution = new QComboBox(dialog1);
                        Webcamresolution->addItem(tr("Default"));
                        Webcamresolution->addItem("100*100");
                        Webcamresolution->addItem("120*100");
                        Webcamresolution->addItem("200*200");
                        Webcamresolution->addItem("250*250");
                        Webcamresolution->addItem("300*300");
                        Webcamresolution->addItem("350*350");

                        lable3->setHidden(true);
                        comboxwebcam->setHidden(true);
                        Webcamresolution->setHidden(true);
                        if (webcam == true) {
                            lable3->setHidden(false);
                            comboxwebcam->setHidden(false);
                            Webcamresolution->setHidden(false);
                            layout1->addWidget(lable3, 2, 0);
                            layout1->addWidget(comboxwebcam, 2, 1);
                            layout1->addWidget(Webcamresolution, 3, 1);

                        }

                        QPushButton* ok_btn = new QPushButton(tr("Ok"), dialog1);
                        layout1->addWidget(ok_btn, 4, 0);
                        dialog1->setLayout(layout1);
                        dialog1->show();
                        connect(ok_btn, &QPushButton::clicked, this, [&, pushbtn, dialog1, comboxMicrophone, comboxwebcam, Webcamresolution, deviceInfos, cameras]() {
                            if (pushbtn->text() == tr("Emittion"))
                            {
                                if (microphone == true)
                                {
                                    for (const QAudioDeviceInfo& deviceInfo : deviceInfos)
                                        if (deviceInfo.deviceName() == comboxMicrophone->currentText())
                                        {
                                            QAudioFormat formatofinput;
                                            formatofinput.setSampleRate(44100);
                                            formatofinput.setChannelCount(2);
                                            formatofinput.setSampleSize(16);
                                            formatofinput.setCodec("audio/pcm");
                                            formatofinput.setByteOrder(QAudioFormat::LittleEndian);
                                            formatofinput.setSampleType(QAudioFormat::SignedInt);
                                            if (!deviceInfo.isFormatSupported(formatofinput))
                                                formatofinput = deviceInfo.nearestFormat(formatofinput);
                                            input_voice = new QAudioInput(deviceInfo, formatofinput, this);
                                            input_voice->setBufferSize(16384);
                                            break;
                                        }

                                }

                                if (webcam == true) {
                                    if (comboxwebcam->currentText() != tr("Webcam not allowed")) {
                                        for (const QCameraInfo& cameraInfo : cameras)
                                            if (cameraInfo.description() == comboxwebcam->currentText())
                                            {
                                                camera1 = new QCamera(cameraInfo, this);
                                                camera1->setViewfinder(cameraviewfinder1);
                                                connect(timerwebcam, &QTimer::timeout, this, &mainwindow::sendwebcam);
                                            }
                                    }
                                    else {
                                        camera1->deleteLater();
                                        camera1 = nullptr;
                                        disconnect(timerwebcam, &QTimer::timeout, this, &mainwindow::sendwebcam);
                                    }

                                    QString resulayion = Webcamresolution->currentText();
                                    if (resulayion != tr("Default")) {
                                        camera1->stop();
                                        int with = resulayion.mid(0, resulayion.indexOf("*")).toInt();
                                        resulayion.remove(0, resulayion.indexOf("*") + 1);
                                        int height = resulayion.mid(0).toInt();
                                        cameraviewfinder1->setFixedSize(with, height);
                                    }
                                    else
                                        cameraviewfinder1->setFixedSize(ui.splitter->width(), ui.splitter->width());
                                }
                            }
                            dialog1->close();
                            });
                        });
                    grid1->addWidget(pushbtn, numberperson + 1, 0, 1, 2);
                    grid1->addWidget(toolbtn, numberperson + 1, 2);

                    widget->setLayout(grid1);
                    item->setSizeHint(QSize(150, 150));



                }
            }

            ui.listWidget_2->addItem(item);
            ui.listWidget_2->setItemWidget(item, widget);
            numberperson++;
            if (payam.isEmpty())
                break;
        }
        QString addnd = tr("Attendees: ") + QString::number(numberperson);
        ui.label_2->setText(addnd);
    


}

void mainwindow::ReadscreenSocket() {
    qDebug() << "hhhh";
    Allscreen = Allscreen + screenSocket->readAll();
    if (Allscreen.indexOf("@%*@on@%*@") != -1)
    {
        if (widgetScreen == nullptr) {
            widgetScreen = new QWidget(this, Qt::Window);
            QGridLayout* layout1 = new QGridLayout(widgetScreen);
            labscreen = new QLabel(widgetScreen);
            layout1->addWidget(labscreen);
            widgetScreen->setLayout(layout1);
            widgetScreen->show();

        }
        Allscreen.remove(Allscreen.indexOf("@%*@on@%*@"), 10);
    }

    if (Allscreen.indexOf("##!#") != -1 && Allscreen.indexOf("#!$#") != -1)
    {
        QByteArray payam = Allscreen.mid(Allscreen.indexOf("##!#") + 4, Allscreen.indexOf("#!$#") - Allscreen.indexOf("##!#") - 4);
        qDebug() << "yes";
        QPixmap pixscreen;
        pixscreen.loadFromData(payam);
        QScreen* screen = QGuiApplication::primaryScreen();
        int width = screen->geometry().width();
        int height = screen->geometry().height();
        labscreen->setPixmap(pixscreen.scaled(width - 10, height - 80, Qt::AspectRatioMode::KeepAspectRatio));
        Allscreen.remove(Allscreen.indexOf("##!#"), Allscreen.indexOf("#!$#") - Allscreen.indexOf("##!#") + 4);
    }


    if (Allscreen.indexOf("@%*@off@%*@") != -1)
    {
        widgetScreen->close();
        Allscreen.remove(Allscreen.indexOf("@%*@off@%*@"), 11);
    }

}



void mainwindow::startlisenVoice() {
    QAudioFormat formatofoutput;
    formatofoutput.setSampleRate(44100);
    formatofoutput.setChannelCount(2);
    formatofoutput.setSampleSize(16);
    formatofoutput.setCodec("audio/pcm");
    formatofoutput.setByteOrder(QAudioFormat::LittleEndian);
    formatofoutput.setSampleType(QAudioFormat::SignedInt);

    QAudioDeviceInfo info2(QAudioDeviceInfo::defaultOutputDevice());
    if (!info2.isFormatSupported(formatofoutput))
        formatofoutput = info2.nearestFormat(formatofoutput);
    // ui->label->setText(info2.deviceName()); // the supported output device


    output_voice = new QAudioOutput(formatofoutput);
    output_voice->setBufferSize(16384);


    output_device = output_voice->start();
    Preparationsendvoice();
}

void mainwindow::sendvoiceToServer() {
    QByteArray payam = input_device->readAll();
    voiceSocket->write(payam);
}

void mainwindow::on_pushButton_4_clicked() {
    if (ui.pushButton_4->text() == tr("Emittion"))
    {

        input_device = input_voice->start();
        connect(input_device, SIGNAL(readyRead()), this, SLOT(sendvoiceToServer()));
        if (camera1 != nullptr)
            camera1->start();
        timerwebcam->start();
        ui.pushButton_4->setText(tr("Stop"));
    }

    else if (ui.pushButton_4->text() == tr("Stop")) {
        input_voice->stop();
        if (camera1 != nullptr) {
            camera1->stop();
            QString pam("##off##");
            webcamSocket->write(QByteArray(pam.toUtf8()));
        }
        timerwebcam->stop();
        ui.label_3->setPixmap(QPixmap(":/mainwindow/icon_ha/images1.jpg"));
        ui.pushButton_4->setText(tr("Emittion"));

    }
}

void mainwindow::Preparationsendvoice() {
    QAudioFormat formatofinput;
    formatofinput.setSampleRate(44100);
    formatofinput.setChannelCount(2);
    formatofinput.setSampleSize(16);
    formatofinput.setCodec("audio/pcm");
    formatofinput.setByteOrder(QAudioFormat::LittleEndian);
    formatofinput.setSampleType(QAudioFormat::SignedInt);

    //If format isn't supported find the nearest supported
    QAudioDeviceInfo info(QAudioDeviceInfo::defaultInputDevice());
    if (!info.isFormatSupported(formatofinput))
        formatofinput = info.nearestFormat(formatofinput);
    // ui->label_2->setText(info.deviceName()); // the supported Input device

    input_voice = new QAudioInput(formatofinput);
    input_voice->setBufferSize(16384); //  set buffere size to solve sound distribution on windows but not solve this problem when use it in android


}

void mainwindow::btnPerson(QString username, QString name) {
    QDialog* dialog1 = new QDialog(this);
    QGridLayout* grid1 = new QGridLayout(dialog1);
    QLabel* name_lable = new QLabel(name, this);
    QCheckBox* checkboxmicrophone = new QCheckBox(tr("access to microphone:"), this);
    QCheckBox* checkboxwebcam = new QCheckBox(tr("access to webcem:"), this);
    QCheckBox* checkboxcontent = new QCheckBox(tr("access to change content:"), this);
    QPushButton* ok_btn = new QPushButton(tr("OK"), this);

    grid1->addWidget(name_lable, 0, 0);
    grid1->addWidget(checkboxmicrophone, 1, 0);
    grid1->addWidget(checkboxwebcam, 2, 0);
    grid1->addWidget(checkboxcontent, 3, 0);
    grid1->addWidget(ok_btn, 4, 0);


    connect(ok_btn, &QPushButton::clicked, this, [&, username, checkboxmicrophone, checkboxwebcam, checkboxcontent, dialog1]() {sendchangeaccesToserver(username, checkboxmicrophone, checkboxwebcam, checkboxcontent, dialog1); });

    dialog1->setLayout(grid1);
    dialog1->show();

}

void mainwindow::sendStatus() {
    int status = ui.comboBox->currentIndex();
    QString str = QString("%1").arg(status);
    attendessSocket->write(QByteArray(str.toUtf8()));
}

void mainwindow::sendnote() {
    QString payam = ui.plainTextEdit->toPlainText();
    noteSocket->write(QByteArray(payam.toUtf8()));
}

void mainwindow::sendchat() {
    if (ui.lineEdit->text() != "")
    {
        chatSocket->write(QByteArray(QString(ui.lineEdit->text()).toUtf8()));
        ui.lineEdit->clear();
    }
}

void mainwindow::sendchangeaccesToserver(QString username, QCheckBox* microphone, QCheckBox* webcam, QCheckBox* content, QDialog* dialog) {
    QString payam = "S " + username + "," + QString("%1").arg(microphone->isChecked()) + "&" + QString("%1").arg(webcam->isChecked()) + "&" + QString("%1").arg(content->isChecked()) + "&";
    permitSocket->write(QByteArray(payam.toUtf8()));
    dialog->close();
}

void mainwindow::Preparationwebcam() {
    cameraviewfinder1 = new QCameraViewfinder(this);
    cameraviewfinder1->hide();
    cameraviewfinder1->setFixedSize(ui.splitter->width(), ui.splitter->width());
    timerwebcam = new QTimer(this);
    timerwebcam->setInterval(83);
}

void mainwindow::sendwebcam() {
    QPixmap pixmap = cameraviewfinder1->grab();
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "jpg");
    QByteArray payam = QByteArray(QString("&&").toUtf8()) + bytes + QByteArray(QString("$$").toUtf8());
    webcamSocket->write(payam);
}

void mainwindow::on_pushButton_2_clicked() {
    //choice Allow
    QDialog* dialog1 = new QDialog(this);
    QGridLayout* layout1 = new QGridLayout(dialog1);


    QLabel* lable1 = new QLabel(tr("Professor"), dialog1);
    QLabel* lable2 = new QLabel(tr("Microphone:"), dialog1);
    QComboBox* comboxMicrophone = new QComboBox(dialog1);

    const auto deviceInfos = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    for (const QAudioDeviceInfo& deviceInfo : deviceInfos)
        if (comboxMicrophone->findText(deviceInfo.deviceName()) == -1)
            comboxMicrophone->addItem(deviceInfo.deviceName());

    QLabel* lable3 = new QLabel(tr("Webcam:"), dialog1);
    QComboBox* comboxwebcam = new QComboBox(dialog1);
    comboxwebcam->addItem(tr("Webcam not allowed"));
    const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    for (const QCameraInfo& cameraInfo : cameras)
        comboxwebcam->addItem(cameraInfo.description());

    QComboBox* Webcamresolution = new QComboBox(dialog1);
    Webcamresolution->addItem(tr("Default"));
    Webcamresolution->addItem("100*100");
    Webcamresolution->addItem("120*100");
    Webcamresolution->addItem("200*200");
    Webcamresolution->addItem("250*250");
    Webcamresolution->addItem("300*300");
    Webcamresolution->addItem("350*350");

    QPushButton* ok_btn = new QPushButton("Ok", dialog1);

    QCheckBox* checkAllaccMicrophone = new QCheckBox(tr("Access all person to microphones"), dialog1);
    QCheckBox* checkAllaccwebcam = new QCheckBox(tr("Access all person to webcam"), dialog1);

    layout1->addWidget(lable1, 0, 0);
    layout1->addWidget(lable2, 1, 0);
    layout1->addWidget(comboxMicrophone, 1, 1);
    layout1->addWidget(lable3, 2, 0);
    layout1->addWidget(comboxwebcam, 2, 1);
    layout1->addWidget(Webcamresolution, 3, 1);


    layout1->addWidget(checkAllaccMicrophone, 8, 0);
    layout1->addWidget(checkAllaccwebcam, 9, 0);

    QLabel* lable8 = new QLabel("    ", dialog1);
    layout1->addWidget(lable8, 10, 0);

    layout1->addWidget(ok_btn, 11, 0, 1, 2);



    dialog1->setLayout(layout1);
    connect(ok_btn, &QPushButton::clicked, this, [&, comboxMicrophone, comboxwebcam,
        Webcamresolution, deviceInfos, cameras, checkAllaccMicrophone, checkAllaccwebcam, dialog1]() {
            for (const QAudioDeviceInfo& deviceInfo : deviceInfos)
                if (deviceInfo.deviceName() == comboxMicrophone->currentText())
                {
                    QAudioFormat formatofinput;
                    formatofinput.setSampleRate(44100);
                    formatofinput.setChannelCount(2);
                    formatofinput.setSampleSize(16);
                    formatofinput.setCodec("audio/pcm");
                    formatofinput.setByteOrder(QAudioFormat::LittleEndian);
                    formatofinput.setSampleType(QAudioFormat::SignedInt);
                    if (!deviceInfo.isFormatSupported(formatofinput))
                        formatofinput = deviceInfo.nearestFormat(formatofinput);
                    input_voice = new QAudioInput(deviceInfo, formatofinput, this);
                    input_voice->setBufferSize(16384);
                    break;
                }

            if (comboxwebcam->currentText() != tr("Webcam not allowed")) {
                for (const QCameraInfo& cameraInfo : cameras)
                    if (cameraInfo.description() == comboxwebcam->currentText())
                    {
                        camera1 = new QCamera(cameraInfo, this);
                        camera1->setViewfinder(cameraviewfinder1);
                        connect(timerwebcam, &QTimer::timeout, this, &mainwindow::sendwebcam);
                    }
            }
            else {
                camera1->deleteLater();
                camera1 = nullptr;
                disconnect(timerwebcam, &QTimer::timeout, this, &mainwindow::sendwebcam);
            }

            QString resulayion = Webcamresolution->currentText();
            if (resulayion != tr("Default")) {
                camera1->stop();
                int with = resulayion.mid(0, resulayion.indexOf("*")).toInt();
                resulayion.remove(0, resulayion.indexOf("*") + 1);
                int height = resulayion.mid(0).toInt();
                cameraviewfinder1->setFixedSize(with, height);
            }
            else
                cameraviewfinder1->setFixedSize(ui.splitter->width(), ui.splitter->width());

            if (checkAllaccMicrophone->isChecked() || checkAllaccwebcam->isChecked()) {
                QString payam = "A ";
                if (checkAllaccMicrophone->isChecked())
                    payam = payam + "1,";
                else
                    payam = payam + "0,";

                if (checkAllaccwebcam->isChecked())
                    payam = payam + "1,";
                else
                    payam = payam + "0,";

                permitSocket->write(QByteArray(payam.toUtf8()));
            }
            dialog1->close();
        });
    dialog1->show();
}

void mainwindow::PDFContent(QString name, int numberpage) {
    QWidget* Pdfwidget = new QWidget(this);
    QGridLayout* pdflayout = new QGridLayout(Pdfwidget);

    QSpacerItem* spacer1 = new QSpacerItem(1, 0);
    QLabel* labelzoom = new QLabel(tr("Zoom:"), Pdfwidget);
    QSlider* Sliderzoom = new QSlider(Qt::Orientation::Horizontal, Pdfwidget);
    Sliderzoom->setMaximumWidth(150);
    Sliderzoom->setRange(30, 150);
    Sliderzoom->setValue(100);
    QLabel* labelzoomsize = new QLabel(Pdfwidget);
    connect(Sliderzoom, &QSlider::valueChanged, this, [=]() { labelzoomsize->setText(QString("%1 %").arg(Sliderzoom->value())); });
    QSpacerItem* spacer2 = new QSpacerItem(1, 0);
    QLabel* numberAllpage = new QLabel(QString::number(numberpage), Pdfwidget);
    QLabel* label1 = new QLabel("/", Pdfwidget);
    QSpinBox* pagespin = new QSpinBox(Pdfwidget);
    pagespin->setMinimum(1);
    pagespin->setMaximum(numberpage);
    QLabel* page = new QLabel(tr(":Page"), Pdfwidget);
    //QSpacerItem* spacer2 = new QSpacerItem(2, 0);
    QScrollArea* scrollArea = new QScrollArea(Pdfwidget);

    // pdflayout
    QLabel* fasele = new QLabel("  ", Pdfwidget);
    fasele->setMinimumSize(QSize(150, 0));
    QLabel* fasele1 = new QLabel("  ", Pdfwidget);
    fasele1->setMinimumSize(QSize(100, 0));
    QLabel* fasele2 = new QLabel("  ", Pdfwidget);
    fasele2->setMinimumSize(QSize(110, 0));

    pdflayout->addWidget(fasele, 0, 0);
    pdflayout->addWidget(labelzoom, 0, 1);
    pdflayout->addWidget(labelzoomsize, 0, 2);
    pdflayout->addWidget(Sliderzoom, 0, 3);
    pdflayout->addWidget(fasele1, 0, 4);
    pdflayout->addWidget(numberAllpage, 0, 5);
    pdflayout->addWidget(label1, 0, 6);
    pdflayout->addWidget(pagespin, 0, 7);
    pdflayout->addWidget(page, 0, 8);
    pdflayout->addWidget(fasele2, 0, 9);
    pdflayout->addWidget(scrollArea, 1, 0, 1, 10);

    Pdfwidget->setLayout(pdflayout);
    if (Professor == true)
        ui.tabWidget->insertTab(ui.tabWidget->count() - 1, Pdfwidget, name);
    if (Professor == false)
        ui.tabWidget->insertTab(ui.tabWidget->count(), Pdfwidget, name);



    tabwidget1[tabwidget1.count() - 1].name = name;
    tabwidget1[tabwidget1.count() - 1].pagespin = pagespin;
    tabwidget1[tabwidget1.count() - 1].Sliderzoom = Sliderzoom;
    tabwidget1[tabwidget1.count() - 1].scrollArea = scrollArea;

    if (Professor == false && content == false)
    {
        changesync();
    }

    connect(pagespin, qOverload<int>(&QSpinBox::valueChanged), this, [&, name, pagespin](int value) {sendreqChangepage(name, pagespin->value() /*value*/); });
    connect(Sliderzoom, &QSlider::valueChanged, this, [&, name, pagespin]() {sendreqChangepage(name, pagespin->value()); });
    if (Professor) {
        connect(pagespin, qOverload<int>(&QSpinBox::valueChanged), this, [&, name](int value) {sendcurrenttabAndContent(ui.tabWidget->currentIndex()); });
        connect(Sliderzoom, &QSlider::valueChanged, this, [&, name](int value) {sendcurrenttabAndContent(ui.tabWidget->currentIndex()); });
        connect(scrollArea->verticalScrollBar(), &QScrollBar::valueChanged, this, [&, name](int value) {sendcurrenttabAndContent(ui.tabWidget->currentIndex()); });
        connect(scrollArea->horizontalScrollBar(), &QScrollBar::valueChanged, this, [&, name](int value) {sendcurrenttabAndContent(ui.tabWidget->currentIndex()); });
    }
}

void mainwindow::newContent() {
    QWidget* newwidget = new QWidget(this);
    QGridLayout* newlayout = new QGridLayout(newwidget);

    QLabel* label1 = new QLabel(tr("Select what you want to share"), newwidget);
    label1->setFont(QFont("Arial", 20));
    QRadioButton* PdfRadio = new QRadioButton(tr("PDF File"), newwidget);
    PdfRadio->setFont(QFont("Arial", 15));
    //QRadioButton* imageRadio = new QRadioButton(tr("Image File"), newwidget);
    //imageRadio->setFont(QFont("Arial", 15));
    QPushButton* shareBtn = new QPushButton(tr("Share"), newwidget);
    shareBtn->setFont(QFont("Arial", 15));


    QLabel* fasele = new QLabel("  ", newwidget);
    fasele->setMinimumSize(QSize(0, 10));

    QLabel* fasele2 = new QLabel("  ", newwidget);
    fasele2->setMinimumSize(QSize(0, 100));

    QLabel* fasele3 = new QLabel("  ", newwidget);
    fasele3->setMinimumSize(QSize(0, 100));

    QLabel* fasele4 = new QLabel("  ", newwidget);
    fasele4->setMinimumSize(QSize(0, 30));


    newlayout->addWidget(label1, 0, 0, 1, 3);
    newlayout->addWidget(PdfRadio, 2, 0, 1, 3);
    //newlayout->addWidget(imageRadio, 4, 0,1,3);
    newlayout->addWidget(fasele2, 5, 0, 1, 3);
    newlayout->addWidget(shareBtn, 6, 1, 1, 1);
    newlayout->addWidget(fasele3, 7, 0, 1, 3);
    //badan

    newwidget->setLayout(newlayout);
    ui.tabWidget->addTab(newwidget, "new tab");
    if (Professor == false)
    {
        tabwidget1.append(Tabwidget());
        tabwidget1[tabwidget1.count() - 1].name = "new tab";

    }
    connect(shareBtn, &QPushButton::clicked, this, [&, PdfRadio]() {if (PdfRadio->isChecked())  openpdf(); /*else if (imageRadio->isChecked())  openimage();*/ else; });
}

void mainwindow::openpdf() {
    QFileDialog dialogfile1;
    QString namefi = dialogfile1.getOpenFileName(this, "open pdf file", "", "PDF (*.pdf)");
    QFileInfo info1(namefi);
    QString basename = info1.baseName();
    QString pre_dir = qApp->applicationDirPath() + "/pdfChange/" + basename;
    QDir dir1;
    dir1.mkpath(pre_dir);



    QMessageBox* mes = new QMessageBox(this);
    mes->setText(tr("Wait for processing"));
    mes->setFont(QFont("Areal", 25));
    mes->setWindowTitle("Processing...");
    mes->setStyleSheet("QLabel{ color: red}");
    mes->setStandardButtons(0);

    mes->open();

    QFile::copy(namefi, pre_dir + "/" + basename + ".pdf");
    QFile::copy(":/new/file/file_ha/pdftopng.exe", pre_dir + "/" + "pdftopng.exe");
    QString drive_name = qApp->applicationDirPath().mid(0, qApp->applicationDirPath().indexOf(":/"));
    QString cmddir;
    cmddir = qApp->applicationDirPath() + "/pdfChange/" + "transfer.cmd";
    QFile file1(cmddir);
    file1.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file1);
    out << drive_name << ":\n";

    out << "cmd /c \"cd \"" + pre_dir + "\" && pdftopng.exe\"\" \"" + basename + ".pdf\" \"png\"";

    file1.close();
    QProcess* pro = new QProcess(this);
    QString pre_process = qApp->applicationDirPath() + "/pdfChange/transfer.cmd";
    pro->start(pre_process, QStringList() << "");

    QString path = pre_dir;
    QDir dirCount(path);

    dirCount.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
    int Previous_count = 0;

    int new_count = 0;
    do
    {
        pro->waitForFinished(2000);
        Previous_count = new_count;
        dirCount.refresh();
        new_count = dirCount.count() - 2;
    } while (new_count > Previous_count);


    mes->rejected();
    mes->close();
    mes->reject();

    int numberPage = 0;
    QString nameoffile23;
    QString dirfilepng;

    numberPage = dirCount.count() - 2;
    nameoffile23 = basename;
    dirfilepng = pre_dir + "/";
    QFile file(QString(pre_dir + "/" + basename + ".pdf"));
    file.remove();
    if (numberPage > 0)
        sendpdftoServer(numberPage, dirfilepng, nameoffile23);
    else {
        QMessageBox::critical(this, "Error", tr("An Error occurred while converting the file!"), QMessageBox::Ok);
    }

}
void mainwindow::sendpdftoServer(int numberPage, QString dirfilepng, QString nameoffile23) {
    //for example "~  0,namepdf*196^"
    QString payamaval = "~  0," + nameoffile23 + "*" + QString::number(numberPage) + "^";
    sendSocket->write(QByteArray(payamaval.toUtf8()));
    QProgressDialog progress("Sending to server...", "Cancel", 0, numberPage, this);
    progress.setWindowModality(Qt::WindowModal);
    int pagesended = 0;
    progress.show();

    int sadgan = (numberPage / 100);
    int dahgan = ((numberPage / 10) % 10);
    int yekan = (numberPage % 10);


    for (int i = 0; i <= (numberPage / 100); i++)
        for (int j = 0; (i < sadgan && j < 10) || (i == sadgan && j <= dahgan); j++)
            for (int k = 0; (j < dahgan && k < 10) || (k <= (numberPage % 10) && k <= yekan); k++)
            {
                QString pa = dirfilepng + "png-" + "000" + QString::number(i) + QString::number(j) + QString::number(k) + ".png";
                QFile filered(pa);
                if (filered.open(QIODevice::ReadOnly)) {

                    QByteArray buffer = filered.readAll();
                    QString pre = "&&&&$" + QString::number(i) + QString::number(j) + QString::number(k) + ",";
                    QByteArray payam = pre.toUtf8() + buffer + QString("####$").toUtf8();
                    while (!payam.isEmpty())
                    {
                        sendSocket->write(QByteArray(payam));
                        payam.remove(0, payam.length());
                    }
                    pagesended++;
                    progress.setValue(pagesended);
                    filered.remove();
                }

            }

    QDir dir1(dirfilepng);
    dir1.removeRecursively();
}


void mainwindow::openimage() {

}


void mainwindow::imageContent() {
    QWidget* imagewidget = new QWidget(this);
    QGridLayout* imagelayout = new QGridLayout(imagewidget);

    QLabel* labelzoom = new QLabel(tr("Zoom:"), imagewidget);
    QSlider* Sliderzoom = new QSlider(Qt::Orientation::Horizontal, imagewidget);
    Sliderzoom->setMaximumWidth(150);
    Sliderzoom->setRange(30, 150);
    Sliderzoom->setValue(100);
    QLabel* labelzoomsize = new QLabel(imagewidget);
    connect(Sliderzoom, &QSlider::valueChanged, this, [=]() { labelzoomsize->setText(QString("%1 %").arg(Sliderzoom->value())); });
    QScrollArea* scrollArea = new QScrollArea(imagewidget);


    QLabel* fasele = new QLabel("  ", imagewidget);
    fasele->setMinimumSize(QSize(190, 0));
    QLabel* fasele2 = new QLabel("  ", imagewidget);
    fasele2->setMinimumSize(QSize(190, 0));

    imagelayout->addWidget(fasele, 0, 0);
    imagelayout->addWidget(labelzoom, 0, 1);
    imagelayout->addWidget(labelzoomsize, 0, 2);
    imagelayout->addWidget(Sliderzoom, 0, 3);
    imagelayout->addWidget(fasele2, 0, 4);
    imagelayout->addWidget(scrollArea, 1, 0, 1, 5);

}

void mainwindow::sendreqChangepage(QString name, int pagenumber) {
    QString payam = "!^^^^$0," + name + "*" + QString::number(pagenumber) + "&^^$^^";
    sendSocket->write(QByteArray(payam.toUtf8()));
}

void mainwindow::on_mousebtn_clicked(QPushButton* btn) {
    if (btn->isChecked())
    {
        QCursor cursor1 = QCursor(QPixmap(":/mainwindow/icon_ha/Webp.net-resizeimage.png"), 15, 7);
        ui.tabWidget->setCursor(cursor1);
        ui.tabWidget->installEventFilter(this);
        timerformouse = new QTimer(this);
        connect(timerformouse, &QTimer::timeout, this, [&, cursor1]() {AnalizMouseForSend(cursor1); });
        timerformouse->start(50);
    }
    else
    {
        ui.tabWidget->unsetCursor();
        ui.tabWidget->removeEventFilter(this);
        disconnect(timerformouse, SIGNAL(timeout()), this, SLOT(AnalizMouseForSend()));
        timerformouse->stop();
        delete timerformouse;
        QString payam2 = "##off##";
        mouseSocket->write(QByteArray(payam2.toUtf8()));
    }
}
void mainwindow::AnalizMouseForSend(QCursor cursor1) {
    QPoint mouspos = ui.tabWidget->mapFromGlobal(cursor1.pos());
    if (mouspos.x() > 0 && mouspos.y() > 0 && mouspos.x() < ui.tabWidget->width() && mouspos.y() < ui.tabWidget->height())
    {
        float nesbatX = (float)mouspos.x() / ui.tabWidget->width();
        float nesbatY = (float)mouspos.y() / ui.tabWidget->height();
        QString payam = "**X:" + QString::number(nesbatX) + "&Y:" + QString::number(nesbatY) + "&&";
        mouseSocket->write(QByteArray(payam.toUtf8()));
    }
}

void mainwindow::sendcurrenttabAndContent(int indexnow) {
    QString name = ui.tabWidget->tabText(indexnow);
    int page;
    for (int i = 0; i < tabwidget1.count(); i++)
        if (tabwidget1[i].name == name) {
            page = tabwidget1[i].pagespin->value();
            int scrollVir = tabwidget1[i].scrollArea->verticalScrollBar()->value();
            int scrollHor = tabwidget1[i].scrollArea->horizontalScrollBar()->value();
            int zoom = tabwidget1[i].Sliderzoom->value();
            QString payam = "###Name=" + name + "*page=" + QString::number(page) + "!" + "virScroll=" + QString::number(scrollVir) + "horScroll=" + QString::number(scrollHor) + "zoom=" + QString::number(zoom) + "!&&&";
            shapeSocket->write(QByteArray(payam.toUtf8()));
        }

}

void mainwindow::changesync() {
    if (ui.checkBox->isChecked())
    {
        ui.tabWidget->tabBar()->setDisabled(true);
        for (int i = 0; i < tabwidget1.count(); i++)
        {
            if (tabwidget1[i].name != "new tab") {
                tabwidget1[i].pagespin->setDisabled(true);
                tabwidget1[i].Sliderzoom->setDisabled(true);
                tabwidget1[i].scrollArea->verticalScrollBar()->setDisabled(true);
                tabwidget1[i].scrollArea->horizontalScrollBar()->setDisabled(true);
            }
            if (lastContent.name != "" && lastContent.name == tabwidget1[i].name)
            {
                initialEntered = true;

                tabwidget1[i].pagespin->setValue(lastContent.page);
                tabwidget1[i].Sliderzoom->setValue(lastContent.zoom);
                tabwidget1[i].scrollArea->verticalScrollBar()->setValue(lastContent.verscroll);
                tabwidget1[i].scrollArea->horizontalScrollBar()->setValue(lastContent.horscroll);
            }
        }

    }
    else {
        ui.tabWidget->tabBar()->setDisabled(false);
        for (int i = 0; i < tabwidget1.count(); i++)
        {
            if (tabwidget1[i].name != "new tab") {
                tabwidget1[i].pagespin->setDisabled(false);
                tabwidget1[i].Sliderzoom->setDisabled(false);
                tabwidget1[i].scrollArea->verticalScrollBar()->setDisabled(false);
                tabwidget1[i].scrollArea->horizontalScrollBar()->setDisabled(false);
            }

        }


    }
}

void mainwindow::mousePressEvent(QMouseEvent* event) {
    int num;
    for (int i = 0; i < tabwidget1.count(); i++)
        if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
            num = i;

    if (Drawing || rectangle || circle || line || eraser || text)
    {
        if (event->y() < (ui.tabWidget->geometry().y() + ui.tabWidget->geometry().height())) {
            xPress = event->pos().x() - 10; //-13
            yPress = event->pos().y() - 7 - ui.checkBox->geometry().y() - ui.checkBox->height() - tabwidget1[num].Sliderzoom->height() - ui.tabWidget->tabBar()->height() - 10 + tabwidget1[num].scrollArea->verticalScrollBar()->value(); //-7
        }

    }
    if (Drawing)
    {
        path = new QPainterPath(QPointF(xPress, yPress));
        path->moveTo(xPress, yPress);
    }

}

void mainwindow::mouseMoveEvent(QMouseEvent* event) {
    int num;
    for (int i = 0; i < tabwidget1.count(); i++)
        if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
            num = i;

    if (Drawing)
    {
        if (event->y() < (ui.tabWidget->geometry().y() + ui.tabWidget->geometry().height())) {
            xMove = event->pos().x() - 10;
            yMove = event->pos().y() - 7 - ui.checkBox->geometry().y() - ui.checkBox->height() - tabwidget1[num].Sliderzoom->height() - ui.tabWidget->tabBar()->height() - 10 + tabwidget1[num].scrollArea->verticalScrollBar()->value();
            draw();
        }
    }
    if (rectangle)
    {
        if (event->y() < (ui.tabWidget->geometry().y() + ui.tabWidget->geometry().height())) {
            xRelease = 0;
            yRelease = 0;
            xMove = event->pos().x() - 10;
            yMove = event->pos().y() - 7 - ui.checkBox->geometry().y() - ui.checkBox->height() - tabwidget1[num].Sliderzoom->height() - ui.tabWidget->tabBar()->height() - 10 + tabwidget1[num].scrollArea->verticalScrollBar()->value();
            drawRectangle();
        }
    }
    if (circle)
    {
        if (event->y() < (ui.tabWidget->geometry().y() + ui.tabWidget->geometry().height())) {
            xRelease = 0;
            yRelease = 0;
            xMove = event->pos().x() - 10;
            yMove = event->pos().y() - 7 - ui.checkBox->geometry().y() - ui.checkBox->height() - tabwidget1[num].Sliderzoom->height() - ui.tabWidget->tabBar()->height() - 10 + tabwidget1[num].scrollArea->verticalScrollBar()->value();
            drawCircel();
        }
    }
    if (line)
    {

        xRelease = 0;
        yRelease = 0;
        xMove = event->pos().x() - 10;
        yMove = event->pos().y() - 7 - ui.checkBox->geometry().y() - ui.checkBox->height() - tabwidget1[num].Sliderzoom->height() - ui.tabWidget->tabBar()->height() - 10 + tabwidget1[num].scrollArea->verticalScrollBar()->value();
        drawLine();
    }
    if (eraser)
    {
        xMove = event->pos().x() - 10;
        yMove = event->pos().y() - 7 - ui.checkBox->geometry().y() - ui.checkBox->height() - tabwidget1[num].Sliderzoom->height() - ui.tabWidget->tabBar()->height() - 10 + tabwidget1[num].scrollArea->verticalScrollBar()->value();
        erase();
    }
}

void mainwindow::mouseReleaseEvent(QMouseEvent* event) {
    int num;
    for (int i = 0; i < tabwidget1.count(); i++)
        if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
            num = i;

    if (Drawing)
    {
        delete path;
        editpagedata(num);
    }
    else if (rectangle)
    {
        xRelease = event->pos().x() - 10;
        yRelease = event->pos().y() - 7 - ui.checkBox->geometry().y() - ui.checkBox->height() - tabwidget1[num].Sliderzoom->height() - ui.tabWidget->tabBar()->height() - 10 + tabwidget1[num].scrollArea->verticalScrollBar()->value();
        drawRectangle();
        rectangle = false;
        editpagedata(num);
    }
    else if (circle)
    {
        xRelease = event->pos().x() - 10;
        yRelease = event->pos().y() - 7 - ui.checkBox->geometry().y() - ui.checkBox->height() - tabwidget1[num].Sliderzoom->height() - ui.tabWidget->tabBar()->height() - 10 + tabwidget1[num].scrollArea->verticalScrollBar()->value();
        drawCircel();
        circle = false;
        editpagedata(num);
    }
    else if (line)
    {
        xRelease = event->pos().x() - 10;
        yRelease = event->pos().y() - 7 - ui.checkBox->geometry().y() - ui.checkBox->height() - tabwidget1[num].Sliderzoom->height() - ui.tabWidget->tabBar()->height() - 10 + tabwidget1[num].scrollArea->verticalScrollBar()->value();
        drawLine();
        editpagedata(num);
    }
    else if (eraser)
    {
        editpagedata(num);
    }
    else if (text)
    {
        xRelease = event->pos().x() - 10;
        yRelease = event->pos().y() - 7 - ui.checkBox->geometry().y() - ui.checkBox->height() - tabwidget1[num].Sliderzoom->height() - ui.tabWidget->tabBar()->height() - 10 + tabwidget1[num].scrollArea->verticalScrollBar()->value();
        drawText();
        editpagedata(num);
    }
}

void mainwindow::on_khatbtn_clicked(QPushButton* btn) {
    if (!btn->isChecked()) {
        line = false;
        colorcombo->setHidden(true);
        sizespin->setHidden(true);

    }
    else if (btn->isChecked())
    {
        line = true;
        Drawing = 0;
        rectangle = 0;
        circle = 0;
        eraser = 0;
        text = false;
        if (painter != nullptr)
        {
            delete painter;
            painter = nullptr;
        }
        pix = new QPixmap();
        //badan
        for (int i = 0; i < tabwidget1.count(); i++)
            if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
                *pix = tabwidget1[i].lastlab->pixmap()->scaled(tabwidget1[i].lastlab->width(), tabwidget1[i].lastlab->height());

        painter = new QPainter(pix);
        colorcombo->setHidden(false);
        sizespin->setHidden(false);
    }
}

void mainwindow::on_medadbtn_clicked(QPushButton* btn) {
    if (!btn->isChecked()) {
        Drawing = false;
        ui.tabWidget->unsetCursor();
        colorcombo->setHidden(true);
        sizespin->setHidden(true);

    }
    else if (btn->isChecked())
    {
        QPixmap medadicon(":/mainwindow/icon_ha/cell-2-0-480.png");
        medadicon = medadicon.scaled(30, 30);
        QCursor cursor1 = QCursor((medadicon), 0, 24);
        for (int i = 0; i < tabwidget1.count(); i++)
        {
            if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
            {
                ui.tabWidget->setCursor(cursor1);
            }
        }
        line = false;
        Drawing = true;
        rectangle = 0;
        circle = 0;
        eraser = 0;
        text = false;
        if (painter == NULL)
        {
            //badan

        }
        pix = new QPixmap();
        for (int i = 0; i < tabwidget1.count(); i++)
            if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
                *pix = tabwidget1[i].lastlab->pixmap()->scaled(tabwidget1[i].lastlab->width(), tabwidget1[i].lastlab->height());

        painter = new QPainter(pix);
        colorcombo->setHidden(false);
        sizespin->setHidden(false);
    }
}

void mainwindow::on_pakkonbtn_clicked(QPushButton* btn) {
    if (!btn->isChecked()) {
        eraser = false;
        ui.tabWidget->unsetCursor();
        colorcombo->setHidden(true);
        sizespin->setHidden(true);

    }
    else if (btn->isChecked())
    {
        QPixmap pakkonicon(":/mainwindow/icon_ha/24-512.png");
        pakkonicon = pakkonicon.scaled(30, 30);
        QCursor cursor1 = QCursor((pakkonicon), 0, 24);
        for (int i = 0; i < tabwidget1.count(); i++)
        {
            if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
            {
                ui.tabWidget->setCursor(cursor1);
            }
        }
        line = false;
        Drawing = false;
        rectangle = false;
        circle = false;
        eraser = 1;
        text = false;
        if (painter == NULL)
        {
            //badan

        }
        pix = new QPixmap();
        for (int i = 0; i < tabwidget1.count(); i++)
            if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
                *pix = tabwidget1[i].lastlab->pixmap()->scaled(tabwidget1[i].lastlab->width(), tabwidget1[i].lastlab->height());

        painter = new QPainter(pix);
        sizespin->setHidden(false);
    }
}

void mainwindow::on_morababtn_clicked(QPushButton* btn) {
    line = false;
    Drawing = false;
    rectangle = 1;
    circle = false;
    eraser = false;
    text = false;
    if (painter == NULL)
    {
        //badan

    }
    pix = new QPixmap();
    for (int i = 0; i < tabwidget1.count(); i++)
        if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
            *pix = tabwidget1[i].lastlab->pixmap()->scaled(tabwidget1[i].lastlab->width(), tabwidget1[i].lastlab->height());

    painter = new QPainter(pix);
    colorcombo->setHidden(false);
    sizespin->setHidden(false);
}

void mainwindow::on_dayerebtn_clicked(QPushButton* btn) {
    line = false;
    Drawing = false;
    rectangle = false;
    circle = 1;
    eraser = false;
    text = false;
    if (painter == NULL)
    {


    }
    pix = new QPixmap();
    for (int i = 0; i < tabwidget1.count(); i++)
        if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
            *pix = tabwidget1[i].lastlab->pixmap()->scaled(tabwidget1[i].lastlab->width(), tabwidget1[i].lastlab->height());

    painter = new QPainter(pix);
    colorcombo->setHidden(false);
    sizespin->setHidden(false);
}




void mainwindow::draw() {
    path->lineTo(xMove, yMove);

    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPath(*path);

    for (int i = 0; i < tabwidget1.count(); i++)
        if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
            tabwidget1[i].lastlab->setPixmap(pix->scaled(pix->width(), pix->height(), Qt::AspectRatioMode::KeepAspectRatio));
    //lab->setPixmap(pix->scaled(pix->width(), pix->height(), Qt::AspectRatioMode::KeepAspectRatio));
}

void mainwindow::drawRectangle() {
    painter->setPen(pen);

    if (xRelease == 0 && yRelease == 0) {

        QPixmap* newmovaghati = new QPixmap();
        newmovaghati->operator =(*pix);
        QPainter* movaghatpaniter125 = new QPainter(newmovaghati);
        movaghatpaniter125->setPen(pen);


        movaghatpaniter125->drawRect(xPress, yPress, xMove - xPress, yMove - yPress);
        for (int i = 0; i < tabwidget1.count(); i++)
            if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
                tabwidget1[i].lastlab->setPixmap(newmovaghati->scaled(pix->width(), pix->height(), Qt::AspectRatioMode::KeepAspectRatio));
    }
    else {
        painter->drawRect(xPress, yPress, xRelease - xPress, yRelease - yPress);
        for (int i = 0; i < tabwidget1.count(); i++)
            if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
                tabwidget1[i].lastlab->setPixmap(pix->scaled(pix->width(), pix->height(), Qt::AspectRatioMode::KeepAspectRatio));

        colorcombo->setHidden(true);
        sizespin->setHidden(true);
    }
}

void mainwindow::drawCircel() {
    painter->setPen(pen);

    if (xRelease == 0 && yRelease == 0) {

        QPixmap* newmovaghati = new QPixmap();
        newmovaghati->operator =(*pix);
        QPainter* movaghatpaniter125 = new QPainter(newmovaghati);
        movaghatpaniter125->setPen(pen);



        movaghatpaniter125->drawEllipse(xPress, yPress, xMove - xPress, yMove - yPress);
        for (int i = 0; i < tabwidget1.count(); i++)
            if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
                tabwidget1[i].lastlab->setPixmap(newmovaghati->scaled(pix->width(), pix->height(), Qt::AspectRatioMode::KeepAspectRatio));
    }
    else {
        painter->drawEllipse(xPress, yPress, xRelease - xPress, yRelease - yPress);
        for (int i = 0; i < tabwidget1.count(); i++)
            if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
                tabwidget1[i].lastlab->setPixmap(pix->scaled(pix->width(), pix->height(), Qt::AspectRatioMode::KeepAspectRatio));

        colorcombo->setHidden(true);
        sizespin->setHidden(true);
    }

}

void mainwindow::drawLine() {
    painter->setPen(pen);

    if (xRelease == 0 && yRelease == 0) {

        QPixmap* newmovaghati = new QPixmap();
        newmovaghati->operator =(*pix);
        QPainter* movaghatpaniter125 = new QPainter(newmovaghati);
        movaghatpaniter125->setPen(pen);


        movaghatpaniter125->drawLine(xPress, yPress, xMove, yMove);
        for (int i = 0; i < tabwidget1.count(); i++)
            if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
                tabwidget1[i].lastlab->setPixmap(newmovaghati->scaled(pix->width(), pix->height(), Qt::AspectRatioMode::KeepAspectRatio));

    }
    else {
        painter->drawLine(xPress, yPress, xRelease, yRelease);
        for (int i = 0; i < tabwidget1.count(); i++)
            if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
                tabwidget1[i].lastlab->setPixmap(pix->scaled(pix->width(), pix->height(), Qt::AspectRatioMode::KeepAspectRatio));
    }

}


void mainwindow::erase() {
    int Sizereaser = pen.width() + 4;
    QPen pen;
    pen.setColor(Qt::white);
    pen.setWidth(Sizereaser - 4);
    painter->setPen(pen);

    painter->drawRect(xMove, yMove, Sizereaser, Sizereaser);
    for (int i = 0; i < tabwidget1.count(); i++)
        if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex()))
            tabwidget1[i].lastlab->setPixmap(pix->scaled(pix->width(), pix->height(), Qt::AspectRatioMode::KeepAspectRatio));
}

void mainwindow::editpagedata(int numbertabwidget) {

    QByteArray bArray;
    QBuffer buffer(&bArray);
    buffer.open(QIODevice::WriteOnly);
    pix->save(&buffer, "PNG");
    QByteArray payam = QString("$$#^!0,%1*%2,").arg(tabwidget1[numbertabwidget].name).arg(tabwidget1[numbertabwidget].pagespin->value()).toUtf8() + bArray + QString("$!$&&$").toUtf8();
    shapeSocket->write(payam);


}


void mainwindow::colorAndSize() {

    pen.setColor(Qt::black);
    pen.setWidth(2);
    colorcombo = new QComboBox(this);
    colorcombo->addItem(QIcon(":/Color/icon_ha/black.PNG"), tr("Black"));
    colorcombo->addItem(QIcon(":/Color/icon_ha/red.PNG"), tr("Red"));
    colorcombo->addItem(QIcon(":/Color/icon_ha/blue.PNG"), tr("Blue"));
    colorcombo->addItem(QIcon(":/Color/icon_ha/green.PNG"), tr("Green"));
    colorcombo->addItem(QIcon(":/Color/icon_ha/yellow.PNG"), tr("Yellow"));
    colorcombo->addItem(QIcon(":/Color/icon_ha/perpele.PNG"), tr("Perpel"));
    colorcombo->addItem(QIcon(":/Color/icon_ha/gray.PNG"), tr("Gray"));
    colorcombo->addItem(QIcon(":/Color/icon_ha/white.PNG"), tr("White"));
    QComboBox* colorcombo1 = colorcombo;
    connect(colorcombo1, &QComboBox::currentTextChanged, this, [&](QString color) {if (color == tr("Black")) pen.setColor(Qt::black);
    else if (color == tr("Red")) pen.setColor(Qt::red);
    else if (color == tr("Blue")) pen.setColor(Qt::blue);
    else if (color == tr("Green")) pen.setColor(Qt::green);
    else if (color == tr("Yellow")) pen.setColor(Qt::yellow);
    else if (color == tr("Perpel")) pen.setColor(Qt::magenta);
    else if (color == tr("Gray"))  pen.setColor(Qt::gray);
    else if (color == tr("White")) pen.setColor(Qt::white); });

    sizespin = new QSpinBox(this);
    sizespin->setValue(2);
    sizespin->setMaximum(60);


    QRect mogh = ui.tabWidget->geometry();
    sizespin->setGeometry(mogh.x() + mogh.width() / 2, mogh.y() + mogh.height() + 35, 40, 20);
    colorcombo->setGeometry(sizespin->geometry().x() - 100, sizespin->geometry().y(), 100, 20);
    QSpinBox* sizespin1 = sizespin;
    connect(sizespin1, qOverload<int>(&QSpinBox::valueChanged), this, [&](int value) {pen.setWidth(value); });

    colorcombo1->setHidden(true);
    sizespin->setHidden(true);
}


void mainwindow::on_matnbtn_clicked(QPushButton* btn) {
    line = false;
    Drawing = false;
    rectangle = false;
    circle = 0;
    eraser = false;
    text = 1;
    if (painter == NULL)
    {


    }
    pix = new QPixmap();
    for (int i = 0; i < tabwidget1.count(); i++)
        if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex())) {
            *pix = tabwidget1[i].lastlab->pixmap()->scaled(tabwidget1[i].lastlab->width(), tabwidget1[i].lastlab->height());
        }

    //painter = new QPainter(pix);
    colorcombo->setHidden(false);
    sizespin->setHidden(false);


}

void mainwindow::drawText() {
    int num;
    if (xRelease == 0 && yRelease == 0) {

        QPixmap* newmovaghati = new QPixmap();
        newmovaghati->operator =(*pix);
        QPainter* movaghatpaniter125 = new QPainter(newmovaghati);
        movaghatpaniter125->setPen(pen);


        for (int i = 0; i < tabwidget1.count(); i++)
            if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex())) {
                tabwidget1[i].lastlab->setPixmap(newmovaghati->scaled(pix->width(), pix->height(), Qt::AspectRatioMode::KeepAspectRatio));
                num = i;
            }

    }
    else {

        for (int i = 0; i < tabwidget1.count(); i++)
            if (tabwidget1[i].name == ui.tabWidget->tabBar()->tabText(ui.tabWidget->tabBar()->currentIndex())) {
                tabwidget1[i].lastlab->setPixmap(pix->scaled(pix->width(), pix->height(), Qt::AspectRatioMode::KeepAspectRatio));
                num = i;
            }
    }
    textedit56.append(new QTextEdit(tabwidget1[num].scrollArea));
    if (textedit56.count() != 1) {
        textedit56[textedit56.count() - 2]->setReadOnly(true);
        textedit56[textedit56.count() - 2]->hide();
    }
    textedit56[textedit56.count() - 1]->viewport()->setAutoFillBackground(false);
    textedit56[textedit56.count() - 1]->setTextColor(pen.color());
    if(pen.width()!=1 && pen.width() != 0 && pen.width() != 2)
    textedit56[textedit56.count() - 1]->setFontPointSize(pen.width());
    //textedit->viewport()->setAutoFillBackground(false);
    //asli

    textedit56[textedit56.count() - 1]->setGeometry(xRelease - tabwidget1[num].scrollArea->horizontalScrollBar()->value(), yPress - tabwidget1[num].scrollArea->verticalScrollBar()->value(), -(xRelease - xPress), yRelease - yPress);
    textedit56[textedit56.count() - 1]->show();
    int x = xPress;
    int y = yPress;
    int width = -(xRelease - xPress);
    int height = yRelease - yPress;
    auto textedit1 = textedit56[textedit56.count() - 1];

    connect(tabwidget1[num].scrollArea->verticalScrollBar(), &QScrollBar::valueChanged, this, [&, textedit1, x, y, width, height](int a) {textedit1->setGeometry(textedit1->geometry().x(), y - a, width, height); });
    connect(tabwidget1[num].scrollArea->horizontalScrollBar(), &QScrollBar::valueChanged, this, [&, textedit1, x, y](int a) {textedit1->setGeometry(x - a, textedit1->geometry().y(), width, height); });
    auto temppix = pix;
    auto tempscroll = tabwidget1[num].scrollArea;
    connect(textedit56[textedit56.count() - 1], &QTextEdit::textChanged, this, [&, temppix, textedit1, num, tempscroll]() {

        QPainter* painter2 = new QPainter(temppix);
        QPixmap pixaz = textedit1->grab().scaled(textedit1->width(), textedit1->height());
        painter2->drawPixmap(textedit1->geometry().x() + tempscroll->horizontalScrollBar()->value() - 1, textedit1->geometry().y() - 1 + tempscroll->verticalScrollBar()->value(), textedit1->geometry().width(), textedit1->geometry().height(), pixaz);
        painter2->end();
        editpagedata(num);
        lab->setPixmap(*temppix);
        });
    int page = tabwidget1[num].pagespin->value();
    connect(tabwidget1[num].pagespin, qOverload<int>(&QSpinBox::valueChanged), this, [&, page, textedit1](int page1)
        {if (page != page1)
        textedit1->setHidden(true);
        else textedit1->setHidden(false);
    lab->setPixmap(*temppix); });
    editpagedata(num);
    text = 0;


    colorcombo->setHidden(true);
    sizespin->setHidden(true);
}

void mainwindow::on_Screenbtn_clicked() {
    if (ui.Screenbtn->text() == tr("Emittion"))
    {
        if (timerforScreen == nullptr) {
            timerforScreen = new QTimer(this);
            QCursor cur = cursor();
            QTcpSocket* socket1=screenSocket;
            connect(timerforScreen, &QTimer::timeout, this, [&,socket1,cur]() {task* ruuu = new task(socket1,cur); QThreadPool::globalInstance()->start(ruuu); }, Qt::ConnectionType::QueuedConnection);
            timerforScreen->setInterval(250);
        }

        timerforScreen->start();
        screenSocket->write(QByteArray(QString("@%*@on@%*@").toUtf8()));

        ui.Screenbtn->setText(tr("Stop"));
    }
    else if (ui.Screenbtn->text() == tr("Stop"))
    {
        timerforScreen->stop();
        screenSocket->write(QByteArray(QString("@%*@off@%*@").toUtf8()));
        //widgetScreen->close();
        ui.Screenbtn->setText(tr("Emittion"));
    }
}


void mainwindow::sendfinish() {
    QString payam("ClassFinished");
    permitSocket->write(QByteArray(payam.toUtf8()));
}

mainwindow::task::task(QTcpSocket* socket,QCursor cursersec) {
    tempscreensocket = socket;
    tempcurser = cursersec;
}

void mainwindow::task::run() {

    QScreen* screen = QGuiApplication::primaryScreen();
    QPixmap originalPixmap = screen->grabWindow(0);
    QPainter painter(&originalPixmap);
    QPixmap pixmouse(":/mainwindow/icon_ha/icons8-cursor-100.png");
    painter.drawPixmap(tempcurser.pos().x() - 10, tempcurser.pos().y() - 7, 30, 30, pixmouse);
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    originalPixmap.save(&buffer, "jpg");

    QByteArray payam = QString("##!#").toUtf8() + bytes + QString("#!$#").toUtf8();
    tempscreensocket->write(payam);
    tempscreensocket->flush();
    tempscreensocket->waitForBytesWritten(100);
    this->setAutoDelete(1);
}
