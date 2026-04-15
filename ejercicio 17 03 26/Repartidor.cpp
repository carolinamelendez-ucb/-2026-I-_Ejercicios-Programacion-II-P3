#include "Repartidor.h"

#include <iostream>
#include <string>

using namespace std;

Repartidor::Repartidor() {
    this->nombre = "";
    this->id = 0;
    this->entregasRealizadas = 0;
    this->estado = "libre";
}

Repartidor::Repartidor(string nombre, int id) {
    this->nombre = nombre;
    this->id = id;
    this->entregasRealizadas = 0;
    this->estado = "libre";
}