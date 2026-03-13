#pragma once
#include <iostream>
#include <string>
#include "organizador.h"
#include "invitado.h"
using namespace std;
class Evento {
private:
	string nombreEvento;
	int idEvento;
	int maxInvitados;
	Invitado** invitados;
	int cantInvitados;
	Organizador* organizador;
	bool activo;
public:
	Evento(string nombreEvento, int idEvento, int maxInvitados, Organizador* organizador) {
		this->nombreEvento = nombreEvento;
		this->idEvento = idEvento;
		this->maxInvitados = maxInvitados;
		this->organizador = organizador;
		this->activo = true;
		this->cantInvitados = 0;
		this->invitados = new Invitado * [maxInvitados];
		if (organizador != nullptr) {
			organizador->setDisponible(false);
		}
	}
	int getId() {
		return idEvento;
	}
	bool estaActivo() {
		return activo;
	}
	bool agregarInvitado(string nombre, int telefono) {
		invitados[cantInvitados] = new Invitado(nombre, telefono);
		cantInvitados++;
		return true;
	}
	void finalizarEvento() {
		if (activo) {
			activo = false;
			organizador->incrementarRank();
			organizador->setDisponible(true);
			cout << "Evento terminado. Rank de: " << organizador->getNombre() << " ahora es: " << organizador->getRank() << endl;
		}
	}
	void mostrarEvento() {
		cout << "Evento: " << nombreEvento << endl;
		cout << "ID del evento: " << idEvento << endl;
		cout << "Max de invitados" << maxInvitados << endl;
		cout << "Estado: ";
		if (activo) {
			cout << "En curso...";
		}
		else {
			cout << "Finalizado";
		}
		cout << endl;
		cout << "Organizador: " << organizador->getNombre() << endl;
		cout << "Rank: " << organizador->getRank() << endl;
		cout << "Invitados: " << cantInvitados << "/" << maxInvitados << endl;
		for (int i = 0; i < cantInvitados; i++) {
			invitados[i]->mostrarInvitado();
		}
	}
	int getCantInvitados() {
		return cantInvitados;
	}
};