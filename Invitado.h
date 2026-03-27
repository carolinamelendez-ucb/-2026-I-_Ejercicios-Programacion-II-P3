#pragma once
#include <iostream>
#include <string>
using namespace std;

class Invitado {
private:
	string nombre;
	int telf;
public:
	Invitado(string nombre, int telf) {
		this->nombre = nombre;
		this->telf = telf;
	}
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Tel: " << telf << endl;
	}
};