#pragma once
#include <iostream>
#include <string>
using namespace std;
class Vehiculo {
protected:
	string placa;
	double costoBase;
	bool disponible;
public:
	Vehiculo(const string& placa, double costoBase)
		: placa(placa), costoBase(costoBase)
	{
		this->disponible = true;
	}
	string getPlaca() {
		return placa;
	}
	double getCostoBase() {
		return costoBase;
	}
	bool estaDisponible() {
		return disponible;
	}
	void setDisponible(bool disponible) {
		this->disponible = disponible;
	}
	virtual double calcularCosto(int dias) = 0;
	virtual ~Vehiculo() {}
	virtual void mostrar() {
		cout << "Placa: " << placa << endl;
		cout << "Costo Base: " << costoBase << endl;
		cout << "Disponible: ";
		if (disponible) {
			cout << "Sí" << endl;

		}
		else {
			cout << "No" << endl;
		}
	}
};