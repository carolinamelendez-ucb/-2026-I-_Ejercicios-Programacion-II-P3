#pragma once
#include "Estudiante.h"
#include "Libro.h"
#include <iostream>
#include <string>

using namespace std;
//en esta clase asumimos que se esta prestando el libro y estudiante incrementa su cantidadMax. 
class Prestamo
{
private:
	Estudiante* estudiante;
	Libro* libro;
	bool estaActivo; // el prestamo del libro y la persona true or false
public:

	Prestamo(Estudiante* estudiante, Libro* libro)
	{
		this->estudiante = estudiante;
		this->libro = libro;
		this->estaActivo = true;
		libro->cambiarEstadoDeDisponible(false);
		estudiante->incrementarPrestamos();
	}

	Estudiante* getEstudiante()
	{
		return estudiante;
	}

	Libro* getLibro()
	{
		return libro;
	}
	bool getEstaActivo()
	{
		return estaActivo;
	}

	void devolver()
	{
		estaActivo = false;
		libro->cambiarEstadoDeDisponible(true);
		estudiante->decrementarPrestamos();
	}

	void mostrar()
	{
		cout << " Estudiante  " << estudiante->getCi() << endl;
		cout << " LIBRO  " << libro->getCodigo() << endl;
		cout << " Activo  " << (estaActivo ? "Si" : "No") << endl;
	}



};