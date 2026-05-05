#pragma once
#include <iostream>
#include <string>
using namespace std;
class Auto {
private:
    string marca;

public:
    Auto(string marca) {
       this->marca = marca;
    }

    string getMarca() {
        return marca;
    }
    void mostrar() {
        cout << "Marca: " << marca << endl;
    }
};