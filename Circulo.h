#pragma once
#include <string>
#include <iostream>
#include "Figura.h"
using namespace std;

class Circulo : public Figura {
private:
    double radio;
    double PI = 3.1416;
public:
    Circulo(double rd) :
        Figura("Circulo"), radio(rd) {
    }

    double calcularArea() override {
        return PI * (radio * radio);
    }

    void mostrarInfo() override {
        cout << "Figura: Circulo " << endl;
        cout << "Radio: " << radio << endl;
    }
};