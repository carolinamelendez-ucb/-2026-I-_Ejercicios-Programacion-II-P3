#pragma once
#include <iostream>
#include <string>
#include "Organizador.h"
#include <algorithm>
using namespace std;

class VectorOrganizador {
private:
	int tamanio;
	int indice;
	Organizador** organizadores;
public:
	VectorOrganizador(int tamanio)
		: tamanio(tamanio), indice(0)
	{
		this->organizadores = new Organizador * [tamanio];
	}

	void agregar(Organizador* nuevoOrganizador) {
		organizadores[indice] = nuevoOrganizador;
		indice++;
	}
	void ordenarOrganizadoresRankDisponibilidad() {
		sort(organizadores, organizadores + indice, [](Organizador* a, Organizador* b) {
			if (a->getDisponibilidad() != b->getDisponibilidad()) {
				return a->getDisponibilidad() > b->getDisponibilidad();
			}
			else {
				return a->getRank() > b->getRank();
			}
			
			});
	}
	
	Organizador* getOrganizador(int i) {
		return organizadores[i];
	}
	/*
	void ordenarOrganizadoresRank() {
		sort(organizadores, organizadores + indice, [](Organizador* a, Organizador* b) {
			
		return a->getRank() > b->getRank();
			});
	}*/

	int  asignarOrganizador()
	{
		int pos = -1;
		for (int i = 0; i < indice; i++)
		{
			if (organizadores[i]->getDisponibilidad() == true)
			{
				if (pos == -1) {
					return pos = i;
				}
				else {
					if (organizadores[i]->getRank() > organizadores[pos]->getRank()) {
						return pos = i;
					}
				}
			}
				
		}
		return pos;
	}
	
	void mostrar() {
		ordenarOrganizadoresRankDisponibilidad();
		if (indice == 0) {
			cout << "No hay eventos registrados." << endl;
			return;
		}
		for (int i = 0; i < indice; i++)
		{
			organizadores[i]->mostrar();
		}
	}



	VectorOrganizador() = default;
	~VectorOrganizador() {
		for (int i = 0; i < indice; i++) {
			delete organizadores[i];
		}
		delete[] organizadores;
	}
};