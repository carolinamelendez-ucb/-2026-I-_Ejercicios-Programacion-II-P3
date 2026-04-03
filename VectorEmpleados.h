#pragma once
#include <iostream>
#include <string>
#include "Empledo.h"
using namespace std;

class VectorEmpleados
{
private:
    Empleado** empleados;
    int tamanio;
    int indice;
public:
    VectorEmpleados(int tamanio)
    {
        this->tamanio = tamanio;
        indice = 0;
        empleados = new Empleado * [tamanio];
    }

    bool existeCI(int ci)
    {
        for (int i = 0; i < indice; i++)
        {
            if (empleados[i]->getCi() == ci)
                return true;
        }
        return false;
    }

    void agregar(Empleado* e)
    {
        if (!existeCI(e->getCi()))
        {
            empleados[indice++] = e;
        }
        else
        {
            cout << "CI duplicado" << endl;
        }
    }

    void mostrar()
    {
        for (int i = 0; i < indice; i++)
        {
            empleados[i]->mostrarInformacion();
        }
    }

    float totalSalarios()
    {
        float suma = 0;
        for (int i = 0; i < indice; i++)
        {
            suma += empleados[i]->calcularSalario();
        }
        return suma;
    }
};