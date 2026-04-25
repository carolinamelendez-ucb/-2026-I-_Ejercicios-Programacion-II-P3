#pragma once
#include <iostream>
#include <string>
#include "MensajeLLeno.h"
using namespace std;


template<class T>
class ArrayGen {
private:
	T** lista;
	int tamanio;
	int cantidad;
public:
	ArrayGen(int tam) {
		lista = new T * [tam];
		tamanio = tam;
		cantidad = 0;
	}

	void agregar(T* nvoElemento) {
		if (cantidad < tamanio) {
			lista[cantidad] = nvoElemento;
			cantidad++;
		}
		else {
			throw Vectorlleno();
		}
	}

	void mostraR() {
		for (int i = 0;i < cantidad;i++) {
			lista[i]->mostrar();
		}
	}
};