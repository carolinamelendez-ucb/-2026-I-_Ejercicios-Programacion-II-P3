#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
private:
    T valor;
    Node<T>* ptrSiguiente;

public:
    Node(T nuevoValor) {
        valor = nuevoValor;
        ptrSiguiente = nullptr;
    }

    void setValor(T nuevoValor) {
        valor = nuevoValor;
    }

    T getValor() {
        return valor;
    }

    void setSiguiente(Node<T>* nuevoSiguiente) {
        ptrSiguiente = nuevoSiguiente;
    }

    Node<T>* getSiguiente() {
        return ptrSiguiente;
    }
};
