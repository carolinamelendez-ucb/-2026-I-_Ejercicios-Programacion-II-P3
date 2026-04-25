#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>

class ArrayGenerico {
private: 
	T** lista;
	int tamanio;
	int indice;
public:
	ArrayGenerico(int tamanio) {
		this->lista = new T * [tamanio];
		this->tamanio = tamanio;
		this->indice = indice;
	}
	void agregar(T * nuevo) {
		if (indice<tamanio) {
			lista[indice] = nuevo;
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			lista[i]->mostrar();
		}
	}
};