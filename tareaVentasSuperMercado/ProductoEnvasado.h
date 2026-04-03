#pragma once
#include <iostream>
#include <string>
#include "Producto.h"

using namespace std;

class ProductoEnvasado : public Producto {
private:
    float pesoKg;

public:
    ProductoEnvasado(int id, string nombre, float precioBase, float pesoKg)
        : Producto(id, nombre, precioBase) {
        this->pesoKg = pesoKg;
    }

    float calcularPrecioFinal() override {
        return precioBase * 1.10 + (pesoKg * 2);
    }

    virtual void mostrarInformacion() override {
        cout << "Producto Envasado - ID: " << id << ", Nombre: " << nombre
            << ", Precio Base: " << precioBase << ", Peso: " << pesoKg << " kg"
            << ", Precio Final: " << calcularPrecioFinal() << endl;
    }

    ~ProductoEnvasado() {
    }
};

