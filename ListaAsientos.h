#pragma once
#include "Asiento.h"

class VectorAsientos{
private:
	int tamanio;
	int cantidad;
	Asiento** listaAsientos;
public:
	VectorAsientos(int tam) {
		this->cantidad = 0;
		this->tamanio = tam;
		this->listaAsientos = new Asiento * [tam];
	}

	void agregarP(Asiento* nvoAsientos) {
		if (cantidad < tamanio) {
			listaAsientos[cantidad] = nvoAsientos;
			cantidad++;
		}
		else {
			cout << "No se pueden agregar mas Asientos" << endl;
		}
	}

	Asiento* buscarCodigo(int CodigoBuscado) {
		for (int i = 0;i < cantidad;i++) {
			if (CodigoBuscado == listaAsientos[i]->getCodigo()) {
				return listaAsientos[i];
			}
		}
		return nullptr;
	}

	void mostrar() {
		for (int i = 0;i < cantidad;i++) {
			listaAsientos[i]->mostrar();
		}
	}



};