#pragma once
#include <iostream>
#include "Socio.h"

using namespace std;

class Equipo {
private:
    string nombre;
    Socio* piloto;
    Socio* copiloto;
    string automovil;

public:
    Equipo(string nombre, string automovil) {
        this->nombre = nombre;
        this->automovil = automovil;
    }

    void registrarSocios(Socio* piloto, Socio* copiloto) {

        if (piloto == copiloto) {
            cout << "Error: Piloto y copiloto no pueden ser el mismo socio" << endl;
            return;
        }

        this->piloto = piloto;
        this->copiloto = copiloto;
    }

    bool participaSocio(Socio* s) {

        if (piloto == s) return true;
        if (copiloto == s) return true;

        return false;
    }

    Socio* getPiloto() { return piloto; }
    Socio* getCopiloto() { return copiloto; }

    void mostrar() {
        cout << "Nombre del equipo: " << nombre << endl;
        cout << "Piloto: " << piloto->getNombre() << endl;
        cout << "Copiloto: " << copiloto->getNombre() << endl;
        cout << "Automovil: " << automovil << endl;
    }
};