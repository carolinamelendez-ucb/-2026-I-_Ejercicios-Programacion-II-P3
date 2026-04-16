#pragma once
#include <iostream>
#include <string>
#include "ListaEstudiantes.h"
#include "Curso.h"
using namespace std;


class Docente {
protected:
	string nombre;
	int ciD;
	bool EstadoActual;
	double salario;
	int cantCursos;
public:

	Docente(const string& nombre, int ciD, bool EstadoActual,int salarios,int cantCurso)
		: nombre(nombre), ciD(ciD), EstadoActual(EstadoActual),salario(salarios), cantCursos(cantCurso)
	{}
	
	virtual double calcularBono() = 0;
	virtual void mostrard() = 0;

	bool getEstadoActual() {
		return EstadoActual;
	}

	int getCiD() {
		return ciD;
	}

	double getBono() {
		return salario;
	}

	~Docente(){}
};