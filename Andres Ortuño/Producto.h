#pragma once
#include <iostream>
using namespace std;

class Producto {
private:
	string nombre;
	int cantidad;
	float precio;
public:

	Producto() = default;

	Producto(const string& nombre, int cantidad, int precio)
		: nombre(nombre), cantidad(cantidad), precio(precio)
	{
	}
	int getCantidad() { return cantidad; }
	float getPrecio() { return precio; }
};