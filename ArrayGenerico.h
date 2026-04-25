#pragma once
#include <iostream>
#include <string>

template <class T>
class ArrayGenerico
{
private:
	int tamanio;
	int indice;
	T** lista;
public:
	ArrayGenerico(int max) {
		lista = new T * [max];
		tamanio = max;
		indice = 0;
	}
	void agergar(T* nuevoElemento) {
		if (indice < tamanio)
		{
			lista[indice] = nuevoElemento;
			indice++;
		}
	}
};

