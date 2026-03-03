#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pasajero {
private:
	string nombre;
	int CI;
	int numeroasientos;
public:
	Pasajero(string nombre, int CI) {
		this->nombre = nombre;
		this->CI = CI;
		this->numeroasientos = 0;
	}
	void asiento(int numero) {
		this->numeroasientos = numero;
	}
	int getasiento() { return numeroasientos; }
	void mostrar() {
		cout << "nombre: " << nombre << endl;
		cout << "CI: " << CI << endl;
		cout << "Numero de asiento: " << numeroasientos << endl;
	}
};
