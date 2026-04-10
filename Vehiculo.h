#pragma once
#include <iostream>
#include <string>

using namespace std;

class Vehiculo
{
protected:

	string placa;
	double costoBase;
	bool disponible;

public:

	Vehiculo(string placa, double costoBase)
	{
		this->costoBase = costoBase;
		this->placa = placa;
		this->disponible = true;
	}

	string getPlaca()
	{
		return placa;
	}

	bool getEstaDisponible()
	{
		return disponible;
	}

	void setDisponible(bool variable)
	{
		this->disponible = variable;
	}

	virtual double calcularCosto(int dias) = 0;

	virtual void mostrar()
	{
		cout << "Placa " << placa << endl;
		cout << "Costo Base" << costoBase << endl;
		cout << "Disponible" << (disponible ? "SI" : "NO") << endl;
	}


};