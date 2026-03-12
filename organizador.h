#pragma once
using namespace std;
#include <iostream>
#include <string>
class Organizador {
	private:
	string nombre;
	int ID;
	bool ocupado;
	int cantidadEventos;
	public:
		Organizador() {
		nombre="";
		ID = 0;
		ocupado = false;
		cantidadEventos = 0;
		}
		Organizador(string nombre, int ID,bool ocupado,int cantidad) {
		this->nombre=nombre;
		this->ID=ID;
		this->ocupado = ocupado;
		this->cantidadEventos = cantidad;

	}
	string getNombre() {
		return nombre;
	}
	void mostrarOrganizador() {
		cout << "Nombre del organizador: " << nombre << endl;
		cout << "ID del organizador: " << ID << endl;
		cout << "Cantidad de eventos organizados: " << cantidadEventos << endl;
	}
	bool organizadorocupado(Organizador organizador) {
		if (organizador.getNombre() == nombre) {
			return ocupado=true;
		}
		else {
			return ocupado=false;
		}
	}
};
