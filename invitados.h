#pragma once
using namespace std;
#include <iostream>
#include <string>
class Invitados {
	private:
	string nombre;
	int telefono;
	public:
		Invitados() {
		nombre="";
		telefono = 0;
		}
		Invitados(string nombre, int telefono) {
		this->nombre=nombre;
		this->telefono=telefono;
	}
	void mostrarInvitado() {
		cout << "Nombre del invitado: " << nombre << endl;
		cout << "Telefono del invitado: " << telefono << endl;
	}

	
};
