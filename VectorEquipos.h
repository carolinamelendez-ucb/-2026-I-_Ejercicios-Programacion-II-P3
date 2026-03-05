#pragma once
#include <iostream>
#include "Socio.h"
#include "Equipo.h"

using namespace std;

class VectorEquipos {
private:
	Equipo** equipos;
	int tam;
	int indice;
public:
	VectorEquipos(int tam) {
		this->equipos = new Equipo * [tam];
		this->tam = tam;
		this->indice = 0;
	}

	void agregar(Equipo* equipo) {
		equipos[indice] = equipo;
		if (equipos[indice]->getNombrePiloto() == equipos[indice]->getNombreCopiloto()) {
			cout << "El piloto y el copiloto del equipo: " << equipos[indice]->getNombreEquipo() << " tienen los mismo nombres, no se tomara en cuenta este equipo" << endl;
		}
		else {
			indice++;
		}
	}

	void mostrar() {
		for (int i = 0;i < indice;i++) {
			cout << endl << "EQUIPO N°" << i + 1 << ":" << endl;
			equipos[indice]->mostrar();
		}
	}
};