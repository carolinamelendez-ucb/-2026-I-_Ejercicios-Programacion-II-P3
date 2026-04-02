#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

class EmpleadoPorHoras: public Empleado
{
private:
	int cantidadHoras;
public:
	EmpleadoPorHoras(string nombre, int ci, int salarioBase, int cantidadHoras):
		Empleado(nombre, ci, salarioBase)
	{
		this->cantidadHoras = cantidadHoras;
	}
	float calcularSalario() override
	{
		return salarioBase * cantidadHoras;
	}
	void mostrarInformacion() override
	{
		cout << "nombre: " << nombre << endl;
		cout << "ci: " << ci << endl;
		cout << "salarioBase: " << salarioBase << endl;
		cout << "Cantidad de horas " << cantidadHoras << endl;
		cout << "Salario total: " << calcularSalario() << endl;
	}

};
