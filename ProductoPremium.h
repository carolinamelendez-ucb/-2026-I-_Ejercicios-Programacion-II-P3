#pragma once
#include <iostream>
#include <string>
#include "Productos.h"
using namespace std;

class ProductoPremium : public Producto {
private:
    float pesoKg;

public:
    ProductoPremium(string nombre, float precio, float pesoKg)
        : Producto(nombre, precio) {
        this->pesoKg = pesoKg;
    }

    float calcularPrecio() override {
        return (precioBase * 1.10 + (pesoKg * 2)) * 1.15;
    }
};