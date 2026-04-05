#pragma once
#include <iostream>
#include <string>
using namespace std;

class Transporte
{
protected:
    string placa;

public:
    Transporte(string placa)
    {
        this->placa = placa;
    }

    string getPlaca()
    {
        return placa;
    }

    virtual float calcularCosto(float distancia) = 0;

    virtual void mostrar()
    {
        cout << "Placa: " << placa << endl;
    }

    virtual ~Transporte() {}
};

class Terrestre : public Transporte
{
public:
    Terrestre(string placa) : Transporte(placa) {}

    float calcularCosto(float d)
    {
        float costo = d * 0.5;
        if (d > 100)
        {
            costo = costo * 1.10;
        }
        return costo;
    }
};

class Aereo : public Transporte
{
public:
    Aereo(string placa) : Transporte(placa) {}

    float calcularCosto(float d)
    {
        float costo = d * 2.0;
        if (d > 1000)
        {
            costo = costo * 0.85;
        }
        return costo;
    }
};

class Maritimo : public Transporte
{
public:
    Maritimo(string placa) : Transporte(placa) {}

    float calcularCosto(float d)
    {
        float costo = d * 1.2;
        if (d > 500)
        {
            costo += 50;
        }
        return costo;
    }
};