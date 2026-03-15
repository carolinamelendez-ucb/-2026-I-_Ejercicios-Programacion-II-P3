#pragma once
#include <iostream>
#include <string>
#include "Evento.h"
#include "VectorOrganizado.h"
using namespace std;
class VectorEvento {
private:
	int tamanio;
	int indice;
	Evento** eventos;
	VectorOrganizador * organizadores;

public:
	VectorEvento(int tamanio, VectorOrganizador* organizadores)
		: tamanio(tamanio), indice(0), organizadores(organizadores)
	{
		this->eventos = new Evento * [tamanio];
	}

	//para poder agregar un evetnto el organizador con mayor rank debe estar libre, si no hay nadie libre  no hay evento
	//																							 |
	//ASIGNAR AUTOMATICAMNETE ORGANIZADOR OCN EL RANK MAS ALTO  ---------------------------------|
	
	void agregar(Evento* nuevoEvento)
	{
		int pos = organizadores->asignarOrganizador();

		if (pos != -1) {
			Organizador* orgElegido = organizadores->getOrganizador(pos);
			nuevoEvento->setOrganizador(orgElegido);

			eventos[indice]=nuevoEvento;
			indice++;

			orgElegido->setDisponibilidad(false);
		}
		else
		{
			cout << "No se pudo crear el evento, organizador/es no disponible/s" << endl;
		}
		
		
	}

	void finalizarEvento(int pos) {
		eventos[pos]->getOrganizador()->setRank(eventos[pos]->getOrganizador()->getRank() + 1);
		eventos[pos]->getOrganizador()->setDisponibilidad(true);
	}
	Evento* getEvento(int i) {
		return eventos[i];
	}

	void mostrar() {
		if (indice == 0) {
			cout << "No hay eventos registrados." << endl;
			return;
		}
		for (int i = 0; i < indice; i++) {
			eventos[i]->mostrar();
		}
	}

	~VectorEvento() {
		for (int i = 0; i < indice; i++) {
			delete eventos[i];
		}
		delete[] eventos;
	}



	VectorEvento() = default;

	
};