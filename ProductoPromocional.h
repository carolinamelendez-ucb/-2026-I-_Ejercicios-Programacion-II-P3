#pragma once
#include <iostream>
#include <string>
#include "Producto.h"

using namespace std;

class ProductoPromocional:public Producto
{
private:
	float descuentoPromocional;
	int cantidad;
public:
	ProductoPromocional(string nombre, float precioBase, float descuentoPromocional, int cantidad)
		:Producto(nombre, precioBase)
	{
		this->descuentoPromocional = descuentoPromocional;
		this->cantidad = cantidad;
	}

	float calcularPreciofinal()
	{
		if (cantidad > 5)
		{
			return precioBase - descuentoPromocional - (cantidad > 5 ? (precioBase * 0.05) : 0);
		}
		else
		{
			return precioBase - descuentoPromocional;
		}
	}
	void mostrarInfo()
	{
		cout << "nombre: " << nombre << endl;
		cout << "Precio base: " << precioBase << endl;
		cout << "cantidad: " << cantidad << endl;
		cout << "descuento Promocional: " << descuentoPromocional << endl;
		cout << "Total a pagar: " << calcularPreciofinal() << endl;
		cout << endl;
	}
};
