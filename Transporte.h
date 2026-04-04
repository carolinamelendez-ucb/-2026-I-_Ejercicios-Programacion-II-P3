#pragma once
#include <iostream>
#include <string>

using namespace std;

class Transporte {

protected:
    string placa;

public:

    Transporte(const string& placa) : placa(placa) {}

    string getPlaca() { return placa; }

    virtual float calcularCosto(float distancia) = 0;

    virtual void mostrar() {
        cout << "Placa: " << placa << endl;
    }
};