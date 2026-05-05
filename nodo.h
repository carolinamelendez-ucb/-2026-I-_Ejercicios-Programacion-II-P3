#pragma once

#include <iostream>
using namespace std;

template <class T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;

    Nodo(T dato) {
        this->dato = dato;
        this->siguiente = NULL;
    }
};