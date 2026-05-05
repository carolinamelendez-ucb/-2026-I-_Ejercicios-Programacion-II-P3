#pragma once
#include <iostream>
using namespace std;

class Auto {
private:
    string marca;
    string modelo;

public:
    Auto() {}

    Auto(string marca, string modelo) {
        this->marca = marca;
        this->modelo = modelo;
    }

    void mostrar() {
        cout << "Marca: " << marca << " - Modelo: " << modelo << endl;
    }
};