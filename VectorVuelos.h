#pragma once
#include "Vuelo.h"

class VectorVuelos {
private:
    Vuelo** array;
    int indice;
    int tamanio;

public:
    VectorVuelos(int t) {
        tamanio = t;
        indice = 0;
        array = new Vuelo * [t];
    }

    void agregar(Vuelo* v) {
        if (indice >= tamanio)
            throw MiExcepcion("Capacidad de vuelos llena");

        array[indice++] = v;
    }

    Vuelo* buscar(string cod) {
        for (int i = 0; i < indice; i++) {
            if (array[i]->getCodigo() == cod)
                return array[i];
        }
        return nullptr;
    }
};