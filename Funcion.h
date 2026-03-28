#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"
#include "VectorEspectador.h"
using namespace std;
class Funcion {
private:
	string nombrePelicula;
	int codigo;
	int maxEspectadores;
	VectorEspectador* espectadores;
	Empleado* empleado;
	bool activo;
public:
	Funcion(const string& nombrePelicula, int codigo, int maxEspectadores, Empleado* empleado)
		: nombrePelicula(nombrePelicula), codigo(codigo), maxEspectadores(maxEspectadores), empleado(empleado), activo(true)
	{
		espectadores = new VectorEspectador(maxEspectadores);
		empleado->ocupar();
	}
	~Funcion() {
		delete espectadores;
	}
	int getCodigo() {
		return codigo;
	}
	bool estaActiva() {
		return activo;
	}
	void finalizar() {
		activo = false;
		empleado->liberar();
		empleado->incrementoFunciones();
	}
	void mostrarFuncion() {
		cout << "Nombre de la pelicula: " << nombrePelicula << endl;
		cout << "Codigo: " << codigo << endl;
		cout << "Cantidad espectadores: " << maxEspectadores << endl;
		cout << "Empleado asignado: " << endl;
		empleado->mostrarEmpleado();
	}
};