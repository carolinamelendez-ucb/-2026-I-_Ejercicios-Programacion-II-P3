#pragma once
#include<iostream>
#include  "CapacidadMaximaException.h"
#include <string>
using namespace std;
template <class T>
class ArrayGenerico {
private:
	int tamanio;
	int indice;
	T** lista;
public:
	ArrayGenerico(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->lista = new T * [tamanio];
	}

	void agregar(T* nuevoElemento) {
		if (indice < tamanio) {
			this->lista[indice] = nuevoElemento;
			indice++;
		}
		else {
			throw CapacidadMaximaException();
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			lista[i]->mostrar();
		}
	}

	void mostrar(bool estado, bool (*fucionAComparar)(T*, bool)) {
		for (int i = 0; i < indice; i++) {
			if (fucionAComparar(lista[i], estado)) {
				lista[i]->mostrar();
			}
			
		}
	}


	T* buscar(string codigo, bool (*funcionComparar)(T*, string)) {
		for (int i = 0; i < indice; i++) {
			if (funcionComparar(lista[i], codigo)) {
				return lista[i];
			}
		}
		return nullptr;
	}
	T* buscar(bool estado, bool (*funcionComparar)(T*, bool)) {
		for (int i = 0; i < indice; i++) {
			if (funcionComparar(lista[i], estado)) {
				return lista[i];
			}
		}
		return nullptr;
	}

	void ordenar(bool (*funcionAComparar)(T*, T*)) {
		for (int i = 0; i < indice - 1; i++) {
			for (int j = 0; j < indice - i - 1; j++) {
				if (funcionAComparar(lista[j], lista[j+1])) {

					T* temp = lista[j];
					lista[j] = lista[j + 1];
					lista[j + 1] = temp;
				}
			}
		}
	}
	
};