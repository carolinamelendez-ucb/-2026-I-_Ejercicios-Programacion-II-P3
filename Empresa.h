#pragma once
#include <iostream>
#include <string>
#include "VectorProyecto.h"
#include "VectorEmpleado.h"

using namespace std;

class Empresa {
private:
	VectorEmpleado* listaEmpleados;
	VectorProyecto* listaProyectos;
public:
	Empresa(int tamanioEmpleados, int tamanioProyecto) {
		this->listaEmpleados = new VectorEmpleado(tamanioEmpleados);
		this->listaProyectos = new VectorProyecto(tamanioProyecto);
	}
	//1
	void agregarEmpleado(Empleado* nuevoEmpelado) {
		
		if (listaEmpleados->buscarEmpleado(nuevoEmpelado)!= nullptr){
			cout << "Ya existe un empleado con le mismo ci, no se registro a un empleado " << endl;
			return;
		}
		listaEmpleados->agregar(nuevoEmpelado);
	}
	void mostrarEmpleados(){
		listaEmpleados->mostrar();
	}

	void agregarProyecto(Proyecto* nuevoProyecto) {

		if (listaProyectos->buscarProyecto(nuevoProyecto)!=nullptr){
			cout << "Ya existe un proyecto con el mismo codigo, no se registro uno de los proyectos" << endl;
			return;
		}
		listaProyectos->agregar(nuevoProyecto);
	}
	void mostrarProyectos() {
		listaProyectos->mostrar();
	}

	//2
	void totalSalariosEmpleados() {
		cout << "Total de salario de los Empleados: "<<	listaEmpleados->totalSalarios() << endl;
	}
	//3

	void proyectoConMasCosto() {
		cout << "Proyecto con mayor costo" << endl;
		Proyecto* proyectoMayor;
		proyectoMayor = listaProyectos->mayorCosto();
		proyectoMayor->mostrarInformacion();
	}

	~Empresa() {
		delete listaEmpleados;
		delete listaProyectos;
	}
};