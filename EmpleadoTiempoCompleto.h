#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

class EmpleadoTiempoCompleto: public Empleado
{
private:
	float bono;
public:
	EmpleadoTiempoCompleto(string nombre, int ci, int salarioBase,float bono)
		:Empleado(nombre,ci,salarioBase)
	{
		this->bono = bono;
	}

	float calcularSalario() override
	{
		return salarioBase + bono;
	}
	void mostrarInformacion()
	{
		cout << "nombre: " << nombre << endl;
		cout << "ci: " << ci << endl;
		cout << "salarioBase: " << salarioBase << endl;
		cout << "bono: " << bono << endl;
		cout << "Salario total: " << calcularSalario() << endl;
	}
};

