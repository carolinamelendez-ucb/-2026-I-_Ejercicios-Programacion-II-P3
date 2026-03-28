#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "VectorEstudiantes.h"
#include "Intructores.h"

class Curso {
private:	
	int id;
	string nombre;
	int tamanio;
	VectorEstudiantes* estudiantes;
	Instructor* instructor;
public:
	Curso(int id, string nombre, int tamanio) {
		this->id = id;
		this->nombre = nombre;
		this->tamanio = tamanio;
		this->estudiantes = new VectorEstudiantes(tamanio);
		this->instructor = nullptr;
	}

	Curso(int id, string nombre, int tamanio, Instructor* instructorAsignado) {
		this->id = id;
		this->nombre = nombre;
		this->tamanio = tamanio;
		this->estudiantes = new VectorEstudiantes(tamanio);
		this->instructor = instructorAsignado;
	}
	
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Id: " << id << endl;
		cout << "Cantidad maxima de estudiantes " << tamanio << endl;
		cout << "Estudiantes Inscritos: " << endl;
		estudiantes->mostrar();
		if (instructor != nullptr) {
			cout << "Instructor Asignado: " << instructor->getNombre() << endl;
		}
		cout << endl;
	}

	void asignarInstructor(Instructor* instructorAsignado) {
		this->instructor = instructorAsignado;
		instructorAsignado->actualizarEstado();
	}

	void agregarEstudiante(Estudiante* nuevoEstudiante) {
		estudiantes->agregarEstudiante(nuevoEstudiante);
	}

	void finalizarCurso() {
		instructor->actualizarEstado();
	}

	int getId() {
		return id;
	}
};