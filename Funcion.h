#pragma once
#include "EspectadorVector.h"
#include "Empleado.h"

#include <string>
#include <iostream>
using namespace std;

class Funcion
{
private:
	string codigo;
	string nombrePelicula;
	int maxEspectadores;
	EspectadorVector* listaEspectadores;
	Empleado* empleado;
	bool estaActiva; // funcion

public:
	Funcion(string codigo, string nombrePeli, int maxEspectadores, Empleado* empleado)
	{
		this->codigo = codigo;
		this->nombrePelicula = nombrePeli;
		this->maxEspectadores = maxEspectadores;
		this->listaEspectadores = new EspectadorVector(maxEspectadores);
		this->empleado = empleado;
		bool estaActiva = true;

		empleado->setDisponible(false);
	}
	string getCodigo()
	{
		return codigo;
	}

	void finalizar()
	{
		estaActiva = false;// la funcion 
		empleado->setDisponible(true); // empleado
		empleado->incrementarFunciones();
	}
};



