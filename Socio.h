#pragma once
#include <iostream>
#include <string>
using namespace std;
class Socio {
private:
	int ci;
	string nombre;
	int tel;
public:
	Socio() {}

	Socio(int ci, string nom, int telef) {
		this-> ci = ci;
		this->nombre = nom;
		this->tel = telef;
	}

	void mostrarSocio(){
		cout << "Nombre: " << nombre<<endl;
		cout << "CI: " <<ci<<endl;
		cout << "Telefono: " <<tel<<endl;

	}
	int getCI() {
		return ci;
	}

	string getNombre() {
		return nombre;
	}

};