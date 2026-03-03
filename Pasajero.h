#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pasajero {
private:
	string nombre;
	int ci;
	int numeroAsiento;
public:
	Pasajero(string nombre, int ci) {
		this->ci = ci;
		this->nombre = nombre;
		this->numeroAsiento = 0;
	}
	void asignarAsiento(int numero) {
		this->numeroAsiento = numero;
	}
	string getNombre() {
		return nombre;
	}
	int getCi() {
		return ci;
	}
	int getNumeroAsiento() {
		return numeroAsiento;
	}
	bool tieneAsiento() {
		return numeroAsiento != 0;
	}
	void mostrar() {
		cout << "nombre: " << nombre << endl;
		cout << "CI :" << ci << endl;
		if (numeroAsiento == 0) {
			cout << "Asiento :(sin asiento)" << endl;
		}
		else {
			cout << "Asiento: " << numeroAsiento << endl;
		}
	}
};