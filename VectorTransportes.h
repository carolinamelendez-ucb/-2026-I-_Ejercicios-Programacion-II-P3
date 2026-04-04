#pragma once
#include "Transporte.h"

class VectorTransportes {

private:
    Transporte** transportes;
    int indice;
    int tamanio;

public:

    VectorTransportes(int tamanio) : tamanio(tamanio), indice(0) {
        transportes = new Transporte * [tamanio];
    }

    ~VectorTransportes() {
        for (int i = 0; i < indice; i++) delete transportes[i];
        delete[] transportes;
    }

    Transporte* buscar(string placa) {
        for (int i = 0; i < indice; i++) {
            if (transportes[i]->getPlaca() == placa)
                return transportes[i];
        }
        return nullptr;
    }

    void agregar(Transporte* transporteNuevo) {
        if (buscar(transporteNuevo->getPlaca()) != nullptr) {
            cout << "Placa duplicada" << endl;
            delete transporteNuevo;
            return;
        }

        if (indice < tamanio) {
            transportes[indice++] = transporteNuevo;
        }
    }

    Transporte* get(int i) {
        if (i >= 0 && i < indice) return transportes[i];
        return nullptr;
    }
};