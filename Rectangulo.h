#pragma once
#include <string>
#include <iostream>
#include "Figura.h"
using namespace std;


class Rectangulo : public Figura {
private:
    double base;
    double altura;
public:
    Rectangulo(double bs, double alt) :
        Figura("Rectangulo"), base(bs), altura(alt) {
    }

    double calcularArea() override {
        return base * altura;
    }

    void mostrarInfo()override {
        cout << "Figura: Rectangulo" << endl;
        cout << "Base: " << base << endl;
        cout << "Altura: " << altura << endl;
    }
};