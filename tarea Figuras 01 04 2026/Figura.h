#pragma once
#include <iostream>
#include <string>

using namespace std;

class Figura {
protected:
    string nombre;

public:
    Figura(const string& nombre) 
        : nombre(nombre) {
    }

    string getNombre() {
        return nombre;
    }

    virtual float calcularArea() = 0;
    virtual void mostrarInformacion() = 0;
};
