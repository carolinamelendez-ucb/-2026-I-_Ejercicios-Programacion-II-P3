#pragma once
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

class ProductoEnvasado: public Producto {
private:
	double pesoKg;
public:
	ProductoEnvasado(string nom, double prB, double psKG)
		:Producto(nom, prB), pesoKg(psKG) {
	}

	double calcularPrecio() {
		return precioBase * 1.10 + (pesoKg * 2);
	}

	void mostrar() {
		cout << nombre << "(Envasado)  - Precio Final: $"<<calcularPrecioFinal()  << endl;
	}



};