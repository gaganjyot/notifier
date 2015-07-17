#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QObject>
#include <QTimer>
#include <QVector>

class MainWindow : public QWidget
{
    Q_OBJECT

    int height, width;
    QVBoxLayout *v;
    QLabel *l;
    QTextEdit *t;
    QString stylesheet;
    QTimer *timer;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QVector<QString> vec;

public slots:
    void recieveMsg(QString v);

private slots:
    void process();
};

#endif // MAINWINDOW_H
