#pragma once
#include <iostream>
#include <string>
#include "ArrayLlenoException.h"
using namespace std;

template<class T>
class ArrayGenerico {
private:
	T** lista;
	int tamanio;
	int indice;
public:
	ArrayGenerico(int tamanio) :tamanio(tamanio), indice(0) {
		this->lista = new T * [tamanio];
	}
	void agregar(T* nuevoElemento) {
		if(indice<tamanio)
		{
			lista[indice] = nuevoElemento;
			indice++;
		}
		else {
			throw ArrayLlenoException();
		}
	}
	void mostrar() {
		for (int i = 0;i < indice;i++) {
			lista[i]->mostrar();
		}
	}
};