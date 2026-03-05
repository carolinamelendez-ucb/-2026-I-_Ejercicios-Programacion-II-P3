#pragma once
#include <iostream>
#include <string>

using namespace std;

class Equipo {
private:
    string nombre;
    string piloto;
    string copiloto;
    string automovil;

public:
    Equipo(string nombre, string automovil) {
        this->nombre = nombre;
        this->piloto = "";
        this->copiloto = "";
        this->automovil = automovil;
    }

    string getNombre() { return nombre; }
    string getPiloto() { return piloto; }
    string getCopiloto() { return copiloto; }
    string getAutomovil() { return automovil; }

    string setPiloto(string nPiloto) { this->piloto = nPiloto; }
    string setCopiloto(string nCopiloto) { this->copiloto = nCopiloto; }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Nombre de Piloto: " << piloto << endl;
        cout << "Nombre de Copiloto: " << copiloto << endl;
        cout << "Numero de Asiento: " << automovil << endl;
    }
};