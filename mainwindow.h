#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

#include "qtcpsocket.h"
#include "CheckeClass.h"
#include <QAudioInput>
#include "qaudioformat.h"
#include "qaudiodeviceinfo.h"
#include "qaudioinput.h"
#include "qaudiooutput.h"
#include "qaudiorecorder.h"
#include "qscreen.h"
#include <QIODevice>
#include "qscrollbar.h"
#include "qcheckbox.h"
#include "qdialog.h"
#include "qwidget.h"
#include "qbytearray.h"
#include "qcamera.h"
#include "qcameraviewfinder.h"
#include "qcamerainfo.h"
#include "qtimer.h"
#include "qbuffer.h"
#include "qtoolbutton.h"
#include <QSpacerItem>
#include "qslider.h"
#include "qspinbox.h"
#include "qscrollarea.h"
#include "qradiobutton.h"
#include "qfiledialog.h"
#include "qprocess.h"
#include "qmessagebox.h"
#include "qprogressbar.h"
#include "qprogressdialog.h"
#include "qcursor.h"
#include "qpoint.h"
#include "qpainter.h"
#include "qpainterpath.h"
#include "qscroller.h"
#include "qscrollerproperties.h"
#include "qscreen.h"
#include "qdesktopwidget.h"
#include "qthread.h"
#include "qrunnable.h"
#include "qthreadpool.h"


#define port1 23245
class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::mainwindowClass ui;
public:
    QTcpSocket* permitSocket; //0
    QTcpSocket* chatSocket; //1
    QTcpSocket* voiceSocket; //2
    QTcpSocket* webcamSocket; //3
    QTcpSocket* noteSocket; //4
    QTcpSocket* mouseSocket; //5
    QTcpSocket* shapeSocket; //6
    QTcpSocket* sendSocket; //7
    QTcpSocket* attendessSocket; //8
    QTcpSocket* screenSocket;//9

    QString Username1;
    bool Professor = false;

    bool microphone = false;
    bool webcam = false;
    bool content = false;

    QHostAddress hostadderss1;
    QString classid123;

    QAudioInput* input_voice;
    QAudioOutput* output_voice;
    QIODevice* input_device;
    QIODevice* output_device;

    QCamera* camera1 = nullptr;
    QCameraViewfinder* cameraviewfinder1;
    QByteArray Allwebcamdata1;
    QByteArray Allsended;
    QByteArray Allscreen;
    QTimer* timerwebcam;

    struct Tabwidget
    {
        QString name;
        QSlider* Sliderzoom;
        QSpinBox* pagespin;
        QScrollArea* scrollArea;
        QLabel* lastlab;
    };
    QVector<Tabwidget> tabwidget1;
    QTimer* timerformouse;
    struct LastContent
    {
        QString name = "";
        int zoom;
        int page;
        int verscroll;
        int horscroll;
    }lastContent;
    QLabel* mouselab;
    bool initialEntered = true;

    bool Drawing = 0, rectangle = 0, circle = 0, line = 0, eraser = 0, text = 0;
    int xMove;
    int yMove;
    int xPress;
    int yPress;
    int xRelease;
    int yRelease;
    QLabel* lab;
    QLabel* labaz;
    QPixmap* pix;
    QPainterPath* path;
    QPainter* painter = nullptr;

    QComboBox* colorcombo;
    QSpinBox* sizespin;
    QPen pen;
    QTextEdit* textedit;
    QVector<QTextEdit*> textedit56;
    QTimer* timerforScreen = nullptr;
    QWidget* widgetScreen = nullptr;
    QLabel* labscreen;

    class task :public QRunnable
    {
    public:
        task(QTcpSocket* socket, QCursor cursersec);
        QTcpSocket* tempscreensocket;
        QCursor tempcurser;

    protected:
        void run();

    };

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

public slots:
    void Initialstart();
    void ReadpermitSocket();
    void ReadchatSocket();
    void ReadvoiceSocket();
    void ReadwebcamSocket();
    void ReadnoteSocket();
    void ReadmouseSocket();
    void ReadshapeSocket();
    void ReadsendSocket();
    void ReadattendessSocket();
    void ReadscreenSocket();

    void startlisenVoice();
    void sendvoiceToServer();
    void Preparationsendvoice();
    void on_pushButton_4_clicked();
    void btnPerson(QString username, QString name);
    void sendStatus();
    void sendnote();
    void sendchat();
    void sendchangeaccesToserver(QString username, QCheckBox* microphone, QCheckBox* webcam, QCheckBox* content, QDialog* dialog);

    void Preparationwebcam();
    void sendwebcam();
    void on_pushButton_2_clicked();

    void PDFContent(QString name, int numberpage);
    void newContent();
    void imageContent();
    void openpdf();
    void openimage();
    void sendpdftoServer(int numberPage, QString dirfilepng, QString nameoffile23);
    void sendreqChangepage(QString name, int pagenumber);
    void sendcurrenttabAndContent(int indexnow);

    void on_mousebtn_clicked(QPushButton* btn);
    void on_khatbtn_clicked(QPushButton* btn);
    void on_medadbtn_clicked(QPushButton* btn);
    void on_pakkonbtn_clicked(QPushButton* btn);
    void on_morababtn_clicked(QPushButton* btn);
    void on_dayerebtn_clicked(QPushButton* btn);
    void on_matnbtn_clicked(QPushButton* btn);
    void AnalizMouseForSend(QCursor cursor1);
    void changesync();

    void draw();
    void drawRectangle();
    void drawCircel();
    void drawLine();
    void erase();
    void drawText();

    void editpagedata(int numbertabwidget);
    void colorAndSize();

    void on_Screenbtn_clicked();
    void sendfinish();
};
