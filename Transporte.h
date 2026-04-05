#pragma once
#include <iostream>
using namespace std;

class Transporte {
protected:
    string placa;

public:
    Transporte(string placa) {
        this->placa = placa;
    }

    string getPlaca() {
        return placa;
    }

    virtual float calcularCosto(float distancia) = 0;

    virtual void mostrar() {
        cout << "Placa: " << placa << endl;
    }

    virtual ~Transporte() {}
};