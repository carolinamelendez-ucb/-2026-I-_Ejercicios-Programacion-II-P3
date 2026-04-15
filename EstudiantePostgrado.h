#pragma once
#include <iostream>
#include <string>
#include "Estudiante.h"
using namespace std;

class EstudiantePostgrado: public Estudiante {
private:
	float recargo;
public:
	EstudiantePostgrado(int ci, const string& nombre, int matricula, bool pago)
		: Estudiante(ci,nombre,matricula,"Postgrado",pago)
	{
		this->recargo = 0.2;
	}

	void mostrar() {
		Estudiante::mostrar();
		cout << "Recargo: " << recargo << endl;
	}
	float costoTotal() {
		return Estudiante::costoTotal() * (1 + recargo);
	}
};