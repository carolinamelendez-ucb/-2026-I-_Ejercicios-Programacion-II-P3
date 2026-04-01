#pragma once
#include <iostream>
#include <string>
#include "Figura.h"
using namespace std;

class VectorFigura
{
private:
	Figura** lista;
	int tamanio;
	int cantidad;
public:
	VectorFigura(int tamanio)
	{
		this->lista = new Figura * [tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}

	void agregar(Figura* nuevaFigura)
	{
		if (cantidad < tamanio)
		{
			lista[cantidad] = nuevaFigura;
			cantidad++;
		}
		else
		{
			cout << "no se pueden agregar figuaras" << endl;
		}
	}
	void calcularTodasLasAreas()
	{
		for (int i = 0; i < cantidad; i++)
		{
			cout << "Figura:" << i+1 <<" Area: " << lista[i]->calcularArea()<<" m2" << endl;
 
		} 
			
		
	}
	~VectorFigura()
	{
		for (int i = 0; i < cantidad; i++)
		{
			delete lista[i];
		}
		delete[]lista;
	}
};
