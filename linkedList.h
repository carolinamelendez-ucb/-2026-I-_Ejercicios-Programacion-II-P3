#pragma once
#include <iostream>
#include <string>
#include "Nodo.h"
using namespace std;
template < class T>

class LinkedList {
private:
    Node<T>* primerNodo;

public:
    LinkedList() {
        primerNodo = nullptr;
    }

    void agregar(T valor) {
        Node<T>* nuevo = new Node<T>(valor);

        if (primerNodo == nullptr) {
            primerNodo = nuevo;
        }
        else {

            Node<T>* actual = primerNodo;
            while (actual->getSiguiente() != nullptr) {
                actual = actual->getSiguiente();
            }
            actual->setSiguiente(nuevo);
        }
    }

    void mostrar() {
        Node<T>* actual = primerNodo;

        while (actual != nullptr) {
            cout << actual->getValor() << endl;
            actual = actual->getSiguiente();
        }
    }
};