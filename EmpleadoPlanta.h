#pragma once
#include "Empleado.h"
class EmpleadoPlanta : public Empleado
{
private:
	float salarioExtra;
public:
	EmpleadoPlanta(string nombre, float salario_base, string departamento)
		:Empleado(nombre, salario_base, departamento)
	{
		this->salarioExtra = 0;
	}
	EmpleadoPlanta(string nombre, float salario_base, string departamento,float salrioExtra)
		:Empleado(nombre, salario_base, departamento)
	{
		this->salarioExtra = salrioExtra;
	}
	void calcular_Salario()
	{
		float salarioFinal;
		salarioFinal = salario_base + 1000; //bono fijo de empleados de planta
	}
};

