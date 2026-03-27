#pragma once
#include <iostream>
#include <string>
#include "Invitado.h"
#include "Organizador.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

class Evento
{
private:
	string nombre;
	int id;
	int maximoInvitados;
	Invitado** listaInvitados;
	Organizador* organizadorAsignado;
	int ind;
public:
	Evento(string nombre, int maximoInvitados,int id)
	{
		this->nombre = nombre;
		this->maximoInvitados = maximoInvitados;
		this->listaInvitados = new Invitado * [maximoInvitados];
		this->organizadorAsignado = nullptr;
		this->id = id;
		this->ind = 0;
	}
	Evento(string nombre, int maximoInvitados)
	{
		this->nombre = nombre;
		this->maximoInvitados = maximoInvitados;
		this->listaInvitados = new Invitado * [maximoInvitados];
		this->organizadorAsignado =nullptr;
			this->id = generarID();
			this->ind = 0;
	}
	 int generarID() {
		return rand() % 9000 + 1000; // número entre 1000 y 9999
	}
	 void asignarOrganizador(Organizador* organizador)
	 {
		 organizadorAsignado = organizador;
	 }
	 void Mostrar()
	 {
		 cout<<endl << nombre << endl;
		 cout << id << endl;
		 cout << maximoInvitados << endl;
		 cout << "organizador:"<<endl;
		 organizadorAsignado->mostrar();
		 cout << endl;
	 }
	 int getID()
	 {
		 return id;
	 }
	 void agregarInvitado(Invitado* invitado)
	 {
		 if (ind < maximoInvitados)
		 {
			 listaInvitados[ind] = invitado;
			 ind++;
			 cout << "invitado agregado correctamente:"<<ind;
		 }
		 
	 }
	 void finalizar()
	 {
		 organizadorAsignado->cambiarRank();
	 }
};

