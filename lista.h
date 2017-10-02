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
    int nro;
    struct nodo *sgte;
};

typedef struct nodo *Tlista;

/**
 * @brief Inserta valores al inicio de la lista enlazada.
 * @param lista
 * @param valor
 */

void insertarInicio(Tlista &lista, int valor)
{
    Tlista q;
    q = new(struct nodo);
    q->nro = valor;
    q->sgte = lista;
    lista  = q;
}


/**
 * @brief Su función es buscar el elemento deseado dentro de una lista.
 * @param lista
 * @param valor
 */
void buscarElemento(Tlista lista, int valor)
{
    Tlista q = lista;
    int i = 1, band = 0;

    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        q = q->sgte;
        i++;
    }

    if(band==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;
}
/**
 *
 * @brief Esta funcion se encarga de imprimir los elementos de la lista
 * @param lista
 */
void reportarLista(Tlista lista)
{
    int i = 0;

    while(lista != NULL)
    {
        cout <<' '<< i+1 <<") " << lista->nro << endl;
        lista = lista->sgte;
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
            if(p->nro==valor)
            {
                if(p==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = p->sgte;

                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}

/**
 * @brief Funcion que elimina los elementos repetidos en la lista
 */

void eliminaRepetidos(Tlista &lista, int valor){

    Tlista q, ant;
    q = lista;
    ant = lista;

    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            if(q==lista) // primero elemento
            {
                lista = lista->sgte;
                delete(q);
                q = lista;
            }
            else
            {
                ant->sgte = q->sgte;
                delete(q);
                q = ant->sgte;
            }
        }
        else
        {
            ant = q;
            q = q->sgte;
        }

    }// fin del while

    cout<<"\n\n Valores eliminados..!"<<endl;
}

/**
 *@brief Esta es la funcion main que contiene las opciones de
 * insertar, eliminar y buscar en la lista.
 * Main
 */

int mainSinglyLinkedList(){


    Tlista lista = NULL;

    int n;
    int dato;

    cout << " Numero de elementos de la lista:  ";
    cin >> n;
    cout << endl;

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        int x = rand() % 10000;
        insertarInicio(lista, x);
    }
    cout << "\n\n MOSTRANDO LISTA\n\n";
    reportarLista(lista);
    cout<<"\n"<<endl;

    int opcion = 0;
    while(opcion !=300){
        cout<<"1.Buscar un Elemento"<<endl;
        cout<<"2.Eliminar Elemento"<<endl;
        cout<<"3.Ingresar Elemento"<<endl;
        cout<<"4.Salir"<<endl;
        cin>>opcion;

        switch (opcion){

            case 1:

                cout << "\n Valor a buscar: ";
                cin >> dato;
                buscarElemento(lista, dato);
                break;

            case 2:
                cout<<"\n Mostrando Lista"<<endl;
                reportarLista(lista);
                cout << "\n Valor a Eliminar: ";
                cin >> dato;
                eliminarElemento(lista,dato);
                break;


            case 3:
                cout << "\n Valor a Ingresar: ";
                cin >> dato;
                insertarInicio(lista,dato);
                reportarLista(lista);
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
