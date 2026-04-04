#pragma once
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

class VectorProducto {
private:
	int tamanio;
	int cantidad;
	Producto** listaProductos;
public:
	VectorProducto(int tam) {
		this->cantidad = 0;
		this->tamanio = tam;
		this->listaProductos = new Producto * [tam];
	}

	void agregarProd(Producto* nvoProd) {
		if (cantidad < tamanio) {
			listaProductos[cantidad] = nvoProd;
			cantidad++;
		}
		else {
			cout << "No se pueden agregar mas productos" << endl;
		}
	}

	void mostrar() {
		for (int i = 0;i < cantidad;i++) {
			listaProductos[i]->mostrarProd();
		}
	}

	int getCantidad() {
		return cantidad;
	}

	

};

