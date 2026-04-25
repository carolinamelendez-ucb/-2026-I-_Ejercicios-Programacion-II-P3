#pragma once
#include <iostream>
#include <string>
#include "Pelicula.h"
#include "Sala.h"
#include "ArrayGenerico.h"
#include "Cliente.h"
using namespace std;
class Funcion {

	Pelicula* pelicula;
	int horaInicio;
	Sala* sala;
	ArrayGenerico<Cliente>* listaClientes;
};