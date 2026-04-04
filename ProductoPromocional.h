#pragma once
#include "Producto.h"

class ProductoPromocional : public Producto {
private:
    float descuentoFijo;
    int cantidadComprada;

public:
    ProductoPromocional(string nombre, float precio, float descuento, int cantidad)
        : Producto(nombre, precio) {
        descuentoFijo = descuento;
        cantidadComprada = cantidad;
    }

    float calcularPrecioFinal() override {
        float precio = precioBase - descuentoFijo;

        if (cantidadComprada > 5)
            precio -= precioBase * 0.05;

        return precio;
    }
};