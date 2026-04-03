#pragma once
#include <iostream>
#include <string>

using namespace std;

class Producto {

protected:
    string nombre;
    float precioBase;

public:

    Producto(const string& nombre, float precioBase)
        : nombre(nombre), precioBase(precioBase) {
    }

    string getNombre() { return nombre; }

    virtual float calcularPrecioFinal() = 0;

    virtual void mostrar() {
        cout << "Producto: " << nombre << endl;
        cout << "Precio final: " << calcularPrecioFinal() << endl;
    }
};
