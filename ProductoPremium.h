#pragma once
#include "ProductoEnvasado.h"

class ProductoPremium : public ProductoEnvasado {
public:
    ProductoPremium(string nombre, float precio, float peso)
        : ProductoEnvasado(nombre, precio, peso) {
    }

    float calcularPrecioFinal() override {
        float precio = ProductoEnvasado::calcularPrecioFinal();
        return precio * 1.15;
    }
};