#pragma once
#include "Transporte.h"

class Operador {

private:

    string nombre;
    string ci;
    float distancia;
    Transporte* transporte;

public:

    Operador(string nombre, string ci, float distancia, Transporte* transporte) {

        this->nombre = nombre;
        this->ci = ci;
        this->distancia = distancia;
        this->transporte = transporte;
    }

    string getCI() {
        return ci;
    }

    float calcularCosto() {
        return transporte->calcularCosto(distancia);
    }

    string getNombre() {
        return nombre;
    }

    string getPlaca() {
        return transporte->getPlaca();
    }

    ~Operador() {}
};