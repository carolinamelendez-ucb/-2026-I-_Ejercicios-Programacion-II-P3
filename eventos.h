#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "evento.h"
class Eventos {
	private:
	Evento** eventos;
	int tamanio;
	int indice;
	public:
	Eventos(int tamanio) {
	this->tamanio=tamanio;
	this->indice = 0;
	this->eventos=new Evento*[tamanio];
	}
	void agregarevento(Evento* evento) {
		eventos[indice] = evento;
		indice++;
	}
	void mostrareventos() {
		for (int i = 0; i < indice; i++) {
			eventos[i]->mostrarEvento();
			cout << endl;
		}
	}
	
	
};
