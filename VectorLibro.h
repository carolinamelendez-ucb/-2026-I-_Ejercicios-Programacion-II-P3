#pragma once
#include <iostream>
#include <string>
#include "Libro.h"

using namespace std;
class VectorLibro {
private:
	int tamanio;
	int indice;
	Libro** libros;
public:	

	VectorLibro() = default;

	VectorLibro(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->libros = new Libro * [tamanio];
	}
	void agregar(Libro * nuevoLibro) {
		if (indice < tamanio) {
			libros[indice] = nuevoLibro;
			indice++;
		}
		else {
			cout << "No se pudo realizar registro de Libro, Error!" << endl;
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			libros[i]->mostrar();
		}
	}

	bool BuscarLibro(int ci) {
		for (int i = 0; i < indice; i++) {
			if (libros[i]->getCodigo() == ci) {
				return true;
			}
		}
		return false;
	}
	
	Libro* getLibro(int codigo) {
		for (int i = 0; i < indice; i++) {
			if (libros[i]->getCodigo() == codigo) {
				return libros[i];
			}
		}
		return nullptr;
	}

	~VectorLibro() {
		for (int i = 0; i < indice; i++) {
			delete libros[i];
		}
		delete[] libros;
	}

};