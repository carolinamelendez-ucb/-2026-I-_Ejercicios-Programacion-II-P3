#pragma once
#include <iostream>
#include <string>

using namespace std;

class Producto {
protected:
    int id;
    string nombre;
    float precioBase;

public:
    Producto(int id, const string& nombre, float precioBase)
        : id(id), nombre(nombre), precioBase(precioBase) {
    }

    int getId() {
        return id;
    }

    string getNombre() {
        return nombre;
    }

    float getPrecioBase() {
        return precioBase;
    }

    virtual float calcularPrecioFinal() = 0;
    virtual void mostrarInformacion() = 0;

    virtual ~Producto() {
    }
};