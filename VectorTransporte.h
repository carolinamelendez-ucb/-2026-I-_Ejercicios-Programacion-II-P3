#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"
using namespace std;

class VectorTransportes
{
private:
    Transporte** lista;
    int tamanio;
    int indice;

public:
    VectorTransportes(int tamanio)
    {
        this->tamanio = tamanio;
        indice = 0;
        lista = new Transporte * [tamanio];
    }

    bool existePlaca(string placa)
    {
        for (int i = 0; i < indice; i++)
        {
            if (lista[i]->getPlaca() == placa)
                return true;
        }
        return false;
    }

    void agregar(Transporte* t)
    {
        if (!existePlaca(t->getPlaca()))
        {
            lista[indice++] = t;
        }
        else
        {
            cout << "Placa duplicada" << endl;
        }
    }

    Transporte* get(int i)
    {
        return lista[i];
    }
};