#pragma once
#include <iostream>
#include <string>
#include "Evento.h"
using namespace std;

class EventoVector {
private:
	Evento** eventos;
	int tamanio;
	int indice;
public:
	EventoVector(int tamanio) {
		this->eventos = new Evento * [tamanio];
		this->tamanio = tamanio;
		this->indice = 0;
	}
	void agregarEvento(Evento* newEvento) {
		eventos[indice] = newEvento;
		indice++;
	}
	void mostrarEventos() {
		for (int i = 0; i < indice; i++) {
			eventos[i]->mostrar();
		}
	}
};
