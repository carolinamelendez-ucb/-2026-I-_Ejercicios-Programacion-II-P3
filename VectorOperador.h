#pragma once
#include <iostream>
#include <string>
#include "Operador.h"
using namespace std;

class VectorOperadores
{
private:
    Operador** lista;
    int tamanio;
    int indice;

public:
    VectorOperadores(int tamanio)
    {
        this->tamanio = tamanio;
        indice = 0;
        lista = new Operador * [tamanio];
    }

    bool existeCI(int ci)
    {
        for (int i = 0; i < indice; i++)
        {
            if (lista[i]->getCI() == ci)
                return true;
        }
        return false;
    }

    void agregar(Operador* o)
    {
        if (!existeCI(o->getCI()))
        {
            lista[indice++] = o;
        }
        else
        {
            cout << "CI duplicado" << endl;
        }
    }

    Operador* get(int i)
    {
        return lista[i];
    }

    int getIndice()
    {
        return indice;
    }
};