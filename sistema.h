#pragma once
#include "vehiculos.h"
#include <string>
#include <iostream>
using namespace std;
class Sistema {

private:

    string nombre;
    string ci;
    float distancia;
    Transporte* transporte;

public:

    Sistema(string nombre, string ci, float distancia, Transporte* transporte) {

        this->nombre = nombre;
        this->ci = ci;
        this->distancia = distancia;
        this->transporte = transporte;
    }

    string getCI() {
        return ci;
    }
    string getNombre() {
        return nombre;
    }
   string getPlaca() {
        return transporte->getPlaca();
    }
   float calcularCosto() {
       return transporte->calcularCosto(distancia);
   }


    ~Sistema() {}
};