#pragma once
#include <iostream>
using namespace std;

class Pago {

protected:
    float monto;

public:

    Pago(float monto) : monto(monto) {}

    virtual float procesar() = 0;

    virtual void mostrar() = 0;
};
