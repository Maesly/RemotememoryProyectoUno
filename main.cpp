#include <iostream>
#include <netinet/in.h>
#include "server.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Servidor* servidor = new Servidor(sockaddr_in());
    servidor->begin();

    return 0;
}