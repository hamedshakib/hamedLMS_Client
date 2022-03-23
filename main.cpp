#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include "SelectionClass.h"
#include "qtranslator.h"
#include "qfile.h"
#include "qdebug.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //mainwindow w;
    //w.show();

    QTranslator translator;
    qDebug() << translator.load(":/new/file/lms1_fa.qm");
    QFile file("loglan");
    if (file.open(QIODevice::ReadOnly))
        if (file.readAll() == "1") {
            a.installTranslator(&translator);
        }

    SelectionClass* selec = new SelectionClass();
    selec->setWindowTitle("Hamed Lms");
    selec->setWindowIcon(QIcon(":/mainwindow/icon_ha/28-512.png"));
    a.setApplicationName("Hamed Lms");
    a.setWindowIcon(QIcon(":/mainwindow/icon_ha/28-512.png"));
    a.setApplicationDisplayName("Hamed Lms");
    selec->show();

    return a.exec();
}
