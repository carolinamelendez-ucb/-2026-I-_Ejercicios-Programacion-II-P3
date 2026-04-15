#pragma once
#include <iostream>
#include <string>
#include "Docente.h"

using namespace std;

class VectorDocentes
{
private:
	Docente** lista;
	int tamanio;
	int cantidad;
public:
	VectorDocentes(int tamanio)
	{
		this->lista = new Docente * [tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}
	void agregar(Docente* nuevoDocente)
	{
		if (cantidad < tamanio)
		{
			lista[cantidad] = nuevoDocente;
			cantidad++;
		}
		else
		{
			cout << "no se puede agregar nuevos docentes " << endl;
		}
	}
	Docente* buscarPorCi(int ciBuscado)
	{
		for (int i = 0; i < cantidad; i++)
		{
			if (ciBuscado == lista[i]->getCi())
			{
				return lista[i];
			}
		}
		return nullptr;
	}
	void mostrar()
	{
		for (int i = 0; i < cantidad; i++)
		{
			lista[i]->mostrar();
			cout << "-----------------" << endl;
		}
	}
	Docente* menorSalario()
	{
		Docente* menor = lista[0];
		for (int i = 0; i < cantidad; i++)
		{
			if (lista[i]->calculaSalario() < menor->calculaSalario())
			{
				menor = lista[i];
			}
		}
		return menor;
	}
	~VectorDocentes()
	{
		for (int i = 0; i < cantidad; i++)
		{
			delete lista[i];
		}
		delete[]lista;
	}
};