//
// Created by maesly on 19/09/17.
//

#ifndef REMOTEMEMORYPROYECTOUNO_LISTA_H
#define REMOTEMEMORYPROYECTOUNO_LISTA_H


#include <iostream>
#include <stdlib.h>
using namespace std;
/**
 * @brief Inicializa el nodo
 *
 */
struct nodo{
    int numero;
    struct nodo *siguiente;
};

typedef struct nodo *Tlista;

/**
 * @brief Inserta valores al inicio de la lista enlazada.
 * @param lista
 * @param valor
 */

void insertar(Tlista &lista, int valor)
{
    Tlista q;
    q = new(struct nodo);
    q->numero = valor;
    q->siguiente = lista;
    lista  = q;
}

/**
 *
 * @brief Esta funcion se encarga de imprimir los elementos de la lista
 * @param lista
 */
void ImprimirLista(Tlista lista)
{
    int i = 0;

    while(lista != NULL)
    {
        cout <<' '<< i+1 <<") " << lista->numero << endl;
        lista = lista->siguiente;
        i++;
    }
}

/**
 * @brief Funcion que se encarga de eliminar un elemento deseado de la lista
 * @param lista
 * @param valor
 *
 */

void eliminarElemento(Tlista &lista, int valor)
{
    Tlista p, ant;
    p = lista;

    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->numero==valor)
            {
                if(p==lista)
                    lista = lista->siguiente;
                else
                    ant->siguiente = p->siguiente;

                delete(p);
                return;
            }
            ant = p;
            p = p->siguiente;
        }
    }
    else
        cout<<" Lista vacia..!";
}

/**
 *@brief Esta es la funcion main que contiene las opciones de
 * insertar, eliminar y buscar en la lista.
 * Main
 */

int mainSinglyLinkedList(){
    int dato;
    Tlista lista = NULL;
    int opcion = 0;
    while(opcion !=300){
        cout<<"1.Ingresar un Elemento"<<endl;
        cout<<"2.Eliminar Elemento"<<endl;
        cout<<"3.Mostrar lista"<< endl;
        cout<<"4.Salir"<<endl;
        cin>>opcion;

        switch (opcion){
            case 1:
                cout << "\n Elemento que desea insertar: ";
                cin >> dato;
                insertar(lista,dato);
                break;
            case 2:
                cout<<"\n Elemento que desea eliminar:"<<endl;
                cin >> dato;
                eliminarElemento(lista,dato);
                break;
            case 3:
                cout << "\n Mostrando la lista ";
                cin >> dato;
                ImprimirLista(lista);
                break;
            case 4:
                opcion = 300;
                break;

            default:
                cout<<"Opcion Incorrecta"<<endl;

        }

    }

}


#endif //REMOTEMEMORYPROYECTOUNO_LISTA_H
