#pragma once
#include <string>
#include <iostream>
#include "Libro.h"
using namespace std;
class VecLibro {
private:
	Libro** listaLibro;
	int tamanio;
	int indice;
public:
	VecLibro(int tamanio) {
		this->tamanio=tamanio;
		this->indice = 0;
		this->listaLibro = new Libro*[tamanio];
	}
	bool buscraLibro(int codigo) {
		for (int i = 0;i < indice;i++) {
			if (listaLibro[i]->getCodigo() == codigo) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	void agregar(Libro* nuevolibro) {
		if (tamanio > indice) {
			listaLibro[indice] = nuevolibro;
			indice++;
		}
	}
	void mostrar() {
		for (int i = 0;i < indice;i++) {
			listaLibro[i]->mostrar();
		}
	}
};