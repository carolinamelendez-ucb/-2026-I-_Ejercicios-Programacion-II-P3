#pragma once
#include <iostream>
#include <string>
#include "Sala.h"
#include "Pelicula.h"
using namespace std;

class Funcion {
private:
	Sala* salaAsignada;
	Pelicula* peliculaAsignada;
public:
	Funcion() {
		this->salaAsignada = nullptr;
		this->peliculaAsignada = nullptr;
	}
	void asignarSala(Sala* newSala) {
		salaAsignada = newSala;
	}
	void asignarPelicula(Pelicula* newPelicula) {
		peliculaAsignada = newPelicula;
	}
	void mostrar() {
		cout << "Sala Asignada: " << salaAsignada << endl;
		cout << "Pelicula Asignada: " << peliculaAsignada << endl;
	}
};
