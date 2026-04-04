#pragma once
#include <iostream>
#include <string>

#include "Productos.h"


class ProductoEnvasado : public Producto{
private:
	float pesoKg;
public:
    ProductoEnvasado(string nombre, float precio, float pesoKg)
        :Producto(nombre, precio) {
        this->pesoKg = pesoKg;
    }

    float calcularPrecio() override {
        return precioBase * 1.10 + (pesoKg * 2);
    }
};