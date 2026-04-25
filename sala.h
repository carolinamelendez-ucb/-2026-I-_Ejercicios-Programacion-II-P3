#pragma once
#include <iostream>
#include <string>
using namespace std;
class Sala {
private:
	int numeroFilas;
	int numeroAsientosFilas;
public:
	Sala(int numFilas, int numAsientos) {
		this->numeroFilas = numFilas;
		this->numeroAsientosFilas = numAsientos;
	}
	void mostrar() {
		cout << "El numero de filas es: " << numeroFilas << endl;
		cout << "El numero de asientos es: " << numeroAsientosFilas << endl;
	}
};