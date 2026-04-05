#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"
using namespace std;

class Operador
{
private:
    string nombre;
    int ci;
    float distancia;
    Transporte* transporte;

public:
    Operador(string nombre, int ci, float distancia)
    {
        this->nombre = nombre;
        this->ci = ci;
        this->distancia = distancia;
        transporte = nullptr;
    }

    int getCI()
    {
        return ci;
    }

    void asignarTransporte(Transporte* t)
    {
        transporte = t;
    }

    float calcularCosto()
    {
        if (transporte != nullptr)
        {
            return transporte->calcularCosto(distancia);
        }
        return 0;
    }

    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "CI: " << ci << endl;
        cout << "Distancia: " << distancia << endl;
        if (transporte != nullptr)
        {
            transporte->mostrar();
            cout << "Costo: " << calcularCosto() << endl;
        }
    }
};