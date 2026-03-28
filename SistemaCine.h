#pragma once
#include <iostream>
#include <string>
#include "VectorEmpleados.h"
#include "VectorFunciones.h"
using namespace std;
class SistemaCine {
private:
	VectorEmpleados* empleados;
	VectorFunciones* funciones;
public:
	SistemaCine(int maxEmpleados, int maxFunciones) {
		empleados = new VectorEmpleados(maxEmpleados);
		funciones = new VectorFunciones(maxFunciones);
	}
	~SistemaCine() {
		delete empleados;
		delete funciones;
	}
	void registrarEmpleados(const string& nombre, int ci) {
		empleados->agregar(new Empleado(nombre, ci));
	}
	void mostrarEmpleadosOrdenados() {
		empleados->ordenarPorFunciones();
		empleados->mostrarVectoresEmpleados();
	}
	void registrarFuncion(int codigo, const string& nombrePelicula, int maxEspectadores) {
		if (funciones->buscar(codigo) != nullptr) {
			cout << "Codigo de funcion duplicado" << endl;
			return;
		}
		Empleado* empleado = empleados->buscarLibreMenosFunciones();
		if (empleado == nullptr) {
			cout << "No hay empleados libre" << endl;
			return;
		}
		funciones->agregar(new Funcion(nombrePelicula, codigo, maxEspectadores, empleado));
	}
	void finalizarFuncion(int codigo) {
		Funcion* funcion = funciones->buscar(codigo);
		if (funcion != nullptr && funcion->estaActiva()) {
			funcion->finalizar();
			cout << "Funcion finalizada" << endl;
		}
	}
	void mostrarFunciones() {
		funciones->mostrarVectorFunciones();
	}
};