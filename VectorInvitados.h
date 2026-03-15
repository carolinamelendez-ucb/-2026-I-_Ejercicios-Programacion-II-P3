#pragma once
#include <iostream>
#include <string>
#include "Invitado.h"
using namespace std;
class VectorInvitado {
private:
	int tamanio;
	int indice;
	Invitado** invitados;
public:

	VectorInvitado() = default;

	VectorInvitado(int tamanio)
		: tamanio(tamanio), indice(0)
	{
		this->invitados = new Invitado * [tamanio];
	}
	int getIndice() {
		return indice;
	}
	void agregar(Invitado * nuevoInvitado) {
		cout << "RegistrandoInvitados..." << endl;
		invitados[indice] = nuevoInvitado;
		indice++;
	}
	void mostrar() {
		if (indice == 0) {
			cout << "No hay invitados registrados." << endl;
			return;
		}
		for (int i = 0; i < indice; i++) {
			cout << i << " : ";
			invitados[i]->mostrar();
			cout << endl;
		}
	}
	~VectorInvitado() {
		for (int i = 0; i < indice; i++) {
			delete invitados[i];
		}
		delete[] invitados;
	}
};