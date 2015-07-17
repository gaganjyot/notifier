#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {

    // No title bar, Stays on top always
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint |
                   Qt::WindowStaysOnTopHint);

    // Maths for good location and size
    height = QApplication::desktop()->screenGeometry().height();
    width = QApplication::desktop()->screenGeometry().width();
    resize(width*.28,height*.1);
    move(width*.7, height*.1);
    v = new QVBoxLayout;
    t = new QTextEdit;

    // Text Box formatting
    t->setFrameStyle(QFrame::NoFrame);
    t->setEnabled(false);
    t->setFont(QFont("Arial", 16, 2));

    stylesheet = "QWidget { background-color : rgb(34, 49, 63) } QTextEdit { background-color : rgb(34, 49, 63) } QTextEdit { color : rgb(25, 181, 254) }";

    this->setStyleSheet(stylesheet);
    this->hide();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(process()));
    timer->setSingleShot(false);
    timer->setInterval(6000);
    timer->start();

    v->addWidget(t);
    this->setLayout(v);
}

void MainWindow::recieveMsg(QString v) {
    vec.push_back(v);
}

void MainWindow::process() {
    if(!vec.empty()) {
        QString tmp = vec.front();
        t->setText(tmp);
        vec.pop_front();
        this->show();
        QTimer::singleShot(5000, this, SLOT(hide()));
    }
}

MainWindow::~MainWindow()
{
    delete(t);
    delete(l);
    delete(v);
}
