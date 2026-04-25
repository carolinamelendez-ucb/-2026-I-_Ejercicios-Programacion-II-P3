#pragma once
#include <iostream>
#include <string>
using namespace std;


class Sala {
private:
	int numSala;
	int capacidad;
public:
	Sala(int numSala, int capacidad)
		: numSala(numSala), capacidad(capacidad)
	{}

	void mostrar() {
		cout << "Num. sala:"<<numSala << endl;
		cout << "Capacidad: "<<capacidad << endl;
	}
};