#include "Entrega.h"

#include <iostream>
#include <string>

using namespace std;

Entrega::Entrega() {
    this->id = 0;
    this->direccion = "";
    this->cantidadPaquetes = 0;
    this->repartidorAsignado = 0;
    this->estado = "activa";
}

Entrega::Entrega(int id, string direccion) {
    this->id = id;
    this->direccion = direccion;
    this->cantidadPaquetes = 0;
    this->repartidorAsignado = 0;
    this->estado = "activa";
}