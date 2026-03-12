#pragma once
using namespace std;
#include <iostream>
#include <string>
#include "organizador.h"
class Organizadores {
	private:
	Organizador** organizadores;
	int tamanio;
	int indice;
	public:
	Organizadores(int tamanio) {
	this->tamanio=tamanio;
	this->indice = 0;
	this->organizadores=new Organizador*[tamanio];
	}
	void agregarOrganizador(Organizador* organizador) {
		organizadores[indice] = organizador;
		indice++;
	}
	void mostrarOrganizadores() {
	for (int i = 0; i < indice; i++) {
			organizadores[i]->mostrarOrganizador();
			cout << endl;
	}
	}
	
};

