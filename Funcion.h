#pragma once
#include <iostream>
#include <string>
#include "Sala.h"
#include "Pelicula.h"
using namespace std;

class Funcion {
private:
	int codigo;
	Pelicula* pelicula;
	Sala* sala;
public:
	Funcion(int codigo) {
		this->pelicula = nullptr;
		this->sala = nullptr;
	}
	void agregarPelicula(Pelicula* peliculaAsignada) {
		pelicula = peliculaAsignada;
	}
	void agregarSala(Sala* salaAsignada) {
		sala = salaAsignada;
	}
	void mostrar() {
		cout << "Codigo de la funcion: " << codigo << endl;
		if (pelicula != nullptr) {
			cout << "Pelicula: ";
			pelicula->mostrar();
		}
		else cout << "No hay pelicula asignada" << endl;
		
		if (sala != nullptr) {
			cout << "Sala: ";
			sala->mostrar();
		}
		else cout << "No hay sala asignada" << endl;
	}
};