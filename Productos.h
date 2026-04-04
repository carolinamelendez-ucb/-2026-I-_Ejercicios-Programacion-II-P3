#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Producto {
protected:
	string nombre;
	float precioBase;

public:
	Producto(const string& nombre, float precioBase)
		: nombre(nombre), precioBase(precioBase)
	{
	}
	virtual float calcularPrecio() = 0;
	virtual void mostrar() {
		cout << "Nombre del Producto: " <<nombre<< endl;
		cout << "Precio final: " << calcularPrecio() << endl;
	}
};