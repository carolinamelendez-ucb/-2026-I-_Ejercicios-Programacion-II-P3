#pragma once
#include <iostream>
#include <string>
#include "Vehiculo.h"
using namespace std;
class VectorVehiculo {
private:
	Vehiculo** vehiculos;
	int tamanio;
	int indice;
public:
	VectorVehiculo(int tamanio)
	{
		this->vehiculos = new Vehiculo * [tamanio];
		this->tamanio = tamanio;
		this->indice = 0;
	}
	void agregar(Vehiculo* nueVehiculos) {
		if (indice < tamanio) {
			vehiculos[indice] = nueVehiculos;
			indice++;
		}
		else {
			cout << "No se puede agregar mas vehiculos" << endl;
		}
	}
	Vehiculo* buscar(string placa) {
		for (int i = 0; i < indice; i++) {
			if (vehiculos[i]->getPlaca() == placa) {
				return vehiculos[i];
			}
		}
		return nullptr;
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			vehiculos[i]->mostrar();
			cout << endl;
		}
	}
};