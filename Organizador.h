#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Organizador {
private:
	string nombre;
	int id;
	int rank;
	bool disponible;
public:
	Organizador(string nombre) {
		this->nombre = nombre;
		this->id = rand() % 1000;
		this->rank = 0;
		this->disponible = true;
	}
    int getRank() {
        return rank;
    }
    bool getDisponible() {
        return disponible;
    }
    void ocupar() {
        disponible = false;
    }
    void liberar() {
        disponible = true;
    }
    void subirRank() {
        rank++;
    }
    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "ID: " << id << endl;
        cout << "Rank: " << rank << endl;
        cout << "Disponible: " << disponible << endl;
        cout << endl;
    }
};
