#pragma once


#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
	string ci;
	string nombre;
public:
	Cliente(string ci, string nombre) {
		this->ci = ci;
		this->nombre = nombre;
	}
	void mostrar() {
		cout << "Nombre: " << nombre << endl;
		cout << "Ci: " << ci << endl;
	}
};