//
// Created by maesly on 15/09/17.
//
//Se incluyen todas las bibliotecas necesarias para ejecutar el servidor

/**
 * @file server.cpp
 *@brief En este archivo se complementa el cuerpo de las funciones declaradas en el header
 *
 * */
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
#include "lista.h"

using namespace std;
/**
* Constructor de la clase
*/

Servidor::Servidor(sockaddr_in server_addr) : server_addr(server_addr) {
    salir = false;
}


/**
* @brief Detiene el servidor cambiando el booleano salir a true
*
*/
void Servidor::detener(){
    salir = true;
    shutdown(cliente,SHUT_RDWR);
}
/**
* @brief Funcion que inicializa el socket cliente y llama la funcion correr()
*/
void Servidor::iniciar(){
    cliente = socket(AF_INET,SOCK_STREAM,0); // se crea el dominio de socket
    correr();
}
/**
* @brief Deconstructor de la clase
*/
Servidor::~Servidor(){ }

/**
* @brief Metodo principal para escuchar por nuevos clientes y realizar un chat entre clientes/servidor
*/

void Servidor::correr(){

    if(cliente<0){ // verifica que el socket se haya creado correctamente
        cout << "Error estableciendo el socket..." << endl;
        exit(1);
    }

    // Se asigna a la estructura sock_addr un dominio,ip y un puerto
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if((bind(cliente,(struct sockaddr*) &server_addr,sizeof(server_addr)))<0){ // se crea la conexion con el puerto y el socket
        cout << "Error enlazando la conexión...\n" << endl;
        exit(-1);

    }

    cout <<"Bienvenido"<< endl;
    size = sizeof(server_addr);
    listen(cliente,1); // El servidor escucha a los clientes

    while(!salir) {                                                             // condicion que mantiene corriendo el servidor
        servidor = accept(cliente,(struct sockaddr*) &server_addr,&size);
        if(servidor>=0){
            char* buffer = (char*) calloc(1,1024);
            while(!salir){

                recv(servidor, buffer, 1024, 0);
                printf("%s\n",buffer);
                Tlista* lista = new Tlista;

                if(*buffer == '1'){
                    mainSinglyLinkedList();
                    send(cliente,buffer,bufsize,0);

                    insertarInicio(reinterpret_cast<Tlista &>(lista), 45);
                    reportarLista(reinterpret_cast<Tlista>(lista));
                    send(servidor,buffer,1024,0);
                    reportarLista(reinterpret_cast<Tlista>(lista));

                }
                else if(*buffer == '2') {
                    buscarElemento(reinterpret_cast<Tlista>(lista), *buffer);
                    reportarLista(reinterpret_cast<Tlista>(lista));

                    send(servidor,buffer,1024,0);
                }else if(*buffer == '3'){
                    eliminarElemento(reinterpret_cast<Tlista &>(lista), *buffer);
                    reportarLista(reinterpret_cast<Tlista>(lista));
                    send(servidor,buffer,1024,0);
                }else if (*buffer == 'salir'){
                    salir = true;
                }
                else{
                    close(cliente);
                }
            }
            close(cliente);
        }else {
            close(cliente);
        }
    }
}