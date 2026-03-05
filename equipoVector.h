#pragma once
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
	void agregar(Equipo* newEquipo) {
		equipos[indice] = newEquipo;
		indice++;
	}
	void mostrarEquipos() {
		for (int i = 0; i < indice; i++) {
			cout << "--> Equipo " << i + 1 << endl;
			equipos[i]->mostrar();
			cout << endl;
		}
	}
};