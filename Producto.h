#pragma once
#include <iostream>
#include <string>
using namespace std;
class Producto {
protected:
	string nombreProd;
	float precioBase;
public:
	Producto(string nombre, float precio) {
		this->nombreProd = nombre;
		this->precioBase = precio;
	}
	string getNombre() {
		return nombreProd;
	}
	virtual float calcularPrecioFinal() = 0;
	virtual void mostrarInformacion() {
		cout << nombreProd << " / " << "Precio final Bs. " << calcularPrecioFinal() << endl;
		cout << endl;
	}
	virtual ~Producto() {}
};