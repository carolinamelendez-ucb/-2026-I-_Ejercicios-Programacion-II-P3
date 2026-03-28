#pragma once
#include "Espectador.h"

class VectorEspectadores {

private:
    Espectador** espectadores;
    int indice;
    int tamanio;

public:

    VectorEspectadores(int tamanio) : tamanio(tamanio), indice(0) {
        espectadores = new Espectador * [tamanio];
    }

    ~VectorEspectadores() {
        for (int i = 0; i < indice; i++) {
            delete espectadores[i];
        }
        delete[] espectadores;
    }

    void agregar(Espectador* nuevoEspectador) {
        if (indice < tamanio) {
            espectadores[indice++] = nuevoEspectador;
        }
        else {
            cout << "Funcion llena" << endl;
        }
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            espectadores[i]->mostrar();
            cout << endl;
        }
    }

    int getCantidad() { return indice; }
};