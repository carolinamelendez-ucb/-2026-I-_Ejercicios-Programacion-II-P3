#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pasajero {
private:
	string nombre;
	int ci;
	int numAsiento;
public:
	Pasajero(string nombre, int ci) {
		this->ci = ci;
		this->nombre = nombre;
		this->numAsiento = 0;
	}
	void asignarAsiento(int num) {
		this->numAsiento = num;
	}
	int getAsiento() {
		return numAsiento;
	}
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "CI: " << ci << endl;
		cout << "Asiento: " << numAsiento << endl;
	}
};
