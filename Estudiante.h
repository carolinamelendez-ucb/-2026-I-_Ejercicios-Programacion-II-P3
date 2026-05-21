#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
	int ci;
	string nombre;
	int cont;
	string apellido;
public:
	Estudiante(int ci, const string& nombre, const string& apellido)
		: ci(ci), nombre(nombre), apellido(apellido)
	{
		this->cont = 0;
	}
	int getCI() {
		return ci; // no deberia haber +1
	}
	static bool compararCI(int c, Estudiante* e) {
		return c == e->ci;
	}
	void mostrar() {
		cout << "CI: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Apellido: " << apellido << endl;
	}
	void aumentarCantInscrionesActivas() {
		cont++;
	}
	int getContInscripciones() {
		return cont;
	}
	void reducirContInscricionesActiva() {
		cont--;
	}
};