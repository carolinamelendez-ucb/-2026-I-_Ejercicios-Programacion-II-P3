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
	void mostrar() {
		cout << "Titulo: " << titulo << endl;
		cout << "Duracion: " << duracion << " minutos" << endl;
	}
};
