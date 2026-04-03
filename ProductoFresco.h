#pragma once
#include "Producto.h"
#include <algorithm>

class ProductoFresco : public Producto {

private:
    int diasRestantes;

public:

    ProductoFresco(const string& nombre, float precioBase, int diasRestantes)
        : Producto(nombre, precioBase), diasRestantes(diasRestantes) {
    }

    float calcularPrecioFinal() override {
        float descuento = min(0.05f * (7 - diasRestantes), 0.3f);
        if (descuento < 0) descuento = 0;
        return precioBase * (1 - descuento);
    }
};
