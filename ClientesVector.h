#pragma once
#include "Cliente.h"

class ClientesVector {

private:
    Cliente** clientes;
    int indice;
    int tamanio;

public:

    ClientesVector(int tamanio)
        : tamanio(tamanio), indice(0)
    {
        clientes = new Cliente * [tamanio];
    }

    ~ClientesVector() {
        for (int i = 0; i < indice; i++) {
            delete clientes[i];
        }
        delete[] clientes;
    }

    void agregar(Cliente* cliente) {
        if (indice < tamanio) {
            clientes[indice] = cliente;
            indice++;
        }
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            clientes[i]->mostrar();
            cout << endl;
        }
    }
};
