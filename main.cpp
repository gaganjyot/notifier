#include <QApplication>
#include <netw.h>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    // Port : 4000
    // Packet Size : 5000 Bytes

    netw *n = new netw(4000, 5000);

    a.connect(n, SIGNAL(sendMsg(QString)), &w, SLOT(recieveMsg(QString)));
    n->start();
    return a.exec();
}
