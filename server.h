//
// Created by maesly on 15/09/17.
//

#ifndef REMOTEMEMORYPROYECTOUNO_SERVER_H
#define REMOTEMEMORYPROYECTOUNO_SERVER_H
class Servidor{

private:
    int cliente,servidor;              //Sockets
    const int port = 8080;          //Puerto por el que se va a comunicar
    const int maxClientes = 10;      //Maximo de cliente que se van a conectar
    int bufsize = 1024;             // tamaño de los char que se van a enviar y recibir
    //int clientCout;
    char* buffer = new char(bufsize);
    bool salir;
    struct sockaddr_in server_addr;
    socklen_t size;

public:
    Servidor(sockaddr_in server_addr);
    ~Servidor();
    void iniciar();
    void correr();
    void detener();

};
#endif //REMOTEMEMORYPROYECTOUNO_SERVER_H
