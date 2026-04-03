#pragma once
#include <iostream>
#include <string>
#include "Producto.h"

using namespace std;

class ProductoFresco : public Producto {
private:
    int diasRestantes;

public:
    ProductoFresco(int id, string nombre, float precioBase, int diasRestantes)
        : Producto(id, nombre, precioBase) {
        this->diasRestantes = diasRestantes;
    }

    float calcularPrecioFinal() override {
        float descuento = 0.05 * (7 - diasRestantes);

        if (descuento > 0.3) {
            descuento = 0.3;
        }
        if (descuento < 0) {
            descuento = 0;
        }

        return precioBase * (1 - descuento);
    }

    virtual void mostrarInformacion() override {
        cout << "Producto Fresco - ID: " << id << ", Nombre: " << nombre
            << ", Precio Base: " << precioBase << ", Dias Restantes: " << diasRestantes
            << ", Precio Final: " << calcularPrecioFinal() << endl;
    }

    ~ProductoFresco() {
    }
};