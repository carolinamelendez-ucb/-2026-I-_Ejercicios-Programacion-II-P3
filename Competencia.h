#pragma once
#include "Equipo.h"
#include <iostream>
#include <string>
using namespace std;

class Competencia
{
private:
	string nombre;
	Equipo** equipos;
	int tamanio;
	int indice;

public:
	Competencia(string nombre, int tamanio)
	{
		this->nombre = nombre;
		this->tamanio = tamanio;
		this->indice = 0;
		equipos = new Equipo * [tamanio];
	}
	void agregarEquipo(Equipo* equipo)
	{
		if (socioYaRegistrado(equipo->getPiloto()) ||
			socioYaRegistrado(equipo->getCopiloto()))
		{
			cout << "Error: un socio ya participa en esta competencia" << endl;
			return;
		}

		equipos[indice] = equipo;
		indice++;
	}
	bool socioYaRegistrado(Socio* socio)
	{
		for (int i = 0; i < indice; i++)
		{
			if (equipos[i]->getPiloto() == socio || equipos[i]->getCopiloto() == socio)
			{
				return true;
			}
		}
		return false;
	}
	void mostrar()
	{
		cout << "Competencia: " << nombre << endl;

		for (int i = 0; i < indice; i++)
		{
			equipos[i]->mostrar();
			cout << endl;
		}
	}
};