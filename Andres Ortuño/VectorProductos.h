#pragma once
#include <iostream>
#include "Producto.h"

using namespace std;

class VectorProductos {
private:
	Producto** productos;
	int tamanio;
	int indice;
public:
	VectorProductos() = default;

	VectorProductos(int tamanio)
		: tamanio(tamanio), indice(0)
	{
		this->productos = new Producto * [tamanio];
	}

	void agregar(Producto* nuevoProducto) {
		this->productos[indice] = nuevoProducto;
		indice++;
	}

	float calcularCostoTotal() {
		float total=0;
		for (int i = 0; i < indice; i++) {
			total += productos[i]->getCantidad() * productos[i]->getPrecio();
		}
		return total;
	}
};