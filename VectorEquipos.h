#pragma once
#include <iostream>
#include "Equipo.h"

using namespace std;

class EquiposVector {
private:
	Equipo** equipos;
	int tamanio;
	int indice;

public:

	EquiposVector(int tamanio) {
		this->equipos = new Equipo * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}

	void agregar(Equipo* nuevoEquipo) {
		equipos[indice] = nuevoEquipo;
		indice++;
	}

	Equipo* getEquipo(int pos) {
		return equipos[pos];
	}

	void registrarSociosEquipo(int posEquipo, Socio* piloto, Socio* copiloto) {

		equipos[posEquipo]->registrarSocios(piloto, copiloto);
	}

	void mostrarEquipos() {

		for (int i = 0; i < indice; i++) {

			cout << "EQUIPO " << i + 1 << endl;
			equipos[i]->mostrar();
			cout << endl;
		}
	}

	void buscarEquiposDeSocio(Socio* s) {

		cout << "Equipos donde participa " << s->getNombre() << ":\n";

		for (int i = 0; i < indice; i++) {

			if (equipos[i]->participaSocio(s)) {
				equipos[i]->mostrar();
				cout << endl;
			}
		}
	}
};