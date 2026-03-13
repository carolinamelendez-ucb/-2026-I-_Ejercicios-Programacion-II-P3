#pragma once
#include <iostream>
#include <string>
using namespace std;
class Organizador {
private:
	string nombre;
	int id;
	int rank;
	bool disponible;
public:
	Organizador(string nombre, int id) {
		this->nombre = nombre;
		this->id = id;
		this->rank = 0;
		this->disponible = true;
	}
	string getNombre() {
		return nombre;
	}
	int getRank() {
		return rank;
	}
	bool estaDisponible() {
		return disponible;
	}
	void setDisponible(bool estado) {
		disponible = estado;
	}
	void incrementarRank() {
		rank++;
	}
	void mostrarOrganizador() {
		cout << "Nombre: " << nombre << endl;
		cout << "ID: " << id << endl;
		cout << "Rank: " << rank << endl;
		cout << "Esta disponible: ";
		if (disponible) {
			cout << "Si";
		}
		else {
			cout << "No";
		}
		cout << endl;
	}

};