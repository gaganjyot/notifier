#ifndef NETW_H
#define NETW_H

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <strings.h>
#include <QObject>
#include <QThread>
#include <QString>

class netw : public QThread
{
    Q_OBJECT

public:
    netw(int port, int packetSize);
    ~netw();

signals:
    void sendMsg(QString s);

protected:
    void run();

private:
    int sockServ, sockCli, servLen, cliLen;
    struct sockaddr_in servAddr, cliAddr;
    char* buff;
    int buffSize;
    int port;
};

#endif // NETW_H
