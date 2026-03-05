#pragma once
#include <iostream>
#include <string>
#include "Equipo.h"

using namespace std;
class VectorEquipos
{
private:
	int tamanio;
	int indice;
	Equipo** equipos;
public:
	VectorEquipos(int tamanio) {
		this->equipos = new Equipo * [tamanio];
		this->tamanio = tamanio;
		this->indice = 0;
	}
	void mostrar() {
		for (int i = 0; i < tamanio; i++)
		{
			equipos[i]->mostrar();
		}
	}
	void agregar(Equipo* nuevoEquipo) {
		equipos[indice] = nuevoEquipo;
		indice++;
	}
	void registrar(Socio* socio,int codigoEquipo,int ciSocio) {
		if (indice <= tamanio) {
			for (int i = 0; i < tamanio; i++)
			{
				if (equipos[i]->getCodgio() == codigoEquipo)
				{
					
				}
			}
		}
		else {
			cout << "Limite del equipo alcanzado" << endl;
		}
	}
};

