#pragma once
#include <iostream>
#include <string>
#include "Proyecto.h"
using namespace std;

class VectorProyectos
{
private:
    Proyecto** proyectos;
    int tamanio;
    int indice;
public:
    VectorProyectos(int tamanio)
    {
        this->tamanio = tamanio;
        indice = 0;
        proyectos = new Proyecto * [tamanio];
    }

    bool existeCodigo(int codigo)
    {
        for (int i = 0; i < indice; i++)
        {
            if (proyectos[i]->getCodigo() == codigo)
                return true;
        }
        return false;
    }

    void agregar(Proyecto* p)
    {
        if (!existeCodigo(p->getCodigo()))
        {
            proyectos[indice++] = p;
        }
        else
        {
            cout << "Codigo duplicado" << endl;
        }
    }

    void mostrar()
    {
        for (int i = 0; i < indice; i++)
        {
            proyectos[i]->mostrar();
            cout << "Costo: " << proyectos[i]->calcularCosto() << endl;
        }
    }

    void proyectoMayorCosto()
    {
        float mayor = 0;
        int pos = -1;

        for (int i = 0; i < indice; i++)
        {
            float costo = proyectos[i]->calcularCosto();
            if (costo > mayor)
            {
                mayor = costo;
                pos = i;
            }
        }

        if (pos != -1)
        {
            cout << "Proyecto con mayor costo=" << endl;
            proyectos[pos]->mostrar();
            cout << "Costo: " << mayor << endl;
        }
    }
};