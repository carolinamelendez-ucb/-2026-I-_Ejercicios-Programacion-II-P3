#pragma once
#include <iostream>
#include <string>
using namespace std;

template<class T>
class ArrayGenerico
{
private:
	T** lista;
	int tamanio;
	int indice;
public:
	ArrayGenerico(int max);

};

