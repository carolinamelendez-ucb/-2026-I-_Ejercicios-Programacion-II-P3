#pragma once
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

class ProductoFresco: public Producto
{
private:
	int diasRestantes;
public:
	ProductoFresco(string nombre, int precioBase, int diasRestantes)
		:Producto(nombre, precioBase)
	{
		this->diasRestantes = diasRestantes;
	}
	float calcularPreciofinal()
	{
		float totalPago = 0;
		if (diasRestantes < 7)
		{
			return totalPago= precioBase * (1 - min(0.05 * (7 - diasRestantes), 0.3));
		}
		else
		{
			return totalPago=totalPago + precioBase;
		}
	}
	void mostrarInfo()
	{
		cout << "nombre: " << nombre << endl;
		cout << "Precio base: " << precioBase << endl;
		cout << "Dias restantes: " <<diasRestantes<< endl;
		cout << "Total a pagar: " << calcularPreciofinal() << endl;
		cout << endl;
	}
};

