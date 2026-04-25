#pragma once
#include <iostream>
#include <string>
#include "Pelicula.h"
#include "Sala.h"
#include "ArrayGenerico.h"

using namespace std;

class Funcion {
private:
	Pelicula* pelicula;
	Sala* sala;
	ArrayGenerico<Cliente>* clientes;
public:
	Funcion(int tamClientes) {
		clientes = new ArrayGenerico<Cliente>(tamClientes);
	}

	void mostrar() {
		cout << "Pelicula: " << pelicula << endl;
		cout << "Sala: " << sala << endl;
		cout << "Lista de clientes: " << endl;
		clientes->mostrar();
	}
};