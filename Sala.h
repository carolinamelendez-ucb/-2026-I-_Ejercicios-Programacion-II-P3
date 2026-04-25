#pragma once
#include <iostream>
#include <string>
using namespace std;

class Sala {
private:
	int NdeSala;
	int capacidad;
public:
	Sala(int NdeSala, int capacidad) {
		this->NdeSala = NdeSala;
		this->capacidad = capacidad;
	}
	void mostrar() {
		cout << "N de sala: " << NdeSala << endl;
		cout << "Capacidad: " << capacidad << endl;
	}
};

