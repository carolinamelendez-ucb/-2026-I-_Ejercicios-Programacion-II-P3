#pragma once
#include <iostream>
#include <string>
#include "ProductoEnvasado.h"
using namespace std;
class ProductoPremium : public ProductoEnvasado {
public:
	ProductoPremium(string nombre, float precio, float peso) : ProductoEnvasado(nombre, precio, peso) {
	}
	float calcularPrecioFinal() override {
		float precio = ProductoEnvasado::calcularPrecioFinal();
		return precio * 1.15;
	}
};