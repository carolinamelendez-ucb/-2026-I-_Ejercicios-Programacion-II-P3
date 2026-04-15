#pragma once
#include <iostream>
#include <string>

using namespace std;

class Estudiante
{
protected:
	string nombre;
	int ci;
	float costoMatricula;
	bool pagoMatricula;
public:

	Estudiante(const string& nombre, int ci, float costoMatricula, bool pagoMatricula)
		: nombre(nombre), ci(ci), costoMatricula(costoMatricula), pagoMatricula(pagoMatricula)
	{}
	virtual float calcularCosto() = 0;
	virtual void mostrar()
	{
		cout << "nombre: " << nombre << endl;
		cout << "ci: " << ci << endl;
	}
	int getCi()
	{
		return ci;
	}
	bool getPagoMatricula()
	{
		return pagoMatricula;
	}

};