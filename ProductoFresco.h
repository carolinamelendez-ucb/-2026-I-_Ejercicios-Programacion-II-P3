#pragma once
#include "Producto.h"

class ProductoFresco : public Producto {
private:
    int diasRestantesParaVencimiento;

public:
    ProductoFresco(string nombre, float precio, int dias)
        : Producto(nombre, precio) {
        diasRestantesParaVencimiento = dias;
    }

    float calcularPrecioFinal() override {
        float descuento = 0.05 * (7 - diasRestantesParaVencimiento);
        if (descuento > 0.3) descuento = 0.3;

        return precioBase * (1 - descuento);
    }
};