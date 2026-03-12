#pragma once
#include <iostream>
#include "Invitado.h"
#include "VectorOrganizadores.h"
using namespace std;

class Evento {
private:
	string nombre;
	int id;
	int max_inv;
	Invitado* invitados;
	Organizador* organizador;
	int indice;
public:
	Evento(string nombre, int id, int max_inv, Organizador* organizador)
	{
		this->nombre = nombre;
		this->id = id;
		this->max_inv = max_inv;
		this->invitados = new Invitado[max_inv];
		this->organizador = organizador;
		indice = 0;
	}
	void agregarInvitados(Invitado nuevoInv) {
		invitados[indice] = nuevoInv;
		indice++;
	}
	void mostrar() {
		cout << endl;
		cout << "Nombre del Evento: " << nombre << endl;
		cout << "Id: " << id << endl;
		cout << "Maximo de Invitados: " << max_inv << endl;
		for (int i = 0; i < indice; i++) {
			cout << endl << "Invitado " << i + 1 << ": "<< endl;
			invitados[i].mostrar();
		}
		cout << "Organizador:" << endl;
		organizador->mostrar();
	}
	void finalizarEvento() { organizador->subirRango(); }
};
