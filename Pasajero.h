#pragma once
#include <iostream>
#include <string>
#include "Asiento.h"
using namespace std;
class Pasajero {
private:
	int ci;
	string nombre;
	string apellido;
	Asiento* asientoAsignado;
public:
	Pasajero(int ci, const string& nombre, const string& apellido)
		: ci(ci), nombre(nombre), apellido(apellido), asientoAsignado(nullptr)
	{
	}
	void asignarAsiento(Asiento* asiento) {
		asientoAsignado = asiento;
	}
	int getCI() {
		return ci;
	}
	Asiento* getAsientoAsignado() {
		return asientoAsignado;
	}
	void mostrar() {
		cout << "CI: " << ci << " - " << "Nombre: " << nombre << " " << apellido;
		if (asientoAsignado != nullptr) {
			cout << ", Asiento: " << asientoAsignado->getCodigo();
		}
		cout << endl;
	}
};