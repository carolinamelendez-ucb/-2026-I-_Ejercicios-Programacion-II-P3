#pragma once
#include <iostream>
#include <string>
#include "Espectador.h"
#include "Empleado.h"
using namespace std;

class Funcion {
private:
	string nombre;
	int codigo;
	int maxEspectadores;
	int cant;
	Espectador* espectadores;
	Empleado* empleado;
	bool activo;
public:
	Funcion(string nombre, int codigo, int maxEspectadores, Empleado* empleado) {
		this->nombre = nombre;
		this->codigo = codigo;
		this->maxEspectadores = maxEspectadores;
		this->cant = 0;
		this->espectadores = new Espectador[maxEspectadores];
		this->empleado = empleado;
		this->activo = true;
	}
	int getCodigo() {
		return codigo;
	}
	void finalizar() {
		if (empleado != nullptr) {
			empleado->liberar();
			empleado->incrementar();
			activo = false;
		}
	}
};
