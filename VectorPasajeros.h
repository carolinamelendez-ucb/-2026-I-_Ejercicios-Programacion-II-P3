#pragma once
#include <iostream>
#include <string>
#include "Pasajero.h"
#include "myException.h"
using namespace std;

class VectorPasajeros {
private:
    Pasajero** array;
    int indice;
    int tamanio;

public:
    VectorPasajeros(int tamanio) {
        this->tamanio = tamanio;
        this->indice = 0;
        array = new Pasajero * [tamanio];
    }

    void agregar(Pasajero* p) {
        for (int i = 0; i < indice; i++) {
            if (array[i]->getCI() == p->getCI())
                throw MiExcepcion("CI duplicado");
        }

        if (indice >= tamanio)
            throw MiExcepcion("Capacidad de pasajeros llena");

        array[indice++] = p;
    }

    Pasajero* buscar(string ci) {
        for (int i = 0; i < indice; i++) {
            if (array[i]->getCI() == ci)
                return array[i];
        }
        return nullptr;
    }

    void mostrar() {
        for (int i = 0; i < indice; i++)
            array[i]->mostrar();
    }
};