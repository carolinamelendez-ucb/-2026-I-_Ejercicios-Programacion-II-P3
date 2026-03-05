#pragma once
#include <iostream>
#include <string>
#include "equipo.h"
using namespace std;
class EquipoVector {
	Equipo** equipo;
	int tamanio;
	int indice;
	EquipoVector(int tamanio) {
		this->equipo = new Equipo * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void mostrarEuipoVector() {
		cout<<""
	}
};