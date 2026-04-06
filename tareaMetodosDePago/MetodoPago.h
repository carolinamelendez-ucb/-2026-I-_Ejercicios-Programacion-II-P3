#pragma once
#include <iostream>
#include <string>

using namespace std;

class MetodoPago {
public:
    virtual float procesarPago(float monto) = 0;
    virtual void mostrarDetalle(float monto) = 0;
    virtual bool esValido(float monto) = 0;
    virtual ~MetodoPago() {
    }
};