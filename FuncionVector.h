#pragma once
#include "Funcion.h"
#include <string>
#include <iostream>
using namespace std;

class FuncionVector
{
private:
	Funcion** funciones;
	int tamanio;
	int indice;

public:
	FuncionVector(int tamanio)
	{
		this->tamanio = tamanio;
		this->indice = 0;
		this->funciones = new Funcion * [tamanio];
	}

	bool agregarFuncion(Funcion* nuevaFuncion)
	{
		for (int i = 0; i < indice; i++)
		{
			if (funciones[i]->getCodigo() == nuevaFuncion->getCodigo())
			{
				return false;
			}
		}
		this->funciones[indice] = nuevaFuncion;
		indice++;
		return true;
	}

	Funcion* buscarPorCodigo(string codigoBuscado)
	{
		for (int i = 0; i < indice; i++)
		{
			if (funciones[i]->getCodigo() == codigoBuscado)
			{
				return funciones[i];
			}
		}
		return nullptr;
	}

};