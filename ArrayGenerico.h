#pragma once
#include <iostream>
#include <string>
#include "ArrayLlenoException.h"
using namespace std;

template<class T>
class ArrayGenerico {
private:
	int indice;
	int tamanio;
	T** lista;
public:
	ArrayGenerico(int tamanio) {
		this->indice = 0;
		this->tamanio = tamanio;
		this->lista = new T * [tamanio];
	}
	void agregar(T* newElemento) {
		if (indice < tamanio) {
			lista[indice] = newElemento;
			indice++;
		}
		else {
			throw ArrayLlenoException();
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			lista[i]->mostrar();
		}
	}
};
