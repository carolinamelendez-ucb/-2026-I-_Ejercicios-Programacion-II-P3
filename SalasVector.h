#pragma once
#include "Sala.h"

class SalasVector {

private:
    Sala** salas;
    int indice;
    int tamanio;

public:

    SalasVector(int tamanio)
        : tamanio(tamanio), indice(0)
    {
        salas = new Sala * [tamanio];
    }

    ~SalasVector() {
        for (int i = 0; i < indice; i++) {
            delete salas[i];
        }
        delete[] salas;
    }

    void agregar(Sala* sala) {
        if (indice < tamanio) {
            salas[indice] = sala;
            indice++;
        }
    }

    Sala* getSala(int pos) {
        return salas[pos];
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            salas[i]->mostrar();
            cout << endl;
        }
    }
};