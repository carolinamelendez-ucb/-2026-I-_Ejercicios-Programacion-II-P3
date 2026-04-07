#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"
using namespace std;

class Sistema
{
private:
    Cliente** clientes;
    int tamanio;
    int indice;

public:
    Sistema(int tamanio)
    {
        this->tamanio = tamanio;
        indice = 0;
        clientes = new Cliente * [tamanio];
    }

    void agregarCliente(Cliente* c)
    {
        if (indice < tamanio)
        {
            clientes[indice++] = c;
        }
    }

    void mostrarTodo()
    {
        for (int i = 0; i < indice; i++)
        {
            clientes[i]->mostrar();
        }
    }

    float totalGeneral()
    {
        float suma = 0;
        for (int i = 0; i < indice; i++)
        {
            suma += clientes[i]->totalCliente();
        }
        return suma;
    }
};