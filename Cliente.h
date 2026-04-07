#pragma once
#include <iostream>
#include <string>
#include "VectorPago.h"
using namespace std;

class Cliente
{
private:
    string nombre;
    VectorPagos* listaPagos;

public:
    Cliente(string nombre)
    {
        this->nombre = nombre;
        listaPagos = new VectorPagos(10);
    }

    void agregarPago(Pago* p)
    {
        listaPagos->agregar(p);
    }

    void mostrar()
    {
        cout << "Cliente: " << nombre << endl;
        cout << "----------------------------------" << endl;
        listaPagos->mostrarPagos();
    }

    float totalCliente()
    {
        return listaPagos->totalPagos();
    }
};