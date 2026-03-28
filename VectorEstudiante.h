#pragma once
#include "Estudiante.h"
#include <iostream>
#include <string>
using namespace std;

class VectorEstudiante
{
private:
	int indice;
	int tamanio;
	Estudiante** estudiantes;

public:

	VectorEstudiante(int tamanio)
	{
		this->indice = 0;
		this->tamanio = tamanio;
		this->estudiantes = new Estudiante * [tamanio];
	}

	bool agregar(Estudiante* nuevoEstudiante)
	{
		for (int i = 0; i < indice; i++)
		{
			if (estudiantes[i]->getCi() == nuevoEstudiante->getCi())
			{
				return false;
			}
		}
		if (indice < tamanio)
		{
			estudiantes[indice] = nuevoEstudiante;
			indice++;
			return true;
		}
		return false;

	}

	Estudiante* busquedaPorCI(string ciBuscado)
	{
		for (int i = 0; i < indice; i++)
		{
			if (estudiantes[i]->getCi() == ciBuscado)
			{
				return estudiantes[i];
			}
		}
		return nullptr;
	}
	
	void mostrarEstudiantesCon5PrestamosActivos()
	{
		for (int i = 0; i < indice; i++)
		{
			if (estudiantes[i]->getPrestamosActivos() == 5)
			{
				cout << " El estudiante "<< estudiantes[i]->getNombre()<<" tiene 5 libros prestados Activos ..." << estudiantes[i]->getPrestamosActivos()<<endl;
			}
		}
		cout << "Ningun estudiante tiene 5 prestamos ... " << endl;
	}


};