#pragma once
#include "EmpleadoVector.h"
#include "FuncionVector.h"
#include <string>
#include <iostream>
using namespace std;

class SistemaCine
{
private:
	EmpleadoVector* listaEmpleados;
	FuncionVector* listaFunciones;

public:

	SistemaCine(int tamListaEmpleados, int tamListaFunciones)
	{
		this->listaEmpleados = new EmpleadoVector(tamListaEmpleados);
		this->listaFunciones = new FuncionVector(tamListaFunciones);
	}
	//op 1
	void registrarEmpleado(string nombre, string ci)
	{
		Empleado* nuevoEmpleado = new Empleado(nombre, ci);
		if (!listaEmpleados->agregar(nuevoEmpleado))
		{
			cout << " Codigo Ci duplicado: " << ci << endl;
		}
	}
	// op2
	void mostrarEmpleadosOrdenados()
	{
		listaEmpleados->OrdenarPorFunciones();
		listaEmpleados->mostrar();
	}
	//op3
	void registrarFuncion(string codigo, string nombrePeli, int maxEspectadores)
	{
		Empleado* empleado = listaEmpleados->busquedaLibreMenorFunc();

		if (empleado == nullptr)
		{
			cout << " No hay empleados libres " << endl;
			return;
		}

		Funcion* funcion = new Funcion(codigo, nombrePeli, maxEspectadores, empleado);

		if (!listaFunciones->agregarFuncion(funcion))
		{
			cout << "Codigo de peli Duplicado  ... " << endl;
		}
	}

	// op 4
	void finalizarFuncion(string codigo)
	{
		Funcion* funcion = listaFunciones->buscarPorCodigo(codigo);
		if (funcion != nullptr)
		{
			funcion->finalizar();
		}
	}


};