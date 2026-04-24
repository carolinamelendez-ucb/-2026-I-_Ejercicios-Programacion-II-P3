#pragma once
#include <iostream>
#include <string>
#include "Asiento.h"
using namespace std;
class VectorAsiento {
private:
	Asiento** asientos;
	int tamanio;
	int indice;
public:
	VectorAsiento(int tamanio) {
		this->asientos = new Asiento * [tamanio];
		this->tamanio = tamanio;
		this->indice = 0;
	}
	void agregarAsiento(Asiento* nueAsiento) {
		if (indice < tamanio) {
			asientos[indice] = nueAsiento;
			indice++;
		}
		else {
			throw exception();
		}
	}
	Asiento* buscar(string codigoBuscado) {
		for (int i = 0; i < indice; i++) {
			if (asientos[i]->getCodigo() == codigoBuscado) {
				return asientos[i];
			}
		}
		return nullptr;
	}
	void mostrar() {
		int disponibles = 0, ocupados = 0;
		for (int i = 0; i < indice; i++) {
			if (asientos[i]->getDisponible()) {
				disponibles++;
			}
			else {
				ocupados++;
			}
		}
			cout << "Disponibles: " << disponibles << endl;
			cout << "Ocupados: " << ocupados << endl;
	}
};
