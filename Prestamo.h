#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Estudiante.h"
#include "Libro.h"

class Prestamo{
	private:
	int ciEstudiante;
	int codigoLibro;
	bool estado; //true = activo
	Estudiante* estudianteAsignado;
	Libro* libroAsignado;
	public:

	Prestamo (int ciEstudiante, int codigoLibro, bool estado){
		this->ciEstudiante = ciEstudiante;
		this->codigoLibro = codigoLibro;
		this->estado = estado;
		this->estudianteAsignado = nullptr;
		this->libroAsignado = nullptr;
	}

	void asignarEstudianteYLibro (Estudiante* estudianteAsignado, Libro* libroAsignado){
		this->estudianteAsignado = estudianteAsignado;
		this->libroAsignado = libroAsignado;

		if(estado == true){
			estudianteAsignado->incrementarPrestamos ();
			libroAsignado->actualizarEstado ();
		}
	}

	void mostrar (){
		cout << "CI del estudiante: " << ciEstudiante << endl;
		cout << "Codigo del libro: " << codigoLibro << endl;
		cout << "Estado del prestamo: " << endl;
		if(estado == true){
			cout << "Activo" << endl;
		}
		else{
			cout << "Inactivo" << endl;
		}
	}

	int getCiEstudiante (){
		return ciEstudiante;
	}

	int getCodigoLibro (){
		return codigoLibro;
	}

	bool getEstado (){
		return estado;
	}

	void devolverLibro (){
		if(estado == true){
			estado = false;
			if(libroAsignado != nullptr){
				libroAsignado->actualizarEstado ();
			}
			if(estudianteAsignado != nullptr){
				estudianteAsignado->disminuirPrestamos ();
			}
		}
	}
};