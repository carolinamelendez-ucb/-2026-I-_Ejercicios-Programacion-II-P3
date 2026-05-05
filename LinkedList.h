#pragma once
#include <iostream>
#include "nodo.h"
using namespace std;

template <class T>
class LinkedList {
private:
    Nodo<T>* cabeza;

public:
    LinkedList() {
        cabeza = NULL;
    }
    void agregar(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);

        if (cabeza == NULL) {
            cabeza = nuevo;
        }
        else {
            Nodo<T>* aux = cabeza;

            while (aux->siguiente != NULL) {
                aux = aux->siguiente;
            }

            aux->siguiente = nuevo;
        }
    }
    void mostrar() {
        Nodo<T>* aux = cabeza;

        while (aux != NULL) {
            aux->dato.mostrar(); 
            aux = aux->siguiente;
        }
    }
};