#pragma once
#include <iostream>
#include <string>
#include "ListaProductos.h"

using namespace std;

class Supermercado {
private:
    string nombre;
    string ubicacion;
    ListaProductos* lista;

public:
    Supermercado(const string& nombre, const string& ubicacion, int tamanioMax) {
        this->nombre = nombre;
        this->ubicacion = ubicacion;
        this->lista = new ListaProductos(tamanioMax);
    }

    string getNombre() {
        return nombre;
    }

    string getUbicacion() {
        return ubicacion;
    }

    void agregarProducto(Producto* nuevoProducto) {
        lista->agregar(nuevoProducto);
    }

    void mostrarProductosEnRango(float precioMin, float precioMax) {
        cout << "Supermercado: " << nombre << " (" << ubicacion << ")" << endl;
        lista->mostrarProductosPorRango(precioMin, precioMax);
    }

    float getPrecioPromedio() {
        return lista->calcularPrecioPromedio();
    }

    bool tieneMayorPrecioPromedioQue(Supermercado* otroSupermercado) {
        return this->getPrecioPromedio() > otroSupermercado->getPrecioPromedio();
    }

    void mostrarDatos() {
        cout << "Supermercado: " << nombre << ", Ubicacion: " << ubicacion
            << ", Precio Promedio: " << getPrecioPromedio() << endl;
    }

    ~Supermercado() {
        delete lista;
    }
};