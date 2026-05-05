#pragma once
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

template <typename T>
class LinkedList {
private:
    Node<T>* primerNodo; // head

public:
    LinkedList() : primerNodo(nullptr) {}

    // Agrega un nuevo elemento al final de la lista
    void agregar(T nuevoValor) {
        Node<T>* nuevo = new Node<T>(nuevoValor);
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

    // Muestra todos los elementos de la lista
    void mostrar() {
        Node<T>* actual = primerNodo;
        while (actual != nullptr) {
            cout << actual->getValor() << endl;
            actual = actual->getSiguiente();
        }
    }
};