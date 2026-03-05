#pragma once
#include <iostream>
#include <string>
#include "equipo.h"
using namespace std;
class Equipovec {
private:
	Equipo** equipos;
	int tamanio;
	int indice;
public:
	Equipovec(int tamanio) {
		this->equipos = new Equipo * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Equipo* nuevoequipo) {
		equipos[indice] = nuevoequipo;
		indice++;
	}
	void mostrar(Equipo* nombrepiloto,Equipo* nombrecopiloto) {
		for (int i = 0;i < indice;i++) {
			if (nombrepiloto[i].getnompiloto() == nombrecopiloto[i].getnomcopiloto()) {
				equipos[i]->mostrar();
			}
		}
	}
};
