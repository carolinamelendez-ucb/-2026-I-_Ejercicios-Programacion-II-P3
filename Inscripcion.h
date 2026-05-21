#pragma once
#include "Estudiante.h"
#include "Curso.h"

class Inscripcion {
private:
	string fechaInscripcion;
	string estado;
	Curso* curso;
	Estudiante* estudiante;
public:
	Inscripcion(const string& fechaInscripcion, const string& estado)
		: fechaInscripcion(fechaInscripcion), estado(estado), curso(nullptr), estudiante(nullptr)
	{
	}
	void mostrar() {
		cout << "Fecha inscripcion: " << fechaInscripcion << endl;
		cout << "Estado: " << estado << endl;
		cout << "Curso-> " << endl;
		curso->mostrar();
	}

	Estudiante* getEstudiante() {
		return estudiante;
	}
	Curso* getCurso() {
		return curso;
	}
	string getEstado() {
		return estado;
	}
	void cancelada() {
		estado = "CANCELADA";  //no corresponde doble igual, no se compara se asigna
		estudiante->reducirContInscricionesActiva();
	}
	static bool compararInscripcion(int ci, string codigo, Inscripcion* i) {
		return ci == i->getEstudiante()->getCI() && codigo == i->getCurso()->getCodigo();
	}
	void asignarCurso(Curso* nuevoCurso) {
		curso = nuevoCurso;
	}
	void asignarEstudiante(Estudiante* nuevoEstudiante) {
		estudiante = nuevoEstudiante;
		nuevoEstudiante->aumentarCantInscrionesActivas();
	}
	static bool compararEstado(int ci, Inscripcion* i) {
		return ci == i->getEstudiante()->getCI() && "ACTIVA" == i->estado;  
	}
};