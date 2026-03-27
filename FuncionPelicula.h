#pragma once
#include <iostream>
#include <string>
#include "VectorEspectador.h"
#include "Empleado.h"

using namespace std;

class FuncionPelicula {
private:
	string nombrePelicula;
	int codigo;
	int maxExpectadores;
	VectorEspectador * listaEspectadores;
	Empleado * empleado;
public:

	FuncionPelicula() = default;

	FuncionPelicula(const string& nombrePelicula, int codigo, int maxExpectadores, Empleado * empleado)
		: nombrePelicula(nombrePelicula), codigo(codigo), maxExpectadores(maxExpectadores)
	{
		this->empleado = empleado;
		this->listaEspectadores = new VectorEspectador(maxExpectadores);
	}
	//void agregarEspectadores() {};
	void mostrar() {
		cout << "Nombre de la Pelicula: " << nombrePelicula << endl;
		cout << "Codigo de la Funcion: " << codigo << endl;
		cout << "Maximo de Espectadores:" << maxExpectadores << endl;
		if (empleado == nullptr) {
			cout << "Empleado asignado a laFuncion: Ninguno" << endl;
		}
		else {
			cout << "Empleado asignado a la Funcion:" << endl;
			empleado->mostrar();
		}
		
		cout << "Lista de espectadores de la fucnion: ... " << endl;
		listaEspectadores->mostrar();
	}
	int getCodigo() {
		return codigo;
	}
	Empleado* getEmpleado() {
		return empleado;
	}
};