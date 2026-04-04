#pragma once
#include <iostream>
#include <string>
#include "Productos.h"
using namespace std;

class VectorProductos {
private:
	int tamanio;
	int indice;
	Producto** productos;
public:
	VectorProductos(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->productos = new Producto * [tamanio];
	}
	void agregar(Producto * nuevoProducto) {
		if (indice < tamanio) {
			productos[indice] = nuevoProducto;
			indice++;
		}
	}
	void mostrarPrecioRango(float minimo, float maximo) {

		for (int i = 0; i < indice; i++) {
			float precio = productos[i]->calcularPrecio();

			if (precio >= minimo && precio <= maximo) {
				productos[i]->mostrar();
			}
		}
	}
	float calcularPromedio() {
		if (indice == 0) {
			return 0;
		}
		float total=0;
		for (int i = 0; i < indice; i++) {
			total = total + productos[i]->calcularPrecio();
		}
		return total / indice;
	}
	~VectorProductos() {
		for (int i = 0; i < indice; i++) {
			delete productos[i];
		}
		delete[] productos;
	}
};