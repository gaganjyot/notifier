#include "netw.h"

netw::netw(int port, int packetSize) {
    buffSize = packetSize;
    this->port = port;
    this->buff = (char*)calloc(packetSize, sizeof(char));
}

void netw::run() {
    sockServ = socket(AF_INET, SOCK_STREAM, 0);

    if(sockServ < 0) {
        printf("ERROR : SOCKET CREATION\n");
        exit(-1);
    }

    bzero(&servAddr, sizeof(struct sockaddr));

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(port);
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sockServ, (const struct sockaddr*)&servAddr, (socklen_t)sizeof(servAddr)) < 0) {
        printf("ERROR : BIND SERVER SOCKET\n");
        exit(-1);
    }

    if(listen(sockServ, 5) < 0) {
        printf("ERROR : LISTEN\n");
        exit(-1);
    }

    cliLen = sizeof(cliAddr);

    while(1) {
        sockCli = accept(sockServ, (struct sockaddr*) &cliAddr, (socklen_t *)&cliLen);
        if(sockCli < 0) {
            printf("ERROR : ACCEPT\n");
            exit(-1);
        }
        bzero(buff, buffSize);
        read(sockCli, buff, buffSize);
        emit sendMsg(QString(buff));
        close(sockCli);
    }
}

netw::~netw() {
    this->wait();
    this->exit();
}
