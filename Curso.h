#pragma once
#include <iostream>
#include <string>
#include "Docente.h"
#include "Estudiante.h"
using namespace std;

class Curso {
protected:
	string nombre;
	int codigo;
	Docente* docente;
	Estudiante** Estudiantes;
	int maxEstudiantes;
public:
	Curso(const string& nombre, int codigo, Docente* docente, Estudiante** listaEstudiantes, int maxEstudiantes)
		: nombre(nombre), codigo(codigo), docente(docente), Estudiantes(listaEstudiantes), maxEstudiantes(maxEstudiantes)
	{}

	bool asignarDoncente(Docente* nvoDoc) {
		
	}





	void mostrar() {
		cout << "Curso:"<<nombre << endl;
		cout << "Codigo:"<<codigo << endl;
		cout << "Docente:"<<nombre << endl;
	}


	int getCodigo() {
		return codigo;
	}






	~Curso() {}
};