#pragma once
#include <iostream>
#include <string>
#include "Productos.h"
using namespace std;

class ProductoPromocional : public Producto {
private:
    float descuentoPromocional;
    int cantidad;

public:
    ProductoPromocional(string nombre, float precio, float descuentoPromocional, int cantidad)
        : Producto(nombre, precio) {
        this->descuentoPromocional = descuentoPromocional;
        this->cantidad = cantidad;
    }

    float calcularPrecio() override {
        return precioBase - descuentoPromocional - (cantidad > 5 ? (precioBase * 0.05) : 0);
    }
};