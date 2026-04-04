#pragma once
#include "Cliente.h"

class VectorClientes {

private:
    Cliente** clientes;
    int indice;
    int tamanio;

public:

    VectorClientes(int tamanio) : tamanio(tamanio), indice(0) {
        clientes = new Cliente * [tamanio];
    }

    ~VectorClientes() {
        for (int i = 0; i < indice; i++) delete clientes[i];
        delete[] clientes;
    }

    void agregar(Cliente* clienteNuevo) {
        if (indice < tamanio) {
            clientes[indice++] = clienteNuevo;
        }
    }

    float totalGeneral() {
        float total = 0;
        for (int i = 0; i < indice; i++) {
            total += clientes[i]->procesarPagos();
        }
        return total;
    }

    void mostrar() {
        for (int i = 0; i < indice; i++) {
            clientes[i]->mostrar();
        }
    }
};
