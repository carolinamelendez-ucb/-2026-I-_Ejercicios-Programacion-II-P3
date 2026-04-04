#pragma once
#include "Operador.h"

class VectorOperadores {

private:
    Operador** operadores;
    int indice;
    int tamanio;

public:

    VectorOperadores(int tamanio) : tamanio(tamanio), indice(0) {
        operadores = new Operador * [tamanio];
    }

    ~VectorOperadores() {
        for (int i = 0; i < indice; i++) delete operadores[i];
        delete[] operadores;
    }

    Operador* buscar(string ci) {
        for (int i = 0; i < indice; i++) {
            if (operadores[i]->getCi() == ci)
                return operadores[i];
        }
        return nullptr;
    }

    void agregar(Operador* operadorNuevo) {
        if (buscar(operadorNuevo->getCi()) != nullptr) {
            cout << "CI duplicado" << endl;
            delete operadorNuevo;
            return;
        }

        if (indice < tamanio) {
            operadores[indice++] = operadorNuevo;
        }
    }

    Operador* get(int i) {
        if (i >= 0 && i < indice) return operadores[i];
        return nullptr;
    }

    int size() { return indice; }
};
