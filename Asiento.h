#pragma once
#include <iostream>
#include <string>
using namespace std;

class Asiento {
private:
    string codigo; 
    bool disponible;

public:
    Asiento(string codigo) {
        this->codigo = codigo;
        this->disponible = true;
    }

    string getCodigo() { return codigo; }
    bool estaDisponible() { return disponible; }

    void ocupar() { disponible = false; }
};