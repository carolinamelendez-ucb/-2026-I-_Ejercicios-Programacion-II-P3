#pragma once
#include <iostream>
#include <string>
using namespace std;
class socio {
private:
	int ci;
	string nombre;
	int telefono;
public:
	socio(int ci, string nombre, int telefono) {
		this->ci = ci;
		this->nombre = nombre;
		this->telefono = telefono;
	}
	void mostrar() {
		cout << "ci" << ci << endl;
		cout << "nombre" << nombre << endl;
		cout << "telefono"<< telefono << endl;
	}
	string getNombre() {
		return nombre;
	}
 };
