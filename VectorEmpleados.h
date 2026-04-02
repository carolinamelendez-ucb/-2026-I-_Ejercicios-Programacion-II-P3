#pragma once
#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

class VectorEmpleados
{
private:
	Empleado** lista;
	int tamanio;
	int cantidad;
public:
	VectorEmpleados(int tamanio)
	{
		this->lista = new Empleado * [tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}

	void agregar(Empleado* nuevoEmpleado)
	{
		if (cantidad < tamanio)
		{
			lista[cantidad] = nuevoEmpleado;
			cantidad++;
		}
		else 
		{
			cout << "El vector esta lleno, nose puede agregar" << endl;
		}
	}
	void mostrar()
	{
		for (int i = 0; i < cantidad; i++)
		{
			lista[i]->mostrarInformacion();
		}
	}
	~VectorEmpleados()
	{
		for (int i = 0; i < cantidad; i++)
		{
			delete lista[i];
		}
		delete[]lista;
	}
	Empleado* BuscarPorCi(int ciBuscado)
	{
		for (int i = 0; i < cantidad; i++)
		{
			if (lista[i]->getCi() == ciBuscado)
			{
				return lista[i];
			}
		}
		return nullptr;
	}
	float calcularTotalSalarios()
	{
		float aux = 0;
		for (int i = 0; i < cantidad; i++)
		{
			aux = aux + lista[i]->calcularSalario();
		}
		return aux;
	}
};

