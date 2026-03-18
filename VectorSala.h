#pragma once
#include <iostream>
#include <string>
#include "Sala.h"
using namespace std;
class VectorSala {
private:
	int tamanio;
	int indice;
	Sala** salas;
public:


	VectorSala() = default;

	VectorSala(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->salas = new Sala * [tamanio];
	}
	void agregar(Sala* nuevaSala) {
		if (indice < tamanio) {
			this->salas[indice] = nuevaSala;
			indice++;
		}
		else {
			cout << "Ya no hay espacio para agregar nuevas Salas" << endl;
		}
		
	}
	Sala* buscarSala(int id) {
		for (int i = 0; i < indice; i++) {
			if (salas[i]->getId() == id) {
				return salas[i];
			}
		}
		return nullptr;
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			salas[i]->mostrar();
		}
	}
};