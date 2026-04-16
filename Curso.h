#pragma once
#include "VectorEstudiantes.h"
#include "Docente.h"

class Curso {
private:
	Docente* docenteAsignado;
	VectorEstudiantes* listaEstudiantes;
	string nombre;
	int codigo;
public:

	Curso(const string& nombre, int codigo , int tamanio)
		: nombre(nombre), codigo(codigo)
	{
		this->docenteAsignado = nullptr;
		this->listaEstudiantes = new VectorEstudiantes(tamanio);
	}

	int getCodigo() {
		return codigo;
	}

	void agregarDocente(Docente* docenteAsignado) {
		this->docenteAsignado = docenteAsignado;
	}
	void agregarEstudianteACurso(Estudiante* nuevoEstudiate) {
		listaEstudiantes->agregarEstudiante(nuevoEstudiate);
	}
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Codigo: " << codigo << endl;
		if (docenteAsignado != nullptr) {
			docenteAsignado->mostrar();
		}
		listaEstudiantes->mostrar();
		cout << endl;
	}
};