#pragma once
#include <iostream>
#include <string>
#include <random>
using namespace std;

class Organizador {
private:
	string nombre;
	int id;
	int rank;
public:
	Organizador()
	{
		nombre = "";
		id = 0;
		rank = 0;
	}
	Organizador(string nombre, int id)
	{
		this->nombre = nombre;
		this->id = id;
		rank = 0;
	}

	void subirRango() { rank++; }

	void mostrar() {
		cout << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Id: " << id << endl;
		cout << "Ranking: " << rank << endl;
	}
};