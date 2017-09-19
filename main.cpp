#include <iostream>
#include <netinet/in.h>
#include "server.h"
#include "Estructura.h"

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <thread>
#include <stdio.h>
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Servidor* servidor = new Servidor(sockaddr_in());
    servidor->iniciar();
    //Memoria::mainEstructura();
}