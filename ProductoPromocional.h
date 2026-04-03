#pragma once
#include "Producto.h"

class ProductoPromocional : public Producto {

private:
    float descuentoPromocional;
    int cantidad;

public:

    ProductoPromocional(const string& nombre, float precioBase, float descuento, int cantidad)
        : Producto(nombre, precioBase), descuentoPromocional(descuento), cantidad(cantidad) {
    }

    float calcularPrecioFinal() override {
        float extra = (cantidad > 5) ? (precioBase * 0.05f) : 0;
        return precioBase - descuentoPromocional - extra;
    }
};