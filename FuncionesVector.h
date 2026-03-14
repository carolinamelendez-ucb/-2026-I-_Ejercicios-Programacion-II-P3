#pragma once
#include "Funcion.h"

class FuncionesVector {

private:
    Funcion** funciones;
    int indice;
    int tamanio;

public:

    FuncionesVector(int tamanio)
        : tamanio(tamanio), indice(0)
    {
        funciones = new Funcion * [tamanio];
    }

    ~FuncionesVector() {
        for (int i = 0; i < indice; i++) {
            delete funciones[i];
        }
        delete[] funciones;
    }

    void agregar(Funcion* funcion) {
        if (indice < tamanio) {
            funciones[indice] = funcion;
            indice++;
        }
    }

    Funcion* getFuncion(int pos) {
        return funciones[pos];
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            funciones[i]->mostrar();
            cout << endl;
        }
    }
};