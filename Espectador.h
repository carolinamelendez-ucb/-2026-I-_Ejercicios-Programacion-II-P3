#pragma once
#include <iostream>
#include <string>

using namespace std;

class Espectador {
private:
	string nombre;
	string telefono;
public:

	Espectador() = default;

	Espectador(const string& nombre, const string& telefono)
		: nombre(nombre), telefono(telefono)
	{
	}
	void mostrar() {
		cout << "Nombre del espectador: " << nombre << endl;
		cout << "Telefono del espectador: " << telefono << endl;
	}
};