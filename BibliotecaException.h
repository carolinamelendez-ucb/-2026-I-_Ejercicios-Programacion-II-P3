#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "VectorEstudiante.h"
#include "VectorLibro.h"

using namespace std;

class Biblioteca :public exception
{
private:
	string ci;
	VectorLibro* listaLibros;
	VectorEstudiante* listaEstudiantes;
public:
	Biblioteca(string ci)
	{
		this->listaLibros = listaLibros;
		this->listaEstudiantes = listaEstudiantes;
		this->ci = ci;
		
	}
	void asignarListaLibros(Libro* nuevoLibro,Estudiante* nuevoEstudiante)
	{
		listaLibros->agregar(nuevoLibro);
		
	}
	void asignarListaEstudiantes(Estudiante* nuevoEstudiante)
	{
		listaEstudiantes->agregar(nuevoEstudiante);
	}
	void registrarPrestamoLibro(string ciBuscado, string codigoBuscado)
	{
		Libro* libroEncontrado = listaLibros->BuscarPorCodigo(ciBuscado);
		Estudiante* estudianteEncontrado = listaEstudiantes->BuscarPorCi(ciBuscado);
		{
			if (estudianteEncontrado == nullptr)
			{
				throw "No existe el estudiante";
			}

			if (libroEncontrado == nullptr)
			{
				throw "No existe el libro";
			}
			estudianteEncontrado->asignarLibro(libroEncontrado);
		}
	}
};