#pragma once
#include <iostream>
#include "Pasajero.h"

using namespace std;

class Pasajeros {
private:
    Pasajero lista[50];
    int cantidad;

public:
    Pasajeros() {
        cantidad = 0;
    }

    void agregar(Pasajero p) {
        lista[cantidad++] = p;
    }

    void mostrarSinAsiento() {
        for (int i = 0;i < cantidad;i++)
            if (lista[i].getAsiento() == 0)
                lista[i].mostrar();
    }

    void mostrarImpares() {
        for (int i = 0;i < cantidad;i++)
            if (lista[i].getAsiento() % 2 == 1)
                lista[i].mostrar();
    }

    void buscarNombre(string nombre) {
        for (int i = 0;i < cantidad;i++)
            if (lista[i].getNombre() == nombre)
                lista[i].mostrar();
    }

    void buscarCI(int ci) {
        for (int i = 0;i < cantidad;i++)
            if (lista[i].getCi() == ci)
                lista[i].mostrar();
    }
};