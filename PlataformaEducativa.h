#pragma once
#include <iostream>
#include <string>
#include "VectorCurso.h"
#include "VectorInstructor.h"
using namespace std;

class PlataformaEducativa {
private:
	VectorCurso* listaCurso;
	VectorInstructor* listaInstructor;
public:
	PlataformaEducativa(int cantidadCursos, int cantidadInstructores) {
		listaCurso = new VectorCurso(cantidadCursos);
		listaInstructor = new VectorInstructor(cantidadInstructores);
	}
	//1
	void registrarInstructores(Instructor* nuevoInstructor) {
		listaInstructor->agregar(nuevoInstructor);
	}
	void mostrarInstrcutores() {
		listaInstructor->ordenarPorCurso();
		listaInstructor->mostrar();
	}
	//2
	void registrarCursos(int id, string nombre, int maxEstudiantes) {
		Curso* cursoTemp = new Curso(id, nombre, maxEstudiantes);

		Instructor* instructorAsignado = listaInstructor->AsignarInstructorMenorCantidad();
		if (instructorAsignado  != nullptr){
			cursoTemp->setInstrucor(instructorAsignado);
			instructorAsignado->EstaOcupado();
		}
		
		listaCurso->agregar(cursoTemp);
	}
	void mostrarCursos() {
		listaCurso->mostrar();
	}
	//3
	void registrarEstudiantes(int idCurso, string nombre, string correo) {
		Estudiante* auxEstudiante = new Estudiante(nombre, correo);
		Curso* cursoEncontrado = listaCurso->getCurso(idCurso);

		if (cursoEncontrado != nullptr) {
			cursoEncontrado->agregarEstudiantes(auxEstudiante);
		} else{
			cout << "Curso no encontrado" << endl;
			delete auxEstudiante; //como no hay curso donde registrar no se tma en cuenta al usaurio creado
		}
			
	}
	//4
	void finalizarCurso(int idCurso) {
    Curso* curso = listaCurso->getCurso(idCurso);
    if (curso != nullptr && curso->getInstructor() != nullptr) {
        curso->getInstructor()->AumentarCantidadCursoR();
        curso->getInstructor()->estaLibre();
    }
}
	// 5
	void InstructorMayorCantidadCursos() {
		listaInstructor->mayorCantidad()->mostrar();
	}
	~PlataformaEducativa() {
		delete listaCurso;
		delete listaInstructor;
	}
	

};