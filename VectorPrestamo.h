#pragma once
#include <iostream>
#include <string>
#include "Prestamo.h"
using namespace std;

class VectorPrestamo
{
private:
	Prestamo** prestamos;
	int tamanio;
	int indice;

public:

	VectorPrestamo(int tamanio)
	{
		this->indice = 0;
		this->tamanio = tamanio;
		this->prestamos = new Prestamo * [tamanio];
	}
	void agregar(Prestamo* prestamoNuevo)
	{
		if (indice < tamanio)
		{
			this->prestamos[indice] = prestamoNuevo;
			indice++;
		}
	}

	Prestamo* buscarPrestamo(Estudiante* estudiante, Libro* libro)
	{
		for (int i = 0; i < indice; i++)
		{
			if (prestamos[i]->getEstudiante() == estudiante && prestamos[i]->getLibro() == libro && prestamos[i]->getEstaActivo())
			{
				return prestamos[i];
			}
		}
		return nullptr;	
	}
	void mostrar()
	{
		for (int i = 0; i < indice; i++)
		{
			prestamos[i]->mostrar();
		}
	}
};