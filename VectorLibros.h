#pragma once
#include <iostream>
#include "Libro.h"
#include <string>
using namespace std;

class VectorLibros {
private:
	int tamanio;
	int indice;
	Libro** libros;
public:
	VectorLibros(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->libros = new Libro * [tamanio];
	}
	void agregar(Libro *nuevoLibro) {
		if (indice < tamanio) {
			libros[indice] = nuevoLibro;
			indice++;
		}
	}
	
	Libro* buscarId(string id) {
		Libro* aux = nullptr;
		for (int i = 0; i < indice; i++) {
			if (aux == nullptr || aux->getCodigo() == id) {
				return aux;
			}
		}
		return aux;
	}
};