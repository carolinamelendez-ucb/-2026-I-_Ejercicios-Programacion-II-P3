#pragma once
#include <iostream>
#include <string>
#include "Transaccion.h"

using namespace std;

class Cliente {
public:
    string nombre;
    Transaccion** transacciones;
    int cantidadTransacciones;
    int tamanioMax;

public:
    Cliente(const string& nombre, int maxTransacciones)
        : nombre(nombre), cantidadTransacciones(0), tamanioMax(maxTransacciones) {
        transacciones = new Transaccion * [maxTransacciones];
    }

    void agregarTransaccion(float monto, MetodoPago* metodoPago) {
        if (cantidadTransacciones < tamanioMax) {
            transacciones[cantidadTransacciones] = new Transaccion(monto, metodoPago);
            cantidadTransacciones++;
        }
        else {
            cout << "Error: No se pueden agregar mas transacciones a " << nombre << endl;
        }
    }

    void procesarTodasLasTransacciones() {
        for (int i = 0; i < cantidadTransacciones; i++) {
            transacciones[i]->procesar();
        }
    }

    void mostrarTransacciones() {
        cout << "Cliente: " << nombre << endl;
        cout << "---" << endl;
        for (int i = 0; i < cantidadTransacciones; i++) {
            cout << "Pago " << i + 1 << ":" << endl;
            transacciones[i]->mostrarDetalle();
            cout << endl;
        }
    }

    float calcularTotalCliente() {
        float total = 0;
        for (int i = 0; i < cantidadTransacciones; i++) {
            total += transacciones[i]->totalPagado;
        }
        return total;
    }

    ~Cliente() {
        for (int i = 0; i < cantidadTransacciones; i++) {
            delete transacciones[i];
        }
        delete[] transacciones;
    }
};