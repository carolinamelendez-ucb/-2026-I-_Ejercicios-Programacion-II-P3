#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "Organizador.h"
#include "Invitado.h"
using namespace std;

class Evento {
private:
	string nombre;
	int id;
	int maxInvitados;
	Organizador* organizador;
	Invitado** invitados;
	int indice;
public:
	Evento(string nombre, int maxInvitados, Organizador* organizador) {
		this->nombre = nombre;
		this->id = rand() % 1000;
		this->maxInvitados = maxInvitados;
		this->organizador = organizador;
		this->invitados = new Invitado * [maxInvitados];
		this->indice = 0;
		organizador->ocupar();
	}
	void registrarInvitado(string nombre, int telf) {
		invitados[indice] = new Invitado(nombre, telf);
		indice++;
	}
	void mostrar() {
		cout << "Evento: " << nombre << endl;
		cout << "ID: " << id << endl;
		cout << "--- Invitados ---" << endl;
		for (int i = 0; i < indice; i++) {
			invitados[i]->mostrar();
		}
	}
	void finalizar() {
		organizador->subirRank();
		organizador->liberar();
	}
};
