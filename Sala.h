#pragma once
#include <iostream>
#include <string>

using namespace std;

class Sala {
private:
	int puerta;
	int cantFilas;
	int cantAsientosFila;
public:
	Sala(int puerta, int cantFilas, int cantAsientosFila)
		: puerta(puerta), cantFilas(cantFilas), cantAsientosFila(cantAsientosFila)
	{
	}

	void mostrar() {
		cout << "Numero de puerta: " << puerta << endl;
		cout << "Cantidad de filas: " << cantFilas << endl;
		cout << "Cantidad de asientos por fila: " << cantAsientosFila << endl;
	}
};