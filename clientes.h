#pragma once
#include <iostream>
#include <string>
using namespace std;
class Cliente {
private:
	string nombre;
	int ci;
public:
	Cliente(string nombre, int ci) {
		this->nombre = nombre;
		this->ci = ci;
	}
	void mostrar() {
		cout << "El nombre del cliente es: " <<nombre<< endl;
		cout << "El ci del cliente es: " << ci << endl;
	}
};