#pragma once
#include "Libro.h"
#include <iostream>
#include <string>
using namespace std;

class VectorLibro
{
private:
	Libro** libros;
	int tamanio;
	int indice;

public:
	VectorLibro(int tamanio)
	{
		this->tamanio = tamanio;
		this->indice = 0;
		this->libros = new Libro * [tamanio];
	}

	bool agregar(Libro* nuevoLibro)
	{
		for (int i = 0; i < indice; i++)
		{
			if (libros[i]->getCodigo() == nuevoLibro->getCodigo())
			{
				return false;
			}
		}
		if (indice < tamanio)
		{
			this->libros[indice] = nuevoLibro;
			indice++;
			return true;
		}
		return false;
	}

	Libro* buscarPorCodigo(string codigoBuscado)
	{
		for (int i = 0; i < indice; i++)
		{
			if (libros[i]->getCodigo() == codigoBuscado)
			{
				return libros[i];
			}
		}
		return nullptr;
	}

	

};