#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Empleado.h"
#include "VectorEspectadores.h"


class Funcion{
private:
	string nombre;
	int codigo;
	int maxEspectadores;
	Empleado* empleadoAsignado;
	VectorEspectadores* espectadores;
public:
	Funcion (string nombre, int codigo, int maxEspectadores){
		this->nombre = nombre;
		this->codigo = codigo;
		this->maxEspectadores =maxEspectadores;
		this->empleadoAsignado = nullptr;
		this-> espectadores = new VectorEspectadores (maxEspectadores);

	}

	Funcion (string nombre, int codigo, int maxEspectadores , Empleado* empleadoAsignado){
		this->nombre = nombre;
		this->codigo = codigo;
		this->maxEspectadores = maxEspectadores;
		this->empleadoAsignado = empleadoAsignado;
		this->espectadores = new VectorEspectadores (maxEspectadores);

	}

	void asignarEmpleadoAFuncion (Empleado* empleadoAsignados){
		this->empleadoAsignado = empleadoAsignados;
		empleadoAsignados->actualizarEstado();

	}
	void mostrar ()  {
		cout << "Nombre de la funcion: " << nombre << endl;
		cout << "Codigo: " << codigo << endl;
		cout << "Maximo de espectadores: " << maxEspectadores << endl;

		cout << "Empleado asignado: ";
		if(empleadoAsignado != nullptr) {
			cout << endl;
			cout << empleadoAsignado->getNombre () << endl;
		}
		else {
			cout << "Ninguno" << endl;
		}

		cout << "Espectadores registrados:" << endl;
		espectadores->mostrar (); 
	}

	int getCodigo (){
		return	 codigo;
	}

	void finalizarFuncion (){
		empleadoAsignado->actualizarEstado();
	}
};