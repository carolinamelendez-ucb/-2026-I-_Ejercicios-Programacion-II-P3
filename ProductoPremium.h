#pragma once
#include "ProductoEnvasado.h"

class ProductoPremium : public ProductoEnvasado {

public:

    ProductoPremium(const string& nombre, float precioBase, float pesoKg)
        : ProductoEnvasado(nombre, precioBase, pesoKg) {
    }

    float calcularPrecioFinal() override {
        float base = ProductoEnvasado::calcularPrecioFinal();
        return base * 1.15;
    }
};
