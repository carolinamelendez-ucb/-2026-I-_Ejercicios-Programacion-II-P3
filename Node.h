#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {
private:
    T valor; //dato
    Node* ptrSiguiente; //puntero a otro dato
public:
    Node(T nuevoValor) {
        valor = nuevoValor;
        ptrSiguiente = nullptr;
    }

    //setters y getters para valor
    void setValor(T nuevoValor) {
        valor = nuevoValor;
    }

    T getValor() {
        return valor;
    }

    //setters y getters para siguiente
    void setSiguiente(Node<T>* nuevoSiguiente) {
        ptrSiguiente = nuevoSiguiente;
    }

    Node<T>* getSiguiente() {
        return ptrSiguiente;
    }
};