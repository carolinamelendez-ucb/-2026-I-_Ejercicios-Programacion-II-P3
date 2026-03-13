#pragma once
#include <iostream>
#include <string>
#include "organizador.h"
using namespace std;
class OrganizadorVector {
private:
	Organizador** organizadores;
	int tamanio;
	int indice;
public:
	OrganizadorVector(int tamanio) {
		this->organizadores = new Organizador * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Organizador* nueOrganizador) {
		if (indice < tamanio) {
			organizadores[indice] = nueOrganizador;
			indice++;
		}
		else {
			cout << "Llego a su capacidad maxima" << endl;
		}
	}
	void ordenarPorRank() {
		for (int i = 0; i < indice; i++) {
			for (int j = i + 1; j < indice; j++) {
				if (organizadores[i]->getRank() < organizadores[i]->getRank()) {
					Organizador* aux = organizadores[i];
					organizadores[i] = organizadores[j];
					organizadores[i] = aux;
				}
			}
		}
	}
	void mostrarTodos() {
		cout << "Organizadores" << endl;
		for (int i = 0; i < indice; i++) {
			organizadores[i]->mostrarOrganizador();
		}
	}
	void mostrarDisponibles() {
		cout << "Organizadores disponibles" << endl;
		for (int i = 0; i < indice; i++) {
			if (organizadores[i]->estaDisponible()) {
				organizadores[i]->mostrarOrganizador();
			}
		}
	}
	Organizador* buscarDisponibleConMasRank() {
		Organizador* mejor = nullptr;
		int maxRank = 0;
		for (int i = 0; i < indice; i++) {
			if (organizadores[i]->estaDisponible() && organizadores[i]->getRank() > maxRank) {
				maxRank = organizadores[i]->getRank();
				mejor = organizadores[i];
			}
		}
		return mejor;
	}
	Organizador* getOrganizador(int posicion) {
		if (posicion >= 0 && posicion < indice) {
			return organizadores[posicion];
		}
		return nullptr;
	}
	int getIndice() {
		return indice;
	}

};