#pragma once
#include <iostream>
#include <string>
#include "Producto.h"

using namespace std;

class ProductoPremium : public Producto {
private:
    float pesoKg;

public:
    ProductoPremium(int id, string nombre, float precioBase, float pesoKg)
        : Producto(id, nombre, precioBase) {
        this->pesoKg = pesoKg;
    }

    float calcularPrecioFinal() override {
        float precioConImpuesto = precioBase * 1.10 + (pesoKg * 2);
        return precioConImpuesto * 1.15;
    }

    virtual void mostrarInformacion() override {
        cout << "Producto Premium - ID: " << id << ", Nombre: " << nombre
            << ", Precio Base: " << precioBase << ", Peso: " << pesoKg << " kg"
            << ", Precio Final: " << calcularPrecioFinal() << endl;
    }

    ~ProductoPremium() {
    }
};