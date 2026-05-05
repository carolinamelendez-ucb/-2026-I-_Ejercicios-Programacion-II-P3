#pragma once
#include <iostream>
#include<string>
#include"Note.h"
using namespace std;
template<class U>
class LinkeList {
private:
    Node<U>* primerNodo;
public:
    LinkeList() {
        primerNodo = nullptr;
    }
    void Agregar(U nuevoValor) {
        Node<U>* nuevo = new Node<U>(nuevoValor);
        if (primerNodo == nullptr) {
            primerNodo = nuevo;
        }
        else {
            Node<U>* actual = primerNodo;
            while (actual->getSiguiente() != nullptr) {
                actual = actual->getSiguiente();
            }
            actual->setSiguiente(nuevo);
        }
    }

    void mostrar() {
        if (primerNodo == nullptr) {
            cout << "Lista vacía" << endl;
            return;
        }

        Node<U>* actual = primerNodo;
        while (actual != nullptr) {
            cout << "Valor: " << actual->getValor() << endl;
            actual = actual->getSiguiente();
        }
    }
};