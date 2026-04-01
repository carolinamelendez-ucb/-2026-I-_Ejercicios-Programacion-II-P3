#pragma once
#include <iostream>
#include <string>
#include "Figura.h"

using namespace std;

class Rectangulo : public Figura {
private:
    float base;
    float altura;

public:
    Rectangulo(string nombre, float base, float altura) 
        : Figura(nombre) {
        this->base = base;
        this->altura = altura;
    }

    float calcularArea() override {
        return base * altura;
    }

    virtual void mostrarInformacion() override {
        cout << "Rectangulo - Base: " << base << " m, Altura: " << altura << " m" << endl;
    }
};