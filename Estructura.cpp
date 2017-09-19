//
// Created by maesly on 15/09/17.
//
#include <iostream>
#include "Estructura.h"


Memoria::Memoria() {
    llave = 0;
    valor = 0;
}

Memoria::~Memoria() {
    std:: cout << "Adiós"<<std::endl;
}

Memoria::Memoria(const int &key, int value) {
    llave = key;
    valor = value;
}

int Memoria::mainEstructura(){

    Memoria *nuevo;
    int x = 10;
    std:: cout << "La llave es: "<< nuevo->llave<< std::endl;
    std:: cout << "El valor es: "<< nuevo->valor<<std::endl;
    nuevo = new Memoria(x, 10);
    nuevo->valor = 45;

    std:: cout << "La llave es: "<< nuevo->llave<< std::endl;
    std:: cout << "El valor es: "<< nuevo->valor;
    return 0;
}
