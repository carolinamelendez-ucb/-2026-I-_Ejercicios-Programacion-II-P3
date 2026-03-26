#pragma once
#include "Empleado.h"
class Contratista :public Empleado
{
private:
	int dias_trabajados;
public:
	Contratista(string nombre, float salario_base, string departamento, int dias_trabajados)
		:Empleado(nombre, salario_base, departamento)
	{
		this->dias_trabajados = dias_trabajados;
	}
	void calcular_Salario()
	{
		salario_base = salario_base * dias_trabajados;
	}
};

