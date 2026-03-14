#pragma once
#include <iostream>
#include <string>
#include "VectorOrganizador.h"
#include "VectorInvitado.h"
using namespace std;

class Evento
{
private:
	string nombreEvento;
	int id;
	int maxInvitados;
	Organizador* organizadorAsignado;
	VectorInvitado* listaDeInvitados;

public:
	Evento() {}
	Evento(int id, string nombreEvento, int maxInvitados) // maxInvitados reemplaria tamanioInvitados
	{
		this->nombreEvento = nombreEvento;
		this->id = id;
		this->maxInvitados = maxInvitados;
		this->organizadorAsignado = nullptr; // NULL porque mas adelante se le asignara un organizador
		this->listaDeInvitados = new VectorInvitado(maxInvitados);
	}

	void asignarOrganizador(Organizador* organizador) {
		this->organizadorAsignado = organizador;
		this->organizadorAsignado->marcarComoOcupado();
	}

	~Evento()
	{
	}
	void mostrar()
	{
		cout << "Nombre del evento: " << nombreEvento << endl;
		cout << "Id: " << id << endl;
		cout << "Cantidad maxima de invitados: " << maxInvitados << endl;
		cout << "El organizaodor asignados es: " << endl;
		if (organizadorAsignado != nullptr) {
			organizadorAsignado->mostrar();
		}
		cout << "la lista de invitados es " << endl;
		listaDeInvitados->mostrar();

	}

	int getId() {
		return id;
	}

	void registrarInvitado(Invitado* invitado) {
		this->listaDeInvitados->agregar(invitado);
	}

	void finalizar() {
		organizadorAsignado->finalizarServicio();
	}

	~Evento() {
		delete listaDeInvitados;
	}
};

