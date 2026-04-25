#pragma once
#include "Asiento.h"
#include "CapacidadAsientosException.h"

class VectorAsientos {
private:
    int indice;
    int tamanio;
    Asiento** asientos;
public:
    VectorAsientos(int tamanio) {
        this->indice = 0;
        this->tamanio = tamanio;
        asientos = new Asiento * [tamanio];
    }

    void agregar(Asiento* a) {
        if (indice >= tamanio) {
            throw CapacidadAsientosException();
        }
        asientos[indice++] = a;
    }

    Asiento* buscar(string codigo) {
        for (int i = 0; i < indice; i++) {
            if (asientos[i]->getCodigo() == codigo) {
                return asientos[i];
            }
        }
        return nullptr;
    }

    int contarDisponibles() {
        int c = 0;
        for (int i = 0; i < indice; i++) {
            if (!asientos[i]->getEstado()) c++;
        }
        return c;
    }

    int contarOcupados() {
        int c = 0;
        for (int i = 0; i < indice; i++) {
            if (asientos[i]->getEstado()) c++;
        }
        return c;
    }

    ~VectorAsientos() {
        for (int i = 0; i < indice; i++) {
            delete asientos[i];
        }
        delete[] asientos;
    }
};
