#pragma once
#include <string>
#include <iostream>
using namespace std;

class Pago {
protected:
    float monto;

public:
    Pago(float m) {
        monto = m;
    }

    float getMonto() {
        return monto;
    }

    virtual float procesarPago() = 0;
    virtual void mostrar() = 0;

    virtual ~Pago() {}
};


class PagoPorcentual : public Pago {
public:
    PagoPorcentual(float m) : Pago(m) {}

    float procesarPago() {
        return monto * 1.03f;
    }

    void mostrar() {
        float comision = monto * 0.03;
        cout << "Pago Porcentual";
        cout << "Monto: " << monto << endl;
        cout << "Comision: " << comision << endl;
        cout << "Total: " << monto + comision << endl;
    }
};


class PagoFijo : public Pago {
public:
    PagoFijo(float m) : Pago(m) {}

    float procesarPago() {
        return monto + 5;
    }

    void mostrar() {
        cout << "Pago Fijo";
        cout << "Monto: " << monto << endl;
        cout << "Comision: 5";
        cout << "Total: " << monto + 5 << endl;
    }
};

class PagoValidado : public Pago {
public:
    PagoValidado(float m) : Pago(m) {}

    float procesarPago() {
        if (monto <= 0) return 0;
        return monto;
    }

    void mostrar() {
        if (monto <= 0) {
            cout << "Error: monto invalido";
        }
        else {
            cout << "Pago Validado";
            cout << "Monto: " << monto << endl;
            cout << "Pago realizado correctamente";
        }
    }
};
class PagoDescuento : public Pago {
public:
    PagoDescuento(float m) : Pago(m) {}

    float procesarPago() {
        return monto * 0.9;
    }

    void mostrar() {
        float desc = monto * 0.10;
        cout << "Pago con Descuento";
        cout << "Monto: " << monto << endl;
        cout << "Descuento: " << desc << endl;
        cout << "Total: " << monto - desc << endl;
    }
};