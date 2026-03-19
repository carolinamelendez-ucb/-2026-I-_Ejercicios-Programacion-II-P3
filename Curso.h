#pragma once
#include <iostream>
#include "Instructor.h"
#include "VectorEstudiantes.h"
using namespace std;

class Curso {
private:
	int id;
	string nombre;
	int maxEstudiantes;
	VectorEstudiantes* estudiantes;
	Instructor* instructor;
public:
	Curso(int id, string nombre, int maxEstudiantes) {
		this->id = id;
		this->nombre = nombre;
		this->maxEstudiantes = maxEstudiantes;
		this->estudiantes = new VectorEstudiantes(maxEstudiantes);
		this->instructor = nullptr;
	}

	
	void agregarEstudiante(Estudiante* nuevoEstudiante) {
		this->estudiantes->agregar(nuevoEstudiante);
	}

	int getId() { return id; }
	string getNombre() { return nombre; }

	void asignarInstructor(Instructor* instructorAsignado) {
		this->instructor = instructorAsignado;
	}

	
	void finalizar() {
		if (instructor != nullptr) {
			cout << endl << "Curso " << nombre << " finalizado." << endl;
			cout << "El instructor " << instructor->getNombre()
				 << " queda libre y suma un curso realizado." << endl;
			instructor->liberarInstructor();
			instructor = nullptr;
		}
		else {
			cout << "El curso " << nombre << " no tiene instructor asignado." << endl;
		}
	}
};