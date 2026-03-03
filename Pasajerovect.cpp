#pragma once
#include "Pasajero.cpp"
class VectPasajero {
private:
	Pasajero** pasajero;
	int tamanio;
	int indice;
public:
	VectPasajero(int tamanio) {
		this->pasajero = new Pasajero * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void AgregarPasaj(Pasajero* nuevoPasaj) {
		pasajero[]
	}
};