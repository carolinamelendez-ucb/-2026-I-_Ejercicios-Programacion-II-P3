#pragma once
#include <iostream>
using namespace std;

class Producto {
protected:
    string nombreProducto;
    float precioBase;

public:
    Producto(string nombre, float precio) {
        nombreProducto = nombre;
        precioBase = precio;
    }

    string getNombreProducto() {
        return nombreProducto;
    }

    virtual float calcularPrecioFinal() = 0;

    virtual void mostrarInformacion() {
        cout << nombreProducto
            << " Precio final: "
            << calcularPrecioFinal() << endl;
            cout << endl;
    }

    virtual ~Producto() {}
};