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
	Evento(){}
	Evento(string nombreEvento, int maxInvitados, Organizador* organizadorAsignado, VectorInvitado* listaDeInvitados)
	{
		this->nombreEvento = nombreEvento;
		this->id = rand();
		this->maxInvitados = maxInvitados;
		this->organizadorAsignado = organizadorAsignado;
		this->listaDeInvitados = listaDeInvitados;
	}
	~Evento()
	{}
	void mostrar()
	{
		cout << "Nombre del evento: " << nombreEvento << endl;
		cout << "Id: " << id << endl;
		cout << "Cantidad maxima de invitados: " << maxInvitados<<endl;
		cout << "El organizaodor asignados es: " << endl;
		organizadorAsignado->mostrar();
		cout << "la lista de invitados es " << endl;
		listaDeInvitados->mostrar();

	}
};

