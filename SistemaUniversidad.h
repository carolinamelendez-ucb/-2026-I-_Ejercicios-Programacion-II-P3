#pragma once
#include <iostream>
#include <string>
#include "VectorDocentes.h"
#include "VectorCursos.h"
#include "VectorEstudiantes.h"
using namespace std;

class SistemaUniversidad{
private:
	VectorCursos* cursos;
	VectorDocentes* docentes;
	VectorEstudiantes* estudiantes;
public:
	SistemaUniversidad(int tamCursos, int tamDocentes, int tamEstudiantes) {
		this->cursos = new VectorCursos(tamCursos);
		this->docentes = new VectorDocentes(tamDocentes);
		this->estudiantes = new VectorEstudiantes(tamEstudiantes);
	}

	void agregarCurso(Curso* curso) {
		cursos->agregar(curso);
	}
	void agregarDocente(Docente* docente) {
		docentes->agregar(docente);
	}
	void agregarEstudiante(Estudiante* estudiante) {
		estudiantes->agregar(estudiante);
	}

	void asignarDocenteACurso(int ci, int codigo) {
		if (cursos->getCursoPorCodigo(codigo) != nullptr && docentes->getDocentePorCi(ci) != nullptr) {
			cursos->getCursoPorCodigo(codigo)->asignarDocente(docentes->getDocentePorCi(ci));
		}
		
	}

	void agregarEstudiabnteACurso(int ci, int codigo) {
		if (cursos->getCursoPorCodigo(codigo) != nullptr && estudiantes->getEstudiantePorCi(ci) != nullptr) {
			cursos->getCursoPorCodigo(codigo)->agregarEstudiante(estudiantes->getEstudiantePorCi(ci));
		}
	}

	void mostrarEstudianteMasPaga() {
		estudiantes->mostrarEstudianteMasPaga();
	}

	void mostrarDocenteMenosCobra() {
		docentes->mostrarDocenteMenosCobra();
	}

	void mostrarTodo() {
		estudiantes->mostrar();
		docentes->mostrar();
		cursos->mostrar();
	}
};