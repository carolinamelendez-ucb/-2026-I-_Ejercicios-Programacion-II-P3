#pragma once
#include <iostream>
#include <string>

#include "Repartidor.h"

using namespace std;

class Entrega {
public:
    int id;
    string direccion;
    int cantidadPaquetes;
    Repartidor* repartidorAsignado;
    string estado; // "activa" o "finalizada"

    Entrega();
    Entrega(int id, string direccion);
};
