#pragma once
#include <iostream>
#include <string>
#include "Sala.h"
#include "Pelicula.h"
#include "ArrayGenerico.h"
#include "Cliente.h"
using namespace std;
class Funcion
{
private:
	int numFuncion;
	Pelicula* peliculaAsignada;
	ArrayGenerico<Cliente>** listaClientes;
public:
	Funcion(int tamanio) {
		listaClientes = new ArrayGenerico < Cliente> * [tamanio];

	}
	~Funcion() {
		delete[] listaClientes; 
	}
};

