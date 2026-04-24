#pragma once
#include "Pasajero.h"
#include "Asiento.h"

class VectorPasajeros {
private:
	int tamanio;
	int cantidad;
	Pasajero** listaPasajeros;
public:
	VectorPasajeros(int tam){
		this->cantidad = 0;
		this->tamanio = tam;
		this->listaPasajeros = new Pasajero * [tam];
	}

	void agregarP(Pasajero* nvoPasajero) {
		if (cantidad<tamanio) {
			listaPasajeros[cantidad] = nvoPasajero;
			cantidad++;
		}
		else {
			cout << "No se pueden agregar mas pasajeros" << endl;
		}
	}

	Pasajero* buscarCi(int Cibuscado) {
		for (int i = 0;i < cantidad;i++) {
			if (Cibuscado == listaPasajeros[i]->getCI()) {
				return listaPasajeros[i];
			}
		}
		return nullptr;
	}
	
	void mostrar() {
		for (int i = 0;i < cantidad;i++) {
			listaPasajeros[i]->mostrar();
		}
	}


};
