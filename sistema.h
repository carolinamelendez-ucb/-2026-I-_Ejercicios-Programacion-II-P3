#pragma once
#pragma once
#include "Cliente.h"

class Sistema {
private:
    Cliente** clientes;
    int cantidad;
    int capacidad;

public:
    Sistema() {
        capacidad = 5;
        cantidad = 0;
        clientes = new Cliente * [capacidad];
    }

    void agregarCliente(Cliente* c) {
        if (cantidad < capacidad) {
            clientes[cantidad] = c;
            cantidad++;
        }
    }

    float totalGeneral() {
        float total = 0;

        for (int i = 0; i < cantidad; i++) {
            total += clientes[i]->totalPagos();
        }

        return total;
    }

    void mostrarSistema() {
        for (int i = 0; i < cantidad; i++) {
            clientes[i]->mostrarPagos();
        }

        cout << "TOTAL GENERAL: " << totalGeneral() << endl;
    }
};