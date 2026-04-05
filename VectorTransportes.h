#pragma once
#include "Transporte.h"

class VectorTransportes {
private:
    Transporte** transportes;
    int indice;
    int tamanio;

public:
    VectorTransportes(int tamanio) {
        tamanio = tamanio;
        indice = 0;
        transportes = new Transporte * [tamanio];
    }

    bool agregar(Transporte* transporte) {
        for (int i = 0; i < indice; i++) {
            if (transportes[i]->getPlaca() == transporte->getPlaca())
                return false;
        }

        transportes[indice++] = transporte;
        return true;
    }

    Transporte* buscar(string placa) {
        for (int i = 0; i < indice; i++) {
            if (transportes[i]->getPlaca() == placa)
                return transportes[i];
        }
        return nullptr;
    }
};