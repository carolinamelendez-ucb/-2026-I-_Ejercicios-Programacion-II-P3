#pragma once
#include <iostream>
#include <string>
#include "VectorEmpleados.h"
#include "VectorProyectos.h"

using namespace std;

class Empresa
{
private:
	VectorEmpleados* listaEmpleados;
	VectorProyectos* listaProyectos;
public:
	Empresa(int tamanioEmpleados, int tamanioProyectos)
	{
		this->listaEmpleados = new VectorEmpleados(tamanioEmpleados);
		this->listaProyectos = new VectorProyectos(tamanioProyectos);
	}

	void registrarEmpelado(Empleado* nuevoEmpleado)
	{
		Empleado* CiEncontrado = listaEmpleados->BuscarPorCi(nuevoEmpleado->getCi());
		if (CiEncontrado == nullptr)
		{
			listaEmpleados->agregar(nuevoEmpleado);
		}
		else
		{
			cout << "Ya existe un empleado con ese CI" << endl;
		}
	}
	void registrarProyecto(Proyecto* nuevoProyecto)
	{
		Proyecto* codigoEncontrado = listaProyectos->BuscarCodigo(nuevoProyecto->getCodigo());
		if (codigoEncontrado == nullptr)
		{
			listaProyectos->agregar(nuevoProyecto);
		}
		else
		{
			cout << "Ya existe un rpoyecto con ese codigo" << endl;
		}
	}
	void mostrarEmpleado()
	{
		cout << "-----------Empleados----------" << endl;
		listaEmpleados->mostrar();
	}
	void mostrarProyecto()
	{
		cout << "-----------Proyectos----------" << endl;
		listaProyectos->mostrar();
	}

	void calcularTotalSalarios()
	{
		cout << "El total de salrios de empleados: " << listaEmpleados->calcularTotalSalarios()<< endl;
	}

	void proyectoMayorCosto()
	{
		Proyecto* mayor = listaProyectos->MayorCosto();
		cout << "El proyecto con mayor costo es:" << endl;
		mayor->mostrarInfo();
	}
		~Empresa()
	{
		delete listaEmpleados;
		delete listaProyectos;
	}



};
