#pragma once
#include <iostream>
#include <string>
#include "VectorVehiculos.h"

class Cliente
{
protected:
	int ci;
	string nombre;
	bool alquilerActivo;
	VectorVehiculo* historial;
public:
	Cliente(int ci, string nombre, int maxHistorial)
	{
		this->ci = ci;
		this->nombre = nombre;
		this->alquilerActivo = false; // inactivo osea que no se esta prestandose 
		this->historial = new VectorVehiculo  (maxHistorial);
	}

	int getCi()
	{
		return ci;
	}

	bool tieneAlquilerActivo()
	{
		return alquilerActivo;
	}

	void setAlquilerActivo(bool estado)
	{
		this->alquilerActivo = estado;
	}

	void agregarVehiculo(Vehiculo* nuevoVehiculo)
	{
		historial->agregar(nuevoVehiculo);
	}

	virtual double calcularDescuento() = 0;

	virtual void mostrar()
	{
		cout << "Cliente : " << nombre << endl;
	}


};