#pragma once
#include "Pasajero.h"

class VectorPasajeros {
private:
    int indice;
    int tamanio;
    Pasajero** pasajeros;
public:
    VectorPasajeros(int tamanio) {
        this->indice = 0;
        this->tamanio = tamanio;
        pasajeros = new Pasajero * [tamanio];
    }

    void agregar(Pasajero* p) {
        pasajeros[indice++] = p;
    }

    Pasajero* buscar(int ci) {
        for (int i = 0; i < indice; i++) {
            if (pasajeros[i]->getCi() == ci) {
                return pasajeros[i];
            }
        }
        return nullptr;
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            pasajeros[i]->mostrar();
        }
    }

    ~VectorPasajeros() {
        for (int i = 0; i < indice; i++) {
            delete pasajeros[i];
        }
        delete[] pasajeros;
    }
};