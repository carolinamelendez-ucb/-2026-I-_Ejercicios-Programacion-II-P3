#pragma once
#include "Producto.h"

class ListaProductos {

private:
    Producto** productos;
    int indice;
    int tamanio;

public:

    ListaProductos(int tamanio) : tamanio(tamanio), indice(0) {
        productos = new Producto * [tamanio];
    }

    ~ListaProductos() {
        for (int i = 0; i < indice; i++) delete productos[i];
        delete[] productos;
    }

    void agregar(Producto* nuevoProducto) {
        if (indice < tamanio) {
            productos[indice++] = nuevoProducto;
        }
    }

    void mostrarEnRango(float min, float max) {
        for (int i = 0; i < indice; i++) {
            float precio = productos[i]->calcularPrecioFinal();
            if (precio >= min && precio <= max) {
                cout << productos[i]->getNombre() << " - " << precio << endl;
            }
        }
    }

    float promedioPrecios() {
        if (indice == 0) return 0;

        float suma = 0;
        for (int i = 0; i < indice; i++) {
            suma += productos[i]->calcularPrecioFinal();
        }
        return suma / indice;
    }
};
