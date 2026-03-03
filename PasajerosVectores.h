#include <iostream>
#include <string>
#include "Pasajeross.h"
using namespace std;
class PasajeroVector {
	//usar Dos"*" cuando se quiera declarar u vetor o arrive
private:
	Pasajero** pasajeros;
	int tamanio;
	int indice;
public:
	PasajeroVector(int tamanio) { //creo que solo se asigna tamanio
		this->pasajeros = pasajeros;
		this->tamanio = tamanio;
		this->indice = 0; //inicia en 0
	}
	void agregar(Pasajero* nuevoPasajero) {
		pasajeros[indice] = nuevoPasajero;
		indice++;
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			pasajeros[i]->mostrar();
		}
	}

};
	