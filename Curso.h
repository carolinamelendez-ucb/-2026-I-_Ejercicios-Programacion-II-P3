#pragma once
#include <iostream>
#include <string>
#include "Docente.h"
#include "VectorEstudiantes.h"

using namespace std;

class Curso
{
private:
	VectorEstudiantes* listaEstudiantes;
	Docente* docenteAsignado;
	int codigo;
public:
	Curso(int codigo, int tamanioEstudiante)
	{
		this->listaEstudiantes = new VectorEstudiantes(tamanioEstudiante);
		this->docenteAsignado = nullptr;
		this->codigo = codigo;
	}
	void asignarDocente(Docente* nuevoDocente)
	{
		docenteAsignado = nuevoDocente;
	}
	void asignarEstudiantes(Estudiante* nuevoEstudiante)
	{
		listaEstudiantes->agregar(nuevoEstudiante);
	}
	void mostrar()
	{
		cout << "Codigo: " << codigo << endl;
		cout << "El docente asiganado es: " << endl;
		if (docenteAsignado != nullptr)
		{
			docenteAsignado->mostrar();
		}
		else
		{
			cout << "no hay docente asiganado" << endl;
		}
		cout << "estudiantes Inscritos: " << endl;
		listaEstudiantes->mostrar();
		cout << endl;
		
	}
	int getCodigo()
	{
		return codigo;
	}
	//~Curso()
	//{
	//	delete listaEstudiantes;
	//}
};