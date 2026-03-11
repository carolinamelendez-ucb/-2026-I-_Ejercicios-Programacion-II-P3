#pragma once
#include <iostream>
#include <string>
#include "equipo.h"
using namespace std;
class equipoVector {
private:
	Equipo** equipos;
	int tamanio;
	int indice;
public:
	equipoVector(int tamanio) {
		this->equipos = new Equipo*[tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Equipo* nueEquipo) {
		if (indice < tamanio) {
			equipos[indice] = nueEquipo;
			indice++;
		}
	}
	void buscarEquiposSocio(Socio* socio) {
		for (int i = 0; i < indice; i++) {
			if (equipos[i]->getPiloto() == socio || equipos[i]->getCopiloto() == socio) {
				cout << "Equipo hallado: " << endl;
				equipos[i]->mostrarEquipo();
				cout << endl;
			}
		}
	}
	void mostrarEquiposVec() {
		for (int i = 0; i < indice; i++) {
			cout << "Equipo" << i + 1 << endl;
			equipos[i]->mostrarEquipo();
			cout << endl;
		}
	}
};