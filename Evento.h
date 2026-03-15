#pragma once
#include <iostream>
#include <string>
#include "VectorInvitados.h"
//#include "Organizador.h"
#include "VectorOrganizado.h"
using namespace std;
class Evento {
private:
	string nombre;
	int id;
	int maxInvitados;
	VectorInvitado listaInvitados;
	Organizador* organizador;
public:

	Evento() = default;

	Evento(string nombre, int maxInvitados, VectorInvitado lista, Organizador* organizador)
		: nombre(nombre), id(generarId()), maxInvitados(maxInvitados),
		listaInvitados(lista), organizador(organizador) {
	}

	void agregarInvitadoDesdeEvento(Invitado* nuevoInvitado) {
		if (listaInvitados.getIndice() < maxInvitados) {
			listaInvitados.agregar(nuevoInvitado);
		}
		else {
			cout << "Se alcanzo el maximo de invitados." << endl;
		}
	}
	void setOrganizador(Organizador* elegido) {
		organizador = elegido;
	}
	Organizador* getOrganizador() {
		return organizador;
	}

	void mostrar() {
		cout << "Nombre del Evento: " << nombre << endl;
		cout << "Id del Evento: " << id << endl;
		cout << "Maximo de Invitados: " << maxInvitados<<endl;
		cout << "Informacion el organizador a cargo: " << endl;
		organizador->mostrar();
		cout << "Lista de invitados: " << endl;
		listaInvitados.mostrar();
	}
	int generarId() {
		id = rand() % 10000 + 10000;
		return id;
	}
	

};