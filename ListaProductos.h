#pragma once
#include "Producto.h"

class ListaProductos {
private:
    Producto** arregloProductos;
    int cantidadActualProductos;
    int capacidadMaxima;

public:
    ListaProductos(int capacidad) {
        capacidadMaxima = capacidad;
        cantidadActualProductos = 0;
        arregloProductos = new Producto * [capacidad];
    }

    void agregarProducto(Producto* producto) {
        if (cantidadActualProductos < capacidadMaxima) {
            arregloProductos[cantidadActualProductos++] = producto;
        }
    }

    void mostrarProductosEnRango(float minimo, float maximo) {
        cout << "Productos en rango...............";

        for (int i = 0; i < cantidadActualProductos; i++) {
            float precio = arregloProductos[i]->calcularPrecioFinal();

            if (precio >= minimo && precio <= maximo) {
                arregloProductos[i]->mostrarInformacion();
            }
        }
    }

    float calcularPromedioPrecios() {
        if (cantidadActualProductos == 0) return 0;

        float suma = 0;
        for (int i = 0; i < cantidadActualProductos; i++) {
            suma += arregloProductos[i]->calcularPrecioFinal();
        }

        return suma / cantidadActualProductos;
    }

    void mostrarTodos() {
        for (int i = 0; i < cantidadActualProductos; i++) {
            arregloProductos[i]->mostrarInformacion();
        }
    }
};