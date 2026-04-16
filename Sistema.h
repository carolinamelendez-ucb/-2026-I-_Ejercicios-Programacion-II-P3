#pragma once
#include <iostream>
#include <string>
#include "ListaEstudiantes.h"
#include "ListaDoc.h"
#include "ListaCursos.h"
using namespace std;

class Sistema {
private:
	ListaCurso* cursos;
	ListaDoc* docentes;
	ListaEstu* estudiantes;
public:
	Sistema(int cantDocentes, int cantEstudiantes, int cantidadCursos) {
		this->cursos = new ListaCurso(cantidadCursos);
		this->docentes = new ListaDoc(cantDocentes);
		this->estudiantes = new ListaEstu(cantEstudiantes);
	}

	void agregarDocente(Docente* nvoDocente) {
		docentes->agregarDocente(nvoDocente);
	}

	void agregarEstudiante(Estudiante* nvoEstudiante) {
		estudiantes->agregarEs(nvoEstudiante);
	}

	void agregarCursos(Curso* nvoCurso) {
		cursos->agregarCurso(nvoCurso);
	}

	void mostrarAlumnos() {
		estudiantes->mostrar();
	}

	void mostraDocentes() {
		docentes->mostrar();
	}

	void mostrarCurso() {
		cursos->mostrar();
	}

	void asignarDocente_Curso(int ciDocente, Curso* nvoCurso) {

		Docente* docenteEncontrado = docentes->buscarCi(ciDocente);

		if (docenteEncontrado == nullptr) {
			cout << "No se entontro al docente de ci:" << ciDocente << endl;
		}
		else {
			
		}

	}


	void verificarCiDuplicadoEstudiantes() {
		estudiantes->verificarDuplicados();
	}
	void verificarCiDuplicadoEstudiantes() {
		docentes->verificarDuplicados();
	}
	void verificarCiDuplicadoEstudiantes() {
		cursos->verificarDuplicados();
	}


	~Sistema(){}

};