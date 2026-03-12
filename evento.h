#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "organizador.h"
#include "invitados.h"
class Evento {
	private:
	string nombre;
	string fecha;
	Organizador organizador;
	Invitados invitados;
	int cantidadinvitados;
	public:
	Evento() {
	nombre="";
	fecha="";
	organizador=Organizador();
	invitados = Invitados();
	cantidadinvitados = 0;
	}
	Evento(string nombre, string fecha, Organizador organizador,Invitados invitado,int cantinvi) {
	this->nombre=nombre;
	this->fecha=fecha;
	this->organizador=organizador;
	this->invitados = invitado;
	this->cantidadinvitados = cantinvi;
	}
	void ocuparOrganizador(Organizador organizador) {
		if (organizador.organizadorocupado(organizador)) {
			cout << "El organizador " << organizador.getNombre() << " está ocupado." << endl;
		} else 
		{
			cout << "El organizador " << organizador.getNombre() << " está disponible." << endl;
		}
	}
	void mostrarEvento() {
		cout << "Nombre del evento: " << nombre << endl;
		cout << "Fecha del evento: " << fecha << endl;
		cout << "Organizador: " << organizador.getNombre() << endl;
		cout << "Cantidad de invitados: " << cantidadinvitados << endl;
		}
		
};
