#pragma once

#include "Docente.h" 
#include "VectorEstudiantes.h"

class Curso {
private:
	string codigo;
	Docente* docenteAsignado;
	VectorEstudiantes* listaEstudiantes;

public:
	Curso(string codigo, int maxCupoEstudiantes) {
		this->codigo = codigo;
		docenteAsignado = nullptr;
		listaEstudiantes = new VectorEstudiantes(maxCupoEstudiantes);
	}
	string getCodigo() {
		return codigo;
	}

	void asignarDocente(Docente * nuevoDocente) {
		docenteAsignado = nuevoDocente;
	}
	void asignarEstudiante(Estudiante* nuevoEstudiante) {
		listaEstudiantes->agregar(nuevoEstudiante);
	}
	void mostrar() {
		cout << "Codigo: " << codigo << endl;
		if (docenteAsignado != nullptr) {
			cout << "Docente asignado:" << endl;
			docenteAsignado->mostrar();
		}
		cout << "Estudiantes:" << endl;
		listaEstudiantes->mostrar();
	}

	~Curso() {
		delete listaEstudiantes;
	}
};