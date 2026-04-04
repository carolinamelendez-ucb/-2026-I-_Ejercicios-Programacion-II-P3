#pragma once
#include <iostream>
#include <string>
#include <algorithm>

#include "Productos.h"
using namespace std;



class ProductoFresco : public Producto {
private:
	int diasRestantes;
	
public:

	ProductoFresco(string nombre, float precio, int diasRestantes)
		:Producto(nombre, precio) {
		this->diasRestantes = diasRestantes;
	}

	float calcularPrecio() override {
		return precioBase * (1 - min(0.05f * (7 - diasRestantes), 0.3f));
	}

};