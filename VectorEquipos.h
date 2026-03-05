#pragma once
#include <iostream>
#include "Equipo.h"
#include "Socio.h"

using namespace std;

class EquiposVector {
private:
	Equipo** equipos;
	Socio** socios;
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
		/*equipos[indice]->setPiloto(socios[indice * 2].getNombre);
		equipos[indice]->setCopiloto(socios[(indice * 2) + 1].getNombre);*/
		indice++;
	}

	void mostrarEquipos() {
		for (int i = 0;i != indice;i++) {
			cout << "EQUIPO " << i + 1 << endl;
			equipos[i]->mostrar();
			cout << endl;
		}
	}
};