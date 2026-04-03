#pragma once
#include <iostream>
#include <string>
#include "Producto.h"

using namespace std;

class ProductoPremium:public Producto
{
private:
	float pesoKg;
public:
	ProductoPremium(string nombre, int precioBase, float pesoKg)
		:Producto(nombre, precioBase)
	{
		this->pesoKg = pesoKg;
	}

	float calcularPreciofinal()
	{
		return (precioBase * 1.10 + (pesoKg * 2)) * 1.15;
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


