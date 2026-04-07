#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;

class VectorPagos
{
private:
    Pago** pagos;
    int tamanio;
    int indice;

public:
    VectorPagos(int tamanio)
    {
        this->tamanio = tamanio;
        indice = 0;
        pagos = new Pago * [tamanio];
    }

    void agregar(Pago* p)
    {
        if (indice < tamanio)
        {
            pagos[indice++] = p;
        }
    }

    void mostrarPagos()
    {
        for (int i = 0; i < indice; i++)
        {
            cout << "Pago " << i + 1 << ":" << endl;
            pagos[i]->mostrar();
            cout << endl;
        }
    }

    float totalPagos()
    {
        float suma = 0;
        for (int i = 0; i < indice; i++)
        {
            suma += pagos[i]->procesarPago();
        }
        return suma;
    }
};