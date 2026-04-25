#pragma once
#include <iostream>
#include <string>
#include "ArrayLLenoException.h"
using namespace std;


template<class T>
class ArrayGenerico
{
private:
	T** lista;
	int tamanio;
	int cantidad;
public:
	ArrayGenerico(int tamanaio)
	{
		this->lista = new T * [tamanaio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}
	void agregar(T* nuevoElemento)
	{
		if (cantidad < tamanio)
		{
			lista[cantidad] = nuevoElemento;
			cantidad++;
		}
		else
		{
			throw ArrayLLenoException();
		}
	}
	void mostrar()
	{
		for (int i = 0; i < cantidad; i++)
		{
			lista[i]->mostrar();
		}
	}

};
