#pragma once
#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;
class ListaProductos {
private:
	Producto** productos;
	int cantidadActual;
	int capacidadMaxima;
public:
	ListaProductos(int capacidad) {
		capacidadMaxima = capacidad;
		cantidadActual = 0;
		productos = new Producto * [capacidad];
	}
	void agregarProducto(Producto* producto) {
		if (cantidadActual < capacidadMaxima) {
			productos[cantidadActual++] = producto;
		}
	}
	void mostrarProductosPorRango(float minimo, float maximo) {
		cout << "Productos en rango" << endl;
		for (int i = 0; i < cantidadActual; i++) {
			float precio = productos[i]->calcularPrecioFinal();
			if (precio >= minimo && precio <= maximo) {
				productos[i]->mostrarInformacion();
			}
		}
	}
	float calcularPromedioPrecios() {
		if (cantidadActual == 0) {
			return 0;
		}
		float suma = 0;
		for (int i = 0; i < cantidadActual; i++) {
			suma = suma + productos[i]->calcularPrecioFinal();
		}
		return suma / cantidadActual;
	}
	void mostrarTodos() {
		for (int i = 0; i < cantidadActual; i++) {
			productos[i]->mostrarInformacion();
		}
	}
};