#pragma once
#include <iostream>
#include <string>
#include "Producto.h"

using namespace std;

class ProductoPromocional : public Producto {
private:
    float descuentoPromocional;
    int cantidad;

public:
    ProductoPromocional(int id, string nombre, float precioBase, float descuentoPromocional, int cantidad)
        : Producto(id, nombre, precioBase) {
        this->descuentoPromocional = descuentoPromocional;
        this->cantidad = cantidad;
    }

    float calcularPrecioFinal() override {
        float descuentoAdicional = 0;
        if (cantidad > 5) {
            descuentoAdicional = precioBase * 0.05;
        }
        return precioBase - descuentoPromocional - descuentoAdicional;
    }

    virtual void mostrarInformacion() override {
        cout << "Producto Promocional - ID: " << id << ", Nombre: " << nombre
            << ", Precio Base: " << precioBase << ", Descuento Promo: " << descuentoPromocional
            << ", Cantidad: " << cantidad << ", Precio Final: " << calcularPrecioFinal() << endl;
    }

    ~ProductoPromocional() {
    }
};