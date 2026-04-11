#pragma once
#include <iostream>
#include <string>
#include "VectorVehiculo.h"
class Cliente {
protected:
	int ci;
	string nombre;
	bool alquilerActivo;
	VectorVehiculo* historial;
public:
	Cliente(int ci, const string& nombre, int maxHistorial)
		: ci(ci), nombre(nombre)
	{
		this->alquilerActivo = false;
		this->historial = new VectorVehiculo(maxHistorial);
	}
	int getCi() {
		return ci;
	}
	string getNombre() {
		return nombre;
	}
	bool tieneAlquilerActivo() {
		return alquilerActivo;
	}
	void setAlquilerActivo(bool estado) {
		this->alquilerActivo = estado;
	}
	void agregarVehiculo(Vehiculo* nueVehiculo) {
		historial->agregar(nueVehiculo);
	}
	virtual double calcularDescuento() = 0;
	virtual void mostrar() {
		cout << "Cliente: " << nombre << endl;
	}
};