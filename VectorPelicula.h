#pragma once
#include <iostream>
#include <string>
#include "Pelicula.h"
using namespace std;
class VectorPelicula {
private:
	int tamanio;
	int indice;
	Pelicula** peliculas;
public:


	VectorPelicula() = default;

	VectorPelicula(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->peliculas = new Pelicula * [tamanio];
	}
	void agregar(Pelicula* nuevaPelicula) {
		if (indice < tamanio) {
			this->peliculas[indice] = nuevaPelicula;
			indice++;
		}
		else {
			cout << "No espacio para agregar nuevas Peliculas" << endl;
		}
		
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			peliculas[i]->mostrar();
		}
	}
	int getIndice() {
		return indice;
	}
	Pelicula* getpos(int i) {
		return peliculas[i];
	}
	
	Pelicula* buscarPelicula(int id) {
		for (int i = 0; i < indice; i++) {
			if (peliculas[i]->getId() == id) {
				return peliculas[i];
			}
		}
		return nullptr;
	}
};