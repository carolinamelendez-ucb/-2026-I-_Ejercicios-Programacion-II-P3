#pragma once
#include <string>
#include <iostream>
#include "Empleado.h"

using namespace std;

class EmpleadoVector
{
private:
	Empleado** empleados;
	int tamanio;
	int indice;

public:

	EmpleadoVector(int tamanio)
	{
		this->tamanio = tamanio;
		this->indice = 0;
		this->empleados = new Empleado * [tamanio];
	}

	bool agregar(Empleado* nuevoEmpleado)
	{
		for (int i = 0; i < indice; i++)
		{
			if (empleados[i]->getCi() == nuevoEmpleado->getCi())
			{
				return false;
			}
		}
		this->empleados[indice] = nuevoEmpleado;
		indice++;
		return true;
	}

	void OrdenarPorFunciones()
	{
		Empleado* temp = nullptr;
		for (int i = 0; i < indice - 1; i++)
		{
			for (int j = 0; j < indice - 1 - i; j++)
			{
				if (empleados[j]->getFunciones() < empleados[j + 1]->getFunciones())
				{
					temp = empleados[j];
					empleados[j] = empleados[j + 1];
					empleados[j + 1] = temp;
				}
			}
		}
	}
	Empleado* busquedaLibreMenorFunc()
	{
		Empleado* mejor = nullptr;

		for (int i = 0; i < indice; i++)
		{
			if (empleados[i]->getLibre())
			{
				if (mejor == nullptr || empleados[i]->getFunciones() < mejor->getFunciones())
				{
					mejor = empleados[i];
				}
			}
		}
		return mejor;
	}

	void mostrar()
	{
		for (int i = 0; i < indice; i++)
		{
			this->empleados[i]->mostrar();
		}
	}


};

