#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pago
{
protected:
    float monto;

public:
    Pago(float monto)
    {
        this->monto = monto;
    }

    virtual float procesarPago() = 0;
    virtual void mostrar() = 0;

    virtual ~Pago() {}
};

class PagoPorcentual : public Pago
{
public:
    PagoPorcentual(float monto) : Pago(monto) {}

    float procesarPago()
    {
        return monto * 1.03;
    }

    void mostrar()
    {
        float comision = monto * 0.03;
        cout << "Monto original: " << monto << endl;
        cout << "Comision (3%): " << comision << endl;
        cout << "Total pagado: " << procesarPago() << endl;
    }
};

class PagoFijo : public Pago
{
public:
    PagoFijo(float monto) : Pago(monto) {}

    float procesarPago()
    {
        return monto + 5;
    }

    void mostrar()
    {
        cout << "Monto original: " << monto << endl;
        cout << "Comision fija: 5" << endl;
        cout << "Total pagado: " << procesarPago() << endl;
    }
};

class PagoValidado : public Pago
{
public:
    PagoValidado(float monto) : Pago(monto) {}

    float procesarPago()
    {
        if (monto <= 0)
        {
            return 0;
        }
        return monto;
    }

    void mostrar()
    {
        if (monto <= 0)
        {
            cout << "Error: monto invalido" << endl;
        }
        else
        {
            cout << "Monto original: " << monto << endl;
            cout << "Pago realizado correctamente" << endl;
            cout << "Total pagado: " << monto << endl;
        }
    }
};

class PagoDescuento : public Pago
{
public:
    PagoDescuento(float monto) : Pago(monto) {}

    float procesarPago()
    {
        return monto * 0.90;
    }

    void mostrar()
    {
        float descuento = monto * 0.10;
        cout << "Monto original: " << monto << endl;
        cout << "Descuento (10%): " << descuento << endl;
        cout << "Total pagado: " << procesarPago() << endl;
    }
};