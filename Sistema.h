#pragma once
#include "VectorCursos.h"
#include "VectorDocentes.h"

class Sistema {
private:
	VectorEstudiantes* listaEstudiantes;
	VectorDocentes* listaDocentes;
	VectorCursos* listaCursos;
public:
	Sistema(int maxEstudiantes, int maxDocentes, int maxCursos) {
		this->listaCursos = new VectorCursos(maxCursos);
		this->listaDocentes = new VectorDocentes(maxDocentes);
		this->listaEstudiantes = new VectorEstudiantes(maxEstudiantes);
	}
	void registrarEstudiante(Estudiante* newEstudiante) {
		int ciNuevoEstudiante = newEstudiante->getCI();
		Estudiante* estudianteCiDuplicado = listaEstudiantes->buscarCi(ciNuevoEstudiante);
		if (estudianteCiDuplicado == nullptr) {
			listaEstudiantes->agregar(newEstudiante);
		}
		else {
			cout << "El CI: " << ciNuevoEstudiante << " esta duplicado" << endl;
		}
	}
	void registrarDocente(Docente* newDocente) {
		int ciNuevoDocente = newDocente->getCI();
		Docente* docenteCiDuplicado = listaDocentes->buscarCi(ciNuevoDocente);
		if (docenteCiDuplicado == nullptr) {
			listaDocentes->agregar(newDocente);
		}
		else {
			cout << "El CI: " << ciNuevoDocente << " esta duplicado" << endl;
		}
	}
	void registrarCurso(Curso* newCurso) {
		int codigoNuevoCurso = newCurso->getCodigo();
		Curso* cursoCodigoDuplicado = listaCursos->buscarCodigo(codigoNuevoCurso);
		if (cursoCodigoDuplicado == nullptr) {
			listaCursos->agregar(newCurso);
		}
		else {
			cout << "El Codigo: " << codigoNuevoCurso << " esta duplicado" << endl;
		}
	}
	void asignarDocenteCurso(int ci, int codigo) {
		Docente* docenteBuscado = listaDocentes->buscarCi(ci);
		Curso* cursoBuscado = listaCursos->buscarCodigo(codigo);
		if (docenteBuscado == nullptr) {
			cout << "Docente no existe" << endl;
		}
		if (cursoBuscado == nullptr) {
			cout << "Curso no existe" << endl;
		}
		if (docenteBuscado->estaAprobado() == false) {
			cout << "Docente no aprobado" << endl;
		}
		cursoBuscado->asignarDocente(docenteBuscado);
		cout << "Docente asignado correctamente" << endl;
	}
	void asignarEstudianteCurso(int ci, int codigo) {
		Estudiante* EstudianteBuscado = listaEstudiantes->buscarCi(ci);
		Curso* cursoBuscado = listaCursos->buscarCodigo(codigo);
		if (EstudianteBuscado == nullptr) {
			cout << "Estudiante no existe" << endl;
		}
		if (cursoBuscado == nullptr) {
			cout << "Curso no existe" << endl;
		}
		if (EstudianteBuscado->pagoRealizado() == false) {
			cout << "Estudiante no pago matricula" << endl;
			return;
		}
		if (cursoBuscado->agregarEstudiante(EstudianteBuscado)) {
			cout << "Estudiante inscrito" << endl;
		}
	}
	void mostrarEstudiantes() {
		cout << "==== ESTUDIANTES ====" << endl;
		for (int i = 0; i < listaEstudiantes->getIndice(); i++) {
			listaEstudiantes->get(i)->mostrar();
			cout << "Pago: "
				<< listaEstudiantes->get(i)->calcularPago() << endl;
		}
	}
	void mostrarDocentes() {
		cout << "==== DOCENTES ====" << endl;
		for (int i = 0; i < listaDocentes->getIndice(); i++) {
			listaDocentes->get(i)->mostrar();
			cout << "Salario: "
				<< listaDocentes->get(i)->calcularSalario() << endl;
		}
	}
	void totalRecaudado() {
		float total = 0;
		for (int i = 0; i < listaEstudiantes->getIndice(); i++) {
			total = total + listaEstudiantes->get(i)->calcularPago();
		}
		cout << "==== TOTAL RECAUDADO ====" << endl; 
		cout << total << endl;
	}
	void estudianteMayorPago() {
		float max = 0;
		Estudiante* mayor = nullptr;
		for (int i = 0; i < listaEstudiantes->getIndice(); i++) {
			float pago = listaEstudiantes->get(i)->calcularPago();
			if (pago > max) {
				max = pago;
				mayor = listaEstudiantes->get(i);
			}
		}
		if (mayor != nullptr) {
			cout << "==== ESTUDIANTE QUE MAS PAGA ====" << endl;
			mayor->mostrar();
			cout << "Pago: " << max << endl;
		}
	}
	void docenteMenorSalario() {
		float min = 999999;
		Docente* menor = nullptr;
		for (int i = 0; i < listaDocentes->getIndice(); i++) {
			float salario = listaDocentes->get(i)->calcularSalario();
			if (salario < min) {
				min = salario;
				menor = listaDocentes->get(i);
			}
		}
		if (menor != nullptr) {
			cout << "==== DOCENTE CON MENOR SALARIO ====" << endl;
			menor->mostrar();
			cout << "Salario: " << min << endl;
		}
	}
};