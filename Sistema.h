#pragma once
#include <iostream>
#include <string>
#include "VectorListaProductos.h"
using namespace std;

class Supermercado {
private:
	VectorProducto* listaProductos;
	string nombre;
	string ubicacion;
	int capacidad;
public:
	Supermercado(string nom, string ubi, int cant)
		:nombre(nom), ubicacion(ubi) {
		listaProductos = new VectorProducto(cant);
	}

	void agregarProducto(Producto* nvoP) {
		listaProductos->agregarProd(nvoP);
	}


	double calcularPromedio() {

	}

};
