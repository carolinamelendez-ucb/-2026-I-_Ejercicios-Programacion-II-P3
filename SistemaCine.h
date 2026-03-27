#pragma once
#include <iostream>
#include <string>
#include "VectorFuncionPelicula.h"
#include "VectorEmpelado.h"

using namespace std;

class SistemaCine {
private:
	VectorEmpleado* listaEmpleados;
	VectorFuncionPelicula* listaFunciones;
public:
	SistemaCine(int tamanioEmpleados, int tamanioFunciones) {
		this->listaEmpleados = new VectorEmpleado(tamanioEmpleados);
		this->listaFunciones = new VectorFuncionPelicula(tamanioFunciones);
	}

	//1
	void registrarEmpleados(string nombre, int ci) {
		Empleado* nuevoEmpleado = new Empleado(nombre, ci);
		if (!listaEmpleados->buscarCiExistente(ci)) {
			listaEmpleados->agregar(nuevoEmpleado);
		}
		else {
			cout << "Ci duplicado, no se regitro un empelado" << endl;
		}
	}

	//2
	void mostrarEmpelados() {
		listaEmpleados->oredenarEmpleadosCantidadFunciones();
		listaEmpleados->mostrar();
	}
	// 3
	void RegistrarFunciones(string nombre, int codigo, int maxEspectadores) {
		if (listaFunciones->buscarCodigoExistente(codigo)) {
			cout << "Codigo duplicado, no se registro una funcion" << endl;
			return;
		}


		Empleado* empleadoAsignado = listaEmpleados->empeladoMenorCantidadLibre();
		if (empleadoAsignado != nullptr) {
		FuncionPelicula* funcionNueva = new FuncionPelicula(nombre, codigo, maxEspectadores, empleadoAsignado);
		listaFunciones->agregar(funcionNueva);
		empleadoAsignado->setEstado(false);
		}
		else {
			cout << "No se pudo registrar la funcion, no hay empleados disponibles, error!" << endl;
		}
	}
	//metodo aux
	void mostrarFunciones() {
		listaFunciones->mostrar();
	}

	//4
	void finalizarFuncion(int codigoFuncion) {
		
		FuncionPelicula* auxFuncion = listaFunciones->getFuncion(codigoFuncion);
		if (auxFuncion == nullptr) {
			cout << "Funcion no encontrada, error!" <<endl;
			return;
		}
		auxFuncion->getEmpleado()->aumenarCantidadFuncionesAtendidas();
		auxFuncion->getEmpleado()->setEstado(true);
	}
	~SistemaCine() {
		delete listaEmpleados;
		delete listaFunciones;
	}
};