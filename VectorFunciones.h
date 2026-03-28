#pragma once
#include "Funcion.h"

class VectorFunciones {

private:
    Funcion** funciones;
    int indice;
    int tamanio;

public:

    VectorFunciones(int tamanio) : tamanio(tamanio), indice(0) {
        funciones = new Funcion * [tamanio];
    }

    ~VectorFunciones() {
        for (int i = 0; i < indice; i++) delete funciones[i];
        delete[] funciones;
    }

    void agregar(Funcion* nuevaFuncion) {
        if (buscar(nuevaFuncion->getCodigo()) != nullptr) {
            cout << "Codigo duplicado" << endl;
            delete nuevaFuncion;
            return;
        }

        if (indice < tamanio) {
            funciones[indice++] = nuevaFuncion;
        }
    }

    Funcion* buscar(int codigo) {
        for (int i = 0; i < indice; i++) {
            if (funciones[i]->getCodigo() == codigo) return funciones[i];
        }
        return nullptr;
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            funciones[i]->mostrar();
            cout << endl;
        }
    }
};