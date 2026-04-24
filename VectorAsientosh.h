#pragma once
#include "Asiento.h"

class VectorAsientos {
private:
	int indice;
	int tamanio;
	Asiento** asientos;
public:
	VectorAsientos(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->asientos = new Asiento * [tamanio];
	}
	void agregarAsientos(Asiento* newAsiento) {
		if (indice < tamanio) {
			asientos[indice] = newAsiento;
			indice++;
		}
	}
	Asiento* buscar(string codigobuscado) {
		for (int i = 0; i < indice; i++) {
			if (asientos[i]->getCodigo() == codigobuscado) {
				return asientos[i];
			}
		}
		return nullptr;
	}
	void mostrarEstado() {
		int disp = 0, ocup = 0;
		for (int i = 0; i < indice; i++) {
			if (asientos[i]->getDiponibilidad())
				disp++;
			else
				ocup++;
		}
		cout << "Disponibles: " << disp << endl;
		cout << "Ocupados: " << ocup << endl;
	}
};