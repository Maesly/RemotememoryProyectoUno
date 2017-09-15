//
// Created by maesly on 15/09/17.
//

#ifndef REMOTEMEMORYPROYECTOUNO_SERVER_H
#define REMOTEMEMORYPROYECTOUNO_SERVER_H
class Servidor{

private:
    int client,server;
    const int port = 2400;
    const int maxClients = 10;
    int bufsize;
    int clientCout;
    bool isExit;
    struct sockaddr_in server_addr;
    socklen_t size;

public:
    Servidor(sockaddr_in server_addr);
    ~Servidor();
    void begin();
    void run();
    void stop();

};
#endif //REMOTEMEMORYPROYECTOUNO_SERVER_H
