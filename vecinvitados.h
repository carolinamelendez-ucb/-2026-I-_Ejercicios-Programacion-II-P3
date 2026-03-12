#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "invitados.h"
class Vecinvitados {
	private:
	Invitados** invitados;
	int tamanio;
	int indice;
	public:
	Vecinvitados(int tamanio) {
	this->tamanio=tamanio;
	this->indice = 0;
	this->invitados=new Invitados*[tamanio];
	}
	void agregarinvitado(Invitados* invitado) {
		invitados[indice] = invitado;
		indice++;
	}
	void mostrarinvitados() {
		for (int i = 0; i < indice; i++) {
			invitados[i]->mostrarInvitado();
			cout << endl;
		}
	}
};
