#pragma once
#include "Asiento.h"

class VectorAsientos {
private:
    Asiento** array;
    int indice;
    int tamanio;

public:
    VectorAsientos(int tamanio) {
        this->tamanio = tamanio;
        indice = 0;
        array = new Asiento * [tamanio];
    }

    void agregar(Asiento* a) {
        if (indice >= tamanio)
            throw MiExcepcion("Capacidad de asientos superada");

        // evitar duplicados
        for (int i = 0; i < indice; i++) {
            if (array[i]->getCodigo() == a->getCodigo())
                throw MiExcepcion("Asiento duplicado");
        }

        array[indice++] = a;
    }

    Asiento* buscar(string cod) {
        for (int i = 0; i < indice; i++) {
            if (array[i]->getCodigo() == cod)
                return array[i];
        }
        return nullptr;
    }

    int disponibles() {
        int c = 0;
        for (int i = 0; i < indice; i++)
            if (array[i]->estaDisponible()) c++;
        return c;
    }

    int ocupados() {
        return indice - disponibles();
    }
};