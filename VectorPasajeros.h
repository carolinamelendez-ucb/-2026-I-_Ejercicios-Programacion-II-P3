#pragma once
#include "Pasajero.h"
#include <exception>

class VectorPasajeros {
private:
	int indice;
	int tamanio;
	Pasajero** pasajeros;
public:
	VectorPasajeros(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->pasajeros = new Pasajero * [tamanio];
	}
    void agregarPasajeros(Pasajero* newPasajero) {
        for (int i = 0; i < indice; i++) {
            if (pasajeros[i]->getCi() == newPasajero->getCi())
                throw exception();
        }

        if (indice < tamanio) {
            pasajeros[indice++] = newPasajero;
        }
    }
    Pasajero* buscar(int ci) {
        for (int i = 0; i < indice; i++) {
            if (pasajeros[i]->getCi() == ci)
                return pasajeros[i];
        }
        return nullptr;
    }
    void mostrar() {
        for (int i = 0; i < indice; i++) {
            cout << pasajeros[i]->getCi();
            if (pasajeros[i]->getAsiento() != nullptr)
                cout << " - " << pasajeros[i]->getAsiento()->getCodigo();
            cout << endl;
        }
    }
};
