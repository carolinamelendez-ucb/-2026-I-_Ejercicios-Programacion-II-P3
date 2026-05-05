#pragma once
#include <iostream>
#include<string>
using namespace std;
template<typename>
class Node {
private:
    string valor;
    Node* ptrsiguiente;

public:
    // Constructor
    Node(string nuevoValor) {
        valor = nuevoValor;
        ptrsiguiente = nullptr;
    }

    // Setter y getter para valor
    void setValor(string nuevoValor) {
        valor = nuevoValor;
    }

    string getValor() {
        return valor;
    }

    // Setter y getter para siguiente
    void setSiguiente(Node* nuevoSiguiente) {
        ptrsiguiente = nuevoSiguiente;
    }

    Node* getSiguiente() {
        return ptrsiguiente;
    }

    // Agregar nodo siguiente correctamente
    void agregarSiguiente(string nuevoValor) {
        ptrsiguiente = new Node(nuevoValor);
    }
};