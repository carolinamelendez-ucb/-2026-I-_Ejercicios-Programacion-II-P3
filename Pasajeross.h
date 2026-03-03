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
	Pasajero(string nombre, int ci)
	{
		this->ci = ci;
		this->nombre = nombre;
		this->numeroAsiento = numeroAsiento;
	}
	void asignarAsiento(int numero) {
		this->numeroAsiento = numero;
	}
	void mostrar() {
		cout << "nombre: " << nombre<<endl;
		cout << "ci: " << ci << endl;
		cout << "numero de Asiento: " <<numeroAsiento<< endl;
	}
};
