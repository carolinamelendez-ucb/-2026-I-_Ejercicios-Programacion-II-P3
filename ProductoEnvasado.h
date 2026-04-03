#pragma once
#include <iostream>
#include <string>
#include "Producto.h"

using namespace std;

class ProductoEnvasado: public Producto
{
private:
	float pesoKg;
public:
	ProductoEnvasado(string nombre, int precioBase, float pesoKg)
		:Producto(nombre, precioBase)
	{
		this->pesoKg = pesoKg;
	}
	float calcularPreciofinal()
	{
		return precioBase * 1.10 + (pesoKg * 2);
	}
	void mostrarInfo()
	{
		cout << "nombre: " << nombre << endl;
		cout << "Precio base: " << precioBase << endl;
		cout << "Peso en kg: " << pesoKg << endl;
		cout << "Total a pagar: " << calcularPreciofinal() << endl;
		cout << endl;
	}
};


