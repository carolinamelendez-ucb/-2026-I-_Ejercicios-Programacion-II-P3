#pragma once
#include <iostream>
#include <string>
#include "VectorTransporte.h"
#include "VectorOperador.h"
using namespace std;

class Sistema
{
private:
    VectorTransportes* transportes;
    VectorOperadores* operadores;

public:
    Sistema()
    {
        transportes = new VectorTransportes(10);
        operadores = new VectorOperadores(10);
    }

    void agregarTransporte(Transporte* t)
    {
        transportes->agregar(t);
    }

    void agregarOperador(Operador* o)
    {
        operadores->agregar(o);
    }

    void asociar(int indexOperador, int indexTransporte)
    {
        operadores->get(indexOperador)->asignarTransporte(
            transportes->get(indexTransporte));
    }

    float costoTotal()
    {
        float suma = 0;
        for (int i = 0; i < operadores->getIndice(); i++)
        {
            suma += operadores->get(i)->calcularCosto();
        }
        return suma;
    }

    void menorCosto()
    {
        float menor = 999999;
        int pos = -1;

        for (int i = 0; i < operadores->getIndice(); i++)
        {
            float c = operadores->get(i)->calcularCosto();
            if (c < menor)
            {
                menor = c;
                pos = i;
            }
        }

        if (pos != -1)
        {
            cout << "Operador con menor costo:" << endl;
            operadores->get(pos)->mostrar();
        }
    }
};