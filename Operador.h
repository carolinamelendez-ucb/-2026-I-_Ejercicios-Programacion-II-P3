#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"
using namespace std;

class Operador
{
private:
	string nombre;
	int ci;
	float distanciaRecorrida;
	Transporte* transporteAsigando;
public:
	Operador(const string& nombre, int ci, float distanciaRecorrida, Transporte* transporteAsigando)
		: nombre(nombre), ci(ci), distanciaRecorrida(distanciaRecorrida), transporteAsigando(transporteAsigando)
	{}

	Operador(const string& nombre, int ci, float distanciaRecorrida)
		: nombre(nombre), ci(ci), distanciaRecorrida(distanciaRecorrida), transporteAsigando(transporteAsigando)
	{
		this->transporteAsigando = nullptr;
	}
	void mostrarInfo()
	{
		cout << "nombre: " << nombre << endl;
		cout << "ci: " << ci << endl;
		cout << "distancia recorrida: " << distanciaRecorrida<< endl;
		if (transporteAsigando != nullptr)
		{
			transporteAsigando->mostrarInfo();
		}
		cout << "costo generado: " << calcularCostoGenerado() << endl;
	}
	int getCi()
	{
		return ci;
	}
	void asignarTranposrte(Transporte* nuevoTransporte)
	{
		transporteAsigando = nuevoTransporte;
	}
	float calcularCostoGenerado()
	{
		if (transporteAsigando != nullptr)
		{
			return transporteAsigando->calcularCosto(distanciaRecorrida);
		}
		
	}
};

