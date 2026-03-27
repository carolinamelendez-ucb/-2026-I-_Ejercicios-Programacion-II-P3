#pragma once
#include <iostream>
#include <string>
#include "VectorEstudiante.h"
#include "Instructor.h"

using namespace std;

class Curso {
private:
	int id;
	string nombre;
	int maxEstudiantes;
	VectorEstudiante* listaEstudiantes;
	Instructor* instructor;
public:

	Curso() = default;

	Curso(int id, const string& nombre, int maxEstudiantes)
		: id(id), nombre(nombre), maxEstudiantes(maxEstudiantes)
	{
		this->instructor = nullptr;
		this->listaEstudiantes = new VectorEstudiante(maxEstudiantes);
	}
	int getId()
	{
		return id;
	}
	Instructor* getInstructor() {
		return instructor;
	}
	void agregarEstudiantes(Estudiante * nuevoEstudiante) {
		this->listaEstudiantes->agregar(nuevoEstudiante);
	}
	void setInstrucor(Instructor* nuvIstructor){
		this->instructor = nuvIstructor;
	}
	void mostrar() {
		cout << "Id del curso: "<<id << endl;
		cout << "Nombre del curso: " << nombre << endl;
		cout << "Maximo de Estudiantes: " << maxEstudiantes << endl;
		cout << "Instructor asigando: " << endl;
		if (instructor != nullptr) {
			instructor->mostrar();
		}
		else {
			cout << "No tiene instructor asignado" << endl;
		}
		cout << "Lista de estduiantes del Curso: " << endl;
		listaEstudiantes->mostrar();
	}


	~Curso() {
		delete listaEstudiantes;
	}

	
};
