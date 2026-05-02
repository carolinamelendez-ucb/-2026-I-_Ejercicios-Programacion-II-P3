#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "CapacidadLlenaException.h"

template < class T >

class ArrayGenerico {
private:
	T** lista;
	int indice;
	int tamanio;
	bool estado;

public:

	ArrayGenerico(int tamanio)
		:  indice(0), tamanio(tamanio),estado(false)
	{
		this->lista = new T * [tamanio];
	}

	void agregar(T* nuevoElemento) {
		if (indice < tamanio) {
			lista[indice] = nuevoElemento;
			indice++;
		}
		else {
			throw CapacidadLlenaException();
			estado = true;
		}
	}

	void mostrar() {

		for (int i = 0; i < indice; i++) {
			lista[i]->mostrar();
		}
	}

	T* comparar(int valorBuscado, bool (*funcionComparar)(T*, int)) {
		for (int i = 0; i < indice; i++) {
			if (funcionComparar(lista[i], valorBuscado)) {
				return lista[i];
			}
		}
		return nullptr;
	}

	void ordenar(bool (*funcionComparar)(T*, T*)) {
		for (int i = 0; i < indice; i++) {
			for (int j = 1;  j < indice;  j++)
			{
				if (funcionComparar(lista[i], lista[j])) {
					T* aux = lista[i];
					lista[i] = lista[j];
					lista[j] = aux;
				}
			}
		}
	}

	T* mayor(bool (*funcionComparar)(T*, T*)) {
		T* mayor = lista[0];
		for (int i = 0; i < indice; i++) {
			if (funcionComparar(lista[i], mayor)) {
				mayor = lista[i];
			}
		}
		return mayor;
	}

	~ArrayGenerico() {
		for (int i = 0; i < indice; i++) {
			delete lista[i];
		}
		delete[] lista;
	}

};