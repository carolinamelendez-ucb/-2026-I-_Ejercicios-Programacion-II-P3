#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pelicula {
private:
	string titulo;
	int duracion;
public:
	Pelicula(string titulo, int duracion) {
		this->titulo = titulo;
		this->duracion = duracion;
	}
	string getTitulo() {
		return titulo;
	}
	void mostrar() {
		cout << "Titulo: " << titulo << endl;
		cout << "Duracion en minutos: " << duracion << endl;
	}
};
