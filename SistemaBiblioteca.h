#pragma once
#include <iostream>
#include <string>
#include "VectorEstudiante.h"
#include "VectorLibro.h"
#include "VectorPrestamo.h"

using namespace std;

class SistemaBibliotecas
{
private:

	VectorLibro* listaDeLibros;
	VectorEstudiante* listaDeEstudiantes;
	VectorPrestamo* listaDePrestamos;

public:

	SistemaBibliotecas(int tamLibos, int tamEstudiantes, int tamPrestamos)
	{
		this->listaDeEstudiantes = new VectorEstudiante(tamEstudiantes);
		this->listaDeLibros = new VectorLibro(tamLibos);
		this->listaDePrestamos = new VectorPrestamo(tamPrestamos);
	}

	void registrarEstudiante(string ci, string nombre)
	{
		Estudiante* nuevoEstudiante = new Estudiante(ci, nombre);
		if (!listaDeEstudiantes->agregar(nuevoEstudiante))
		{
			cout << " Ci duplicado " << endl;
		}
	}

	void registrarLibro(string codigo, string titulo)
	{
		Libro* nuevoLibro = new Libro(codigo, titulo);
		if (!listaDeLibros->agregar(nuevoLibro))
		{
			cout << "Codigo duplicado " << endl;
		}
	}

	void prestarLibro(string ci, string codigo)
	{
		Estudiante* estudianteBuscado = listaDeEstudiantes->busquedaPorCI(ci);
		Libro* libroBuscado = listaDeLibros->buscarPorCodigo(codigo);

		if (estudianteBuscado == nullptr || libroBuscado == nullptr)
		{
			cout << "LIBRO no EXISTE" << endl;
			return;
		}

		if (!libroBuscado->getEstaDispobible())
		{
			cout << "lIBRO OCUPADO" << endl;
			return;
		}

		if (estudianteBuscado->getPrestamosActivos()>=5)
		{
			cout << "Limite Alcanzado " << endl;
			return;
		}
		Prestamo* nuevoPrestamo = new Prestamo(estudianteBuscado, libroBuscado);
		listaDePrestamos->agregar(nuevoPrestamo);
	}

	void devolverLibro(string ci, string codigo)
	{
		Estudiante* estudianteBuscado = listaDeEstudiantes->busquedaPorCI(ci);
		Libro* libroBuscado = listaDeLibros->buscarPorCodigo(codigo);

		Prestamo* pretamoBuscado = listaDePrestamos->buscarPrestamo(estudianteBuscado, libroBuscado);

		if (pretamoBuscado != nullptr)
		{
			pretamoBuscado->devolver();
		}
	}

	void mostrarPrestamos()
	{
		listaDePrestamos->mostrar();
	}

	void mostrarEstudiantesCon5Libros()
	{
		listaDeEstudiantes->mostrarEstudiantesCon5PrestamosActivos();
	}

};