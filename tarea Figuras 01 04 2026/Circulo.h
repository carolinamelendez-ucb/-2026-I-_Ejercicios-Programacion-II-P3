#pragma once
#include <iostream>
#include <string>
#include "Figura.h"

using namespace std;

class Circulo : public Figura {
private:
    float radio;

public:
    Circulo(string nombre, float radio) 
        : Figura(nombre) {
        this->radio = radio;
    }

    float calcularArea() override {
        return 3.1416 * radio * radio;
    }

    virtual void mostrarInformacion() override {
        cout << "Circulo - Radio: " << radio << " m" << endl;
    }
};

