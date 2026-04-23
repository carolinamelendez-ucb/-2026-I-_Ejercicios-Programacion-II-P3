#pragma once

#include <iostream>
#include <string>
#include "VectorEstudiantes.h"
#include "VectorLibros.h"
using namespace std;

class Biblioteca {
private:
	string nombre;
	VectorEstudiantes * listaEstudiantes;
	VectorLibros * listaLibros;
public:
	Biblioteca(string nombre, int tamanioEstudiantes, int tamanioLibros) {
		this->nombre = nombre;
		this->listaLibros = new VectorLibros(tamanioLibros);
		this->listaEstudiantes = new VectorEstudiantes(tamanioEstudiantes);
	}
	void agregarEstudiantes(Estudiante * nuevoEstudiante) {
		listaEstudiantes->agregar(nuevoEstudiante);
	}
	void agregarLibros(Libro* nuevoLibro) {
		listaLibros->agregar(nuevoLibro);
	}

	void prestamo(int ci, string codigo) {
		Estudiante* estudianteEncontrado = listaEstudiantes->buscarCi(ci);
		Libro* libroEncontrado = listaLibros->buscarId(codigo);


	}
};