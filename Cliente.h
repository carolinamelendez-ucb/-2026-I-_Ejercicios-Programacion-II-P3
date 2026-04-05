#pragma once
#include <iostream>
#include<string>
#include"pagos.h"
using namespace std;
class Cliente {
private:
    string nombre;
    float monto;
    MetodoPago* metodo;
public:
    Cliente(string nombre, float monto) {
        this->nombre = nombre;
        this->monto = monto;
        this->metodo = nullptr;
    }
    void setMetodo(MetodoPago* m) {
        metodo = m;
    }
    float totalPagar() {
        if (metodo != nullptr) {
            return metodo->calcularPago(monto);
        }
        return monto;
    }
    void mostrar() {
        cout << "Cliente: " << nombre << endl;
        cout << "Monto base: " << monto << endl;

        if (metodo != nullptr) {
            metodo->mostrar();
            cout << "Total a pagar: " << totalPagar() << endl;
        }
        else {
            cout << "Sin metodo de pago" << endl;
        }

        cout << "------------------" << endl;
    }
};
class VectorClientes {
private:
    Cliente** lista;
    int cantidad;
    int tamanio;

public:
    VectorClientes(int t) {
        tamanio = t;
        cantidad = 0;
        lista = new Cliente * [t];
    }

    void agregar(Cliente* c) {
        if (cantidad < tamanio) {
            lista[cantidad] = c;
            cantidad++;
        }
    }

    void mostrar() {
        for (int i = 0; i < cantidad; i++) {
            lista[i]->mostrar();
        }
    }
};
