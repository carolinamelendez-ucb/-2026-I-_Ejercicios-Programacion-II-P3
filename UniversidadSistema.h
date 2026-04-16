#pragma once
#include "VectorCursos.h"
#include "VectorDocentes.h"

class UniversidadSistema {
private:
	VectorEstudiantes* listaEstudiantes;
	VectorDocentes* listaDocentes;
	VectorCursos* listaCursos;
public:
	UniversidadSistema(int maxEstudiantes, int maxDocentes, int maxCursos) {
		this->listaCursos = new VectorCursos(maxCursos);
		this->listaDocentes = new VectorDocentes(maxDocentes);
		this->listaEstudiantes = new VectorEstudiantes(maxEstudiantes);
	}

	void registrarEstudiante(Estudiante* nuevoEstudianteInscrito) {
		string ciNuevoEstudiante = nuevoEstudianteInscrito->getCi();
		Estudiante* estudianteCiDuplicado = this->listaEstudiantes->buscarPorCi(ciNuevoEstudiante);


		if (estudianteCiDuplicado == nullptr) {
			this->listaEstudiantes->agregar(nuevoEstudianteInscrito);
		}
		else {
			cout << "El ci: " << ciNuevoEstudiante << " esta duplicado" << endl;
		}
	}

	void registrarDocente(Docente* nuevoDocente) {
		string ciNuevoDocente = nuevoDocente->getCi();
		Docente* docenteCiDuplicado = this->listaDocentes->buscarPorCi(ciNuevoDocente);


		if (docenteCiDuplicado == nullptr) {
			this->listaDocentes->agregar(nuevoDocente);
		}
		else {
			cout << "El ci: " << ciNuevoDocente << " esta duplicado" << endl;
		}
	}

	void registrarCurso(Curso* nuevoCurso) {
		string codigoNuevoCurso = nuevoCurso->getCodigo();
		Curso* cursoCodigoDuplicado = this->listaCursos->buscarPorCodigo(codigoNuevoCurso);


		if (cursoCodigoDuplicado == nullptr) {
			this->listaCursos->agregar(nuevoCurso);
		}
		else {
			cout << "El codigo: " << codigoNuevoCurso << " esta duplicado" << endl;
		}
	}
	

	

	void asignarDocenteACurso(string ciDocente, string codigoCurso) {

		Docente* docenteBuscado = this->listaDocentes->buscarPorCi(ciDocente);

		if (docenteBuscado == nullptr) {
			cout << "Docente no existe" << endl;
			return;
		}
		Curso* cursoBuscado = this->listaCursos->buscarPorCodigo(codigoCurso);
		if (cursoBuscado == nullptr) {
			cout << "Curso no existe" << endl;
			return;
		}
		if (docenteBuscado->aproboEntrevista()) {
			cursoBuscado->asignarDocente(docenteBuscado);
		}
	}

	void asignarEstudianteACurso(string ciEstudiante, string codigoCurso) {

		Estudiante *estudianteBuscado = this->listaEstudiantes->buscarPorCi(ciEstudiante);

		if (estudianteBuscado == nullptr) {
			cout << "Estudiante no existe" << endl;
			return;
		}
		Curso* cursoBuscado = this->listaCursos->buscarPorCodigo(codigoCurso);
		if (cursoBuscado == nullptr) {
			cout << "Curso no existe" << endl;
			return;
		}
		if (estudianteBuscado->realizoPagoMatricula()) {
			cursoBuscado->asignarEstudiante(estudianteBuscado);
		}
	}

	void mostrarListaEstudiantes() {
		cout << "LISTA DE ESTUDIANTES" << endl;
		listaEstudiantes->mostrar();
	}

	void mostrarListaDocentes() {
		cout << "LISTA DE DOCENTES" << endl;
		listaDocentes->mostrar();
	}
	void mostrarEstudianteQueMasPaga() {
		Estudiante* mayor = listaEstudiantes->estudianteQueMasPaga();

		if (mayor != nullptr) {
			cout << "Estudinate que mas PAGA:" << endl;
			mayor->mostrar();
		}
		else {
			cout << "No hay estudiantes registrados" << endl;
		}
	}

	void mostrarDocenteQueMenosGana() {
		Docente* menor = listaDocentes->docenteQueMenosGana();

		if (menor != nullptr) {
			cout << "Docente que menos GANA:" << endl;
			menor->mostrar();
		}
		else {
			cout << "No hay docentes registrados" << endl;
		}
	}

	~UniversidadSistema() {
		delete listaEstudiantes;
		delete listaDocentes;
		delete listaCursos;
	}
};