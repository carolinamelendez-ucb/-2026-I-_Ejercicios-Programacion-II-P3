#pragma once
#include "ListaProductos.h"

class Supermercado {
private:
    string nombreSupermercado;
    string ubicacionGeografica;
    ListaProductos* listaProductos;

public:
    Supermercado(string nombre, string ubicacion) {
        nombreSupermercado = nombre;
        ubicacionGeografica = ubicacion;
        listaProductos = new ListaProductos(20);
    }

    void agregarProducto(Producto* producto) {
        listaProductos->agregarProducto(producto);
    }

    bool tieneMayorPrecioPromedioQue(Supermercado* otro) {
        return listaProductos->calcularPromedioPrecios() >
            otro->listaProductos->calcularPromedioPrecios();
    }

    void mostrarDatos() {
        cout << "Supermercado: " << nombreSupermercado
            << " Ubicacion: " << ubicacionGeografica << endl;
        cout << endl;

        listaProductos->mostrarTodos();
    }

    void mostrarProductosEnRango(float min, float max) {
        listaProductos->mostrarProductosEnRango(min, max);
    }
};