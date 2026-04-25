#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
	int ci;
	string nombre;
public:
	Cliente(int ci, string nombre) {
		this->ci = ci;
		this->nombre = nombre;
	}
	void mostrar() {
		cout << "CI: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
	}
};
