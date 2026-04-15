#pragma once
#include <iostream>
#include <string>

using namespace std;

class Repartidor {
public:
    string nombre;
    int id;
    int entregasRealizadas;
    string estado; // "libre" u "ocupado"

    Repartidor();
    Repartidor(string nombre, int id);
};
