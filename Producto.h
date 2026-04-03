#pragma once
#include <iostream>
#include <string>

using namespace std;

class Producto
{
protected:
	string nombre;
	int precioBase;
public:

	Producto(const string& nombre, int precioBase)
		: nombre(nombre), precioBase(precioBase)
	{}
	virtual float calcularPreciofinal() = 0;
	virtual void mostrarInfo() = 0;
	string getNombre()
	{
		return nombre;
	}
};