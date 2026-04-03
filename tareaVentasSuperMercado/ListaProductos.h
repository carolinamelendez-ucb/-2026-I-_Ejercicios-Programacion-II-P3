#pragma once
#include <iostream>
#include <string>
#include "Producto.h"

using namespace std;

class ListaProductos {
private:
    Producto** productos;
    int tamanio;
    int cantidad;

public:
    ListaProductos(int tamanioMax) {
        this->productos = new Producto * [tamanioMax];
        this->tamanio = tamanioMax;
        this->cantidad = 0;
    }

    void agregar(Producto* nuevoProducto) {
        if (cantidad < tamanio) {
            productos[cantidad] = nuevoProducto;
            cantidad++;
        }
        else {
            cout << "Error: La lista esta llena" << endl;
        }
    }

    void mostrarProductosPorRango(float precioMin, float precioMax) {
        for (int i = 0; i < cantidad; i++) {
            float precioFinal = productos[i]->calcularPrecioFinal();
            if (precioFinal >= precioMin && precioFinal <= precioMax) {
                cout << "Nombre: " << productos[i]->getNombre()
                    << " - Precio Final: " << precioFinal << endl;
            }
        }
    }

    void mostrarTodosLosProductos() {
        for (int i = 0; i < cantidad; i++) {
            productos[i]->mostrarInformacion();
        }
    }

    float calcularPrecioPromedio() {
        if (cantidad == 0) return 0;
        float suma = 0;
        for (int i = 0; i < cantidad; i++) {
            suma += productos[i]->calcularPrecioFinal();
        }
        return suma / cantidad;
    }

    int getCantidad() {
        return cantidad;
    }

    ~ListaProductos() {
        for (int i = 0; i < cantidad; i++) {
            delete productos[i];
        }
        delete[] productos;
    }
};