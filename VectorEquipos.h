#pragma once
#include<iostream>
#include<string>
#include "Equipo.h"
using namespace std;

class VectorEquipos {
private:
	Equipo** equipos;
	int tamanio;
	int indice; //cantidad
public:
	VectorEquipos(int tamanio) {
		this->equipos = new Equipo * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Equipo* nuevoEquipo) {
		equipos[indice] = nuevoEquipo;
		indice++;
	}
	void mostrar() {
		for( int i = 0; i < indice;i++ ) {
			equipos[i]->mostrar();
		}
	}
};