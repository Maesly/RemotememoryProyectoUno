//
// Created by maesly on 15/09/17.
//

#ifndef REMOTEMEMORYPROYECTOUNO_ARRAYLIST_H
#define REMOTEMEMORYPROYECTOUNO_ARRAYLIST_H
struct Memoria{
    int llave;
    int valor;

    Memoria();
    Memoria(const int &key, int value);
    ~Memoria();
    static int mainEstructura() ;
};
#endif //REMOTEMEMORYPROYECTOUNO_ARRAYLIST_H
