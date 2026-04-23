#pragma once
#include <iostream>
#include <string>
#include "VectorLibros.h"
#include "VectorEstudiantes.h"

using namespace std;

class Biblioteca {
private:
	VectorLibros* listaLibros;
	VectorEstudiantes* listaEstudiantes;
public:
	Biblioteca(int tamanioLibros, int tamanioEstudiantes) {
		listaLibros = new VectorLibros(tamanioLibros);
		listaEstudiantes = new VectorEstudiantes(tamanioEstudiantes);
	}

	void agregarLibro(Libro* libroNuevo) {
		listaLibros->agregar(libroNuevo);
	}

	void agregarEstudiante(Estudiante* estudianteNuevo) {
		listaEstudiantes->agregar(estudianteNuevo);
	}

	void registrarPrestamo(int ci, int codigo) {
		Libro* libroEncontrado = listaLibros->buscar(codigo);
		Estudiante* estudianteEncontrado = listaEstudiantes->buscar(ci);
		if (libroEncontrado == nullptr) {
			cout << "No se encontro el codigo" << endl;
		}
		else if (estudianteEncontrado == nullptr) {
			cout << "No se encontro el ci" << endl;
		}
		else {
			estudianteEncontrado->asignarLibro(libroEncontrado);
		}
	}
};