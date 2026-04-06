
#include "PagosDerivados.h"
#pragma once

class Cliente {
private:
    string nombre;
    Pago** pagos;
    int cantidad;
    int capacidad;

public:
    Cliente(string n) {
        nombre = n;
        capacidad = 5;
        cantidad = 0;
        pagos = new Pago * [capacidad];
    }

    void agregarPago(Pago* p) {

        if (cantidad < capacidad) {
            pagos[cantidad] = p;
            cantidad++;
        }
    }

    float totalPagos() {
        float suma = 0;

        for (int i = 0; i < cantidad; i++) {
            suma += pagos[i]->procesarPago();
        }

        return suma;
    }

    void mostrarPagos() {
        cout << "Cliente: " << nombre << endl;

        for (int i = 0; i < cantidad; i++) {
            pagos[i]->mostrar();
        }

        cout << "Total cliente: " << totalPagos() << endl;
        cout << endl;
    }
};

