#pragma once
#include <iostream>
#include <string>
using namespace std;

class Producto {
protected:
	string nombre;
	double precioBase;
private:

public:

	Producto(const string& nombre, int precioBase)
		: nombre(nombre), precioBase(precioBase)
	{
	}

	void mostrarProd() {
		cout << "Nombre producto: "<<nombre << endl;
		cout << "Precio: $"<<precioBase << endl;
	}


	string getNombre() {
		return nombre;
	}

	double getPrecio() {
		return precioBase;
	}

	virtual double calcularPrecioFinal() = 0;

};