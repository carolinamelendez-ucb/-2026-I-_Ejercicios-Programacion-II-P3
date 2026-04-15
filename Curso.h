#pragma once
#include <iostream>
#include <string>
#include "Docente.h"
#include "VectorEstudiantes.h"
using namespace std;

class Curso {
private:
	Docente* docenteAsignado;
	int cantidadMaximaEstudiantes;
	VectorEstudiantes* listaEstudiantes;
	int codigo;
public:
	Curso(int codigo, int cantidad) {
		this->codigo = codigo;
		this->cantidadMaximaEstudiantes = cantidad;
		listaEstudiantes = new VectorEstudiantes(cantidad);
		this->docenteAsignado = nullptr;
	}

	void asignarDocente(Docente* docente) {
		if (docente->getFinalizoSeleccion()) {
			docente->aumentarCantidadCursos();
			docente->comprobarCantidadCursosMedioTiempo();
			docenteAsignado = docente;
		}
		else {
			cout << "El docente no finalizo la seleccion" << endl;
		}
	}

	void agregarEstudiante(Estudiante* estudiante) {
		if (estudiante->getPagoMatricula()) {
			estudiante->aumentarCantidadCursos();
			listaEstudiantes->agregar(estudiante);
		}
		else {
			cout << "El estudiante no pago su matricula" << endl;
		}
	}

	void mostrar() {
		cout << "Codigo: " << codigo << endl;
		if (docenteAsignado == nullptr) {
			cout << "Aun no hay docente asignado" << endl;
		}
		else {
			docenteAsignado->mostrar();
		}
		listaEstudiantes->mostrar();
	}

	int getCodigo() { return codigo; }
};