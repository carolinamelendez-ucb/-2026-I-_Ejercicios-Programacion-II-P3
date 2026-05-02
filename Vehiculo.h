#pragma once
#include <iostream>
#include <string>
#include "Espacio.h"
using namespace std;
class Vehiculo {
private:
	string placa;
	string marca;
	string modelo;
	string tipo;
	Espacio* espacioAsigando;

public:

	Vehiculo(const string& placa, const string& marca, const string& modelo, const string& tipo)
		: placa(placa), marca(marca), modelo(modelo), tipo(tipo)
	{
		this->espacioAsigando = nullptr;
	}

	void mostrar() {
		cout << "Placa: " << placa << endl;
		cout << "Marca: " << marca << endl;
		cout << "Modelo: " << modelo << endl;
		cout << "Tipo: " << tipo << endl;
		cout << "Espacio Asigando: " << endl; 
		espacioAsigando->mostrar(); 
	}
	string getPlaca() {
		return placa;
	}

	static bool compararPlaca(Vehiculo * vehiculo, string placa) {
		return vehiculo->placa == placa;
	}
	bool VehiculoYaEstaAsignado() {
		return espacioAsigando != nullptr;
	}

	static bool compararTieneEspacio(Vehiculo* vehiculo , bool tieneEspacio ) {
		return vehiculo->VehiculoYaEstaAsignado() == tieneEspacio;
	}
	void AsignarEspacioAVehiculo(Espacio * espacioAsigando) {
		this->espacioAsigando = espacioAsigando;
	}
	static bool ordenarPorMarca(Vehiculo * vehiculoA, Vehiculo* vehiculoB) {
		return vehiculoA->marca > vehiculoB->marca;
	}
};