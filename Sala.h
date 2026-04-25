#pragma once
#include "Cliente.h"
#include "ArrayGenerico.h"
using namespace std;

class Sala {
private:
	int numeroSala;
	int filas;
	int columnas;
	ArrayGenerico<Cliente>* clientes;
public:
	Sala(int numeroSala, int filas, int columnas) :numeroSala(numeroSala), filas(filas), columnas(columnas) {
		this->clientes = new ArrayGenerico<Cliente>(filas * columnas);
	}
	void mostrar() {
		cout << "Numero de la sala: " << numeroSala << endl;
		cout << "Lista de los clientes: " << endl;
		clientes->mostrar();
	}
};