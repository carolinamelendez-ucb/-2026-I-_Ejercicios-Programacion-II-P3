#pragma once
#include <iostream>
#include <string>
using namespace std;
class Espacio {
private:
	string codigo;
	int nivel;
	string sector;
	bool estado; //true libre and false is ocupado

public:

	Espacio(const string& codigo, int nivel, const string& sector)
		: codigo(codigo), nivel(nivel), sector(sector)
	{
		this->estado = true;
	}

	void mostrar() {
		cout << "Codigo: " << codigo << endl;
		cout << "Nivel: " << nivel << endl;
		cout << "Sector: " << sector << endl;
		cout << "Estado: " << (estado ? "Libre" : "Ocupado") << endl;
	}
	string getCodigo() {
		return codigo;
	}
	static bool compararCodigo(Espacio * espacio, string codigo ) {
		return espacio->codigo == codigo;
	}

	static bool compararDisponibilidad(Espacio * espacio, bool estaDisponible) {
		return espacio->estado == estaDisponible;
	}
	void estaOcupado() {
		this->estado = false;
	}
	
};