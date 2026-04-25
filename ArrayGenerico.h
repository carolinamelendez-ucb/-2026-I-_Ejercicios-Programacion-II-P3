#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class ArrayGenerico
{
private:
	int ind;
	int tamnio;
	T** lista;
public:
	ArrayGenerico(int tamanio)
	{
		this->ind = 0;
		this->tamnio = tamanio;
		this->lista = new T * *[tamanio];
	}
};

