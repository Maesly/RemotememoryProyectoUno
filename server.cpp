//
// Created by maesly on 15/09/17.
//

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <thread>
#include <stdio.h>
#include "server.h"

using namespace std;
/**
* Constructor de la clase
*/
Servidor::Servidor(sockaddr_in server_addr) : server_addr(server_addr) {
    isExit = false;
}


/**
* Detiene el servidor
*/
void Servidor::stop(){
    isExit = true;
    shutdown(client,SHUT_RDWR);
}
/**
* Inicializador
*/
void Servidor::begin(){
    client = socket(AF_INET,SOCK_STREAM,0);
    run();
}
/**
* Deconstructor de la clase
*/
Servidor::~Servidor(){ }

/**
* Metodo principal para escuchar por nuevos clientes
*/
void Servidor::run(){
    if(client<0){
        cout << "Error estableciendo el socket..." << endl;
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(port);
    if((bind(client,(struct sockaddr*) &server_addr,sizeof(server_addr)))<0){
        cout << "Error enlazando la conexión, la conexión ya ha sido creada" << endl;
    }
    //cout <<"Bienvenido, la conexion ha sido creada..."<< endl;
    size = sizeof(server_addr);
    listen(client,maxClients);

    while(!isExit){
        server = accept(client,(struct sockaddr*) &server_addr,&size);
        if(server>=0){
            char* buffer = (char*) calloc(1,1024);
            while(!isExit){
                recv(server, buffer, 1024, 0);
                printf("%s\n",buffer);
                send(server,buffer,1024,0);
            }
        }else{
            break;
            cout << "Error aceptando el cliente" <<endl;
            exit(1);
        }
    }
}