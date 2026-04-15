#pragma once
#include "Estudiante.h"

class EstudiantePregrado:public Estudiante
{

public:
	EstudiantePregrado(string nombre, int ci, bool pagoMatricula)
		:Estudiante(nombre, ci, 2100,pagoMatricula)
	{}

	float calcularCosto()
	{
		return costoMatricula;
	}
	void mostrar()
	{
		Estudiante::mostrar();
		cout << "el costo de la matricula: " << costoMatricula << endl;
		cout << "Total a pagar: " << calcularCosto() << endl;

	}
};

