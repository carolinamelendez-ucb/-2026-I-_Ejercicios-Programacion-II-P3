#pragma once
#include <iostream>
#include <string>
#include "socio.h"
using namespace std;

class Equipo {
private: 
	string nombreE;
	string autoC;
	Socio* piloto;
	Socio* copiloto;
public:
	Equipo(string nombreE, string autoC, Socio* piloto, Socio* copiloto) {
		this->nombreE = nombreE;
		this->autoC = autoC;
		this->piloto = piloto;
		this->copiloto = copiloto;
	}
    Socio* getPiloto() {
        return piloto;
    }
    Socio* getCopiloto() {
        return copiloto;
    }
    void mostrar() {
        cout << "Equipo: " << nombreE << endl;
        cout << "Auto: " << autoC << endl;
        cout << "--- Piloto ---" << endl;
        piloto->mostrar();
        cout << "--- Copiloto ---" << endl;
        copiloto->mostrar();
    }
};
