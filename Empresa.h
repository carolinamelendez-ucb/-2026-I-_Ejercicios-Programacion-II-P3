#pragma once
#include <iostream>
#include<string>
#include"vectores.h"
using namespace std;
class Empresa {
private:
	VectorEmpleado empleados;
	VectorProyectos Proyectos;
public:
	Empresa(int tamE, int tamP) 
	:	empleados(tamE), Proyectos(tamP)
	{}
	void agregarEmpleado(Empleado* e) {
		empleados.agregar(e);
	}
	void agregarProyecto(Proyecto* p) {
		Proyectos.agregar(p);
	}
	void mostarTodo() {
		cout << "\n===== Empleados=====\n" << endl;
		empleados.mostrar();
		cout << "\n===== Proyectos=====\n" << endl;
		Proyectos.mostrar();
	}
	void totalSalarios() {
		cout << "Total salarios: " << empleados.totalsalarios() << endl;
	}
	void proyectoMayor() {
		Proyecto* p = Proyectos.mayorCosto();
		if (p != nullptr) {
			cout << "el proyecto Mayor costo:";
			p->mostrar();
		}
	}
};