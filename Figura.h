#pragma once
#include <iostream>
#include <string>
using namespace std;

class Figura {
public:
protected:
    string tipo;
public:
    Figura(string tipo) : tipo(tipo) {
    }

    virtual double calcularArea() = 0;

    virtual void mostrarInfo() = 0;

    string getTipo() {
        return tipo;
    }
};