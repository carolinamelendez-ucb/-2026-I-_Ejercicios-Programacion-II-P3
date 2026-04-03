#pragma once
#include "Producto.h"

class ProductoEnvasado : public Producto {

protected:
    float pesoKg;

public:

    ProductoEnvasado(const string& nombre, float precioBase, float pesoKg)
        : Producto(nombre, precioBase), pesoKg(pesoKg) {
    }

    float calcularPrecioFinal() override {
        return precioBase * 1.10 + (pesoKg * 2);
    }
};
