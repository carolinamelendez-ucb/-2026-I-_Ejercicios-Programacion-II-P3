#pragma once
#include <iostream>
#include "Invitado.h"

using namespace std;

class InvitadosVector {

private:
    Invitado** invitados;
    int indice;
    int tamanio;

public:
    InvitadosVector(int tamanio)
        : tamanio(tamanio), indice(0)
    {
        invitados = new Invitado * [tamanio];
    }

    ~InvitadosVector() {
        for (int i = 0; i < indice; i++) {
            delete invitados[i];
        }
        delete[] invitados;
    }

    void agregar(Invitado* invitado) {
        if (indice < tamanio) {

            invitados[indice] = invitado;
            indice++;
        }
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            invitados[i]->mostrar();
            cout << endl;
        }
    }
};
