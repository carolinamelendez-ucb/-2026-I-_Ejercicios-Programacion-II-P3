#pragma once
#include "Producto.h"

class ProductoEnvasado : public Producto {
protected:
    float pesoEnKilogramos;

public:
    ProductoEnvasado(string nombre, float precio, float peso)
        : Producto(nombre, precio) {
        pesoEnKilogramos = peso;
    }

    float calcularPrecioFinal() override {
        return precioBase * 1.10 + (pesoEnKilogramos * 2);
    }
};