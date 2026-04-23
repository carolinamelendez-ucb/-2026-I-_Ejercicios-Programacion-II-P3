#pragma once
#include "Libro.h"
using namespace std;

class VectorLibros {
private:
	int tamanio;
	int indice;
	Libro** libros;
public:
	VectorLibros(int tamanio) :tamanio(tamanio), indice(0) {
		this->libros = new Libro * [tamanio];
	}
	void agregar(Libro* nuevoElemento) {
		libros[indice] = nuevoElemento;
		indice++;
	}
	Libro* libroCodigo(int codigo) {
		for (int i = 0;i < indice;i++) {
			if (libros[i]->getCodigo() == codigo) {
				return libros[i];
			}
		}
	}
};