#pragma once
#include <iostream>
#include "VectorCursos.h"
#include "VectorInstructores.h"

using namespace std;

class PlataformaEducativa {
private:
	VectorCursos* cursos;
	VectorInstructores* instructores;
public:
	PlataformaEducativa(int cantCurso, int cantInstructor) {
		this->cursos = new VectorCursos(cantCurso);
		this->instructores = new VectorInstructores(cantInstructor);
	}

	void agregarCurso(Curso* nuevoCurso) {
		cursos->agregar(nuevoCurso);
	}

	void agregarInstructor(Instructor* nuevoInstructor) {
		instructores->agregar(nuevoInstructor);
	}

	
	void asignarInstructores() {
		for (int i = 0; i < cursos->getIndice(); i++) {
			cursos->asignarInstructor(instructores->buscarLibreConMenosCursos(), i);
		}
	}

	
	void mostrarInstructoresOrdenados() {
		instructores->mostrarOrdenadosPorCursos();
	}

	
	void registrarEstudiante(int idCurso, Estudiante* estudiante) {
		Curso* curso = cursos->buscarPorId(idCurso);
		if (curso != nullptr) {
			curso->agregarEstudiante(estudiante);
			cout << endl << "Estudiante registrado en el curso " << curso->getNombre() << endl;
		}
		else {
			cout << endl << "No se encontro un curso con ID " << idCurso << endl;
		}
	}

	
	void finalizarCurso(int idCurso) {
		cursos->finalizarCurso(idCurso);
	}

	
	void mostrarInstructorConMasCursos() {
		instructores->mostrarConMasCursos();
	}
};