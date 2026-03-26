#pragma once
#include <iostream>
#include <string>
using namespace std;
class Empleado
{
protected:
	string nombre;
	float salario_base;
	string departamento;
public:
	Empleado(string nombre, float salario_base, string departamento)
	{
		this->nombre = nombre;
		this->salario_base = salario_base;
		this->departamento = departamento;
	}
	virtual void calcular_Salario() = 0;
};

