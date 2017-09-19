//
// Created by maesly on 15/09/17.
//

#ifndef REMOTEMEMORYPROYECTOUNO_SERVER_H
#define REMOTEMEMORYPROYECTOUNO_SERVER_H
/**
 * @file server.h
 * @class Servidor
 * @brief Esta clase es el header del archivo server.cpp donde se
 * inicializan las variables que usará y se declaran las funciones
 * de la clase
 * */
class Servidor{

private:

    int cliente,servidor;               // Sockets
    const int port = 8080;              // Puerto por el que se va a comunicar
    int bufsize = 1024;                 // tamaño de los char que se van a enviar y recibir
    char* buffer = new char(bufsize);   // buffer son los char que se van a enviar y recibir
    bool salir;                         // booleano que se utiliza en el while como condicion

    struct sockaddr_in server_addr;
    socklen_t size;

public:
    Servidor(sockaddr_in server_addr);   // Declaracion del constructor de la clase
    ~Servidor();                         // Declaracion del destructor de la clase
    void iniciar();                      // funcion que permite iniciar el servidor
    void correr();                       // funcion que ejecuta el codigo del servidor
    void detener();                      // funcion que detiene el servidor

};
#endif //REMOTEMEMORYPROYECTOUNO_SERVER_H
