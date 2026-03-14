#pragma once
#include <iostream>
#include <string>
#include "Organizador.h"

using namespace std;

class VectorOrganizador
{
private:
	Organizador** origanizadores;
	int tamnanio;
	int indice;

public:
	VectorOrganizador(int tamanio)
	{
		this->origanizadores = new Organizador * [tamanio];
		this->tamnanio = tamanio;
		this->indice = 0;
	}
	void agregar(Organizador* nuevoOrganizador)
	{
		origanizadores[indice] = nuevoOrganizador;
		indice++;
	}
	void mostrar()
	{
		for (int i = 0; i < indice; i++)
		{
			origanizadores[i]->mostrar();
		}
	}

	Organizador* buscarOrganizadorDisponible() {
		// Step 1. Ordenar por rank
		this->ordenarPorRank();

		// Step 2. Devolver el primer organizador disponible
		for (int i = 0; i < indice; i++) {
			if (origanizadores[i]->getDisponibilidad() == true) {
				return origanizadores[i];
			}
		}
		return nullptr; // Significa que no existe
	}

	void ordenarPorRank() {
		for (int i = 0; i < indice - 1; i++) {
			for (int j = i + 1; j < indice; j++) {
				if (origanizadores[i]->getRank() < origanizadores[j]->getRank() ) { // "<" de mayor a menor
					Organizador* aux = origanizadores[i];
					origanizadores[i] = origanizadores[j];
					origanizadores[j] = aux;
				}
			}
		}
	}

	~VectorOrganizador() {
		for (int i = 0; i < indice; i++) {
			delete origanizadores[i];
		}

		delete[] origanizadores;
	}

};
