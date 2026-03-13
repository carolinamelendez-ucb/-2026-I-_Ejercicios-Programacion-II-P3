#pragma once
#include <iostream>
#include <string>
#include "evento.h"
using namespace std;
class EventoVector {
private:
	Evento** eventos;
	int tamanio;
	int indice;
public:
	EventoVector(int tamanio) {
		this->eventos = new Evento * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Evento* nueEvento) {
		if (indice < tamanio) {
			eventos[indice] = nueEvento;
			indice++;
		}
		else {
			cout << "Llego a su maxima capacidad" << endl;
		}
	}
	void mostrarTodos() {
		cout << "Todos los eventos" << endl;
		for (int i = 0; i < indice; i++) {
			eventos[i]->mostrarEvento();
		}
	}
	void mostrarActivos() {
		cout << "Eventos activos" << endl;
		for (int i = 0; i < indice; i++) {
			if (eventos[i]->estaActivo()) {
				eventos[i]->mostrarEvento();
			}
		}
	}
	Evento* buscarEventoPorID(int id) {
		for (int i = 0; i < indice; i++) {
			if (eventos[i]->getId() == id) {
				return eventos[i];
			}
		}
		return nullptr;
	}
	Evento* getEvento(int posicion) {
		if (posicion >= 0 && posicion < indice) {
			return eventos[posicion];
		}
		return nullptr;
	}
	int getIndice() {
		return indice;
	}
};