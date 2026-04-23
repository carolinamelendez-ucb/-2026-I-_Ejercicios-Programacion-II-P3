#pragma once
#include <iostream>
#include <string>
#include "Libro.h"

using namespace std;

class VectorLibros {
private:
	int tamanio;
	int indice;
	Libro** libros;
public:
	VectorLibros(int tamanio)
		: tamanio(tamanio), indice(0)
	{
		this->libros = new Libro * [tamanio];
	}

	void agregar(Libro* libroNuevo) {
		if (indice > tamanio) {
			cout << "No se pueden agregar mas" << endl;
		}
		else {
			libros[indice] = libroNuevo;
			indice++;
		}
	}

	Libro* buscar(int codigo) {
		for (int i = 0;i != indice;i++) {
			if (codigo == libros[i]->getCodigo()) {
				return libros[i];
			}
		}
		return nullptr;
	}

	void mostrarMasPrestado() {
		int mayor = -1, j = -1;
		for (int i = 0;i != indice;i++) {
			if (libros[i]->getPrestamos() > mayor) {
				mayor = libros[i]->getPrestamos();
				indice = i;
			}
		}
		libros[j]->mostrar();
	}
};