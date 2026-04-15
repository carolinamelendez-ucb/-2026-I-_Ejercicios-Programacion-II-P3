#pragma once
#include "Estudiante.h"

class EstudiantePostgrado :public Estudiante
{
private:
	float recargo;
public:
	EstudiantePostgrado(string nombre, int ci,bool pagoMatricula)
		:Estudiante(nombre, ci, 2100,pagoMatricula)
	{
		this->recargo = 0.20;
	}

	float calcularCosto()
	{
		return costoMatricula * (1 + recargo);
	}
	void mostrar()
	{
		Estudiante::mostrar();
		cout << "el costo de la matricula: " << costoMatricula << endl;
		cout << "Total a pagar: " << calcularCosto() << endl;

	}
};
