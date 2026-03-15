#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
class Organizador {
private:
	string nombre;
	int id;
	bool disponibilidad;
	int rank;

public:

	Organizador() = default;

	Organizador(const string& nombre, bool disponibilidad,int rank )
		: nombre(nombre), id(generarId()), disponibilidad(disponibilidad), rank(rank)
	{
	}
	void setDisponibilidad(bool disponibilidadNueva) {
        disponibilidad = disponibilidadNueva;
    }

    bool getDisponibilidad() {
        return disponibilidad;
    }
	int getRank() {
		return rank;
	}
	void setRank(int nuevoRank) {
		rank=  nuevoRank;
	}
	
	void mostrar() {
		cout << "Nombre del organizador es: " <<nombre<< endl;
		cout << "Id del organizador es: " << id << endl;
		cout << "Rank delorganizador es: " << rank << endl;
		cout << "La disponibilidad del organizador esta: " << (disponibilidad ? "Libre": "Ocupado") << endl;
	}
	int generarId() {
		id = rand() % 100 + 100;
		return id;
	}
};