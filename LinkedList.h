#pragma once
#include <string>
#include <iostream>
#include "Nodo.h"

using namespace std;

template <class T>
class LinkedList {
private:
	Nodo<T>* primerNodo;

public:
	LinkedList() {
		primerNodo = nullptr;
	}

    void agregar(T nuevoValor) {
        Nodo<T>* nuevo = new Nodo<T>(nuevoValor);
        if (this->primerNodo == nullptr) {
            this->primerNodo = nuevo;
        }
        else {
            Nodo<T>* actual = this->primerNodo;
            while (actual->getSiguiente() != nullptr) {
                actual = actual->getSiguiente();
            }
            actual->setSiguiente(nuevo);
        }
    }

    void mostrar() {
		Nodo<T>* actual = this->primerNodo;
        while (actual != nullptr) {
			actual->mostrarValor();
			actual = actual->getSiguiente();
        }
    }

    /*friend ostream& operator<<(ostream& os, const LinkedList<T>& lista) {
        Nodo<T>* actual = lista.primerNodo;
        while (actual != nullptr) {
            os << actual->getValor() << endl;
            actual = actual->getSiguiente();
        }
        return os;
    }

    void mostrar() {
        cout << *this;
	}*/

};