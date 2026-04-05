#pragma once
#include <iostream>
#include<string>
using namespace std;
class MetodoPago {
public:
    virtual float calcularPago(float monto) = 0;
    virtual void mostrar() = 0;
};
class PagoEfectivo : public MetodoPago {
public:
    float calcularPago(float monto) {
        return monto;
    }
    void mostrar() {
        cout << "Pago en efectivo" << endl;
    }
};
class PagoTarjeta : public MetodoPago {
public:
    float calcularPago(float monto) {
        return monto * 1.05;
    }
    void mostrar() {
        cout << "Pago con tarjeta (5% recargo)" << endl;
    }
};
class PagoQR : public MetodoPago {
public:
    float calcularPago(float monto) {
        return monto * 0.9;
    }
    void mostrar() {
        cout << "Pago por QR (10% descuento)" << endl;
    }
};