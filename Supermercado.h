#pragma once
#include <iostream>
#include <string>
#include "VectorProductos.h"
using namespace std;

class SuperMercado {
private:
	string nombre;
	string ubicacion;
	VectorProductos * listaProductos;
public:
	SuperMercado(string nombre, string ubicacion, int tamanioProductos) {
		this->nombre = nombre;
		this->ubicacion = ubicacion;
		this->listaProductos = new VectorProductos(tamanioProductos);
	}
	void agregarProductos(Producto * nuevoProducto) {
		listaProductos->agregar(nuevoProducto);
	}

	float promedio() {
		return listaProductos->calcularPromedio();
	}	
	void mostrar() {
		cout << "Supermercado: " << nombre << endl;
		cout << "Ubicacion: " << ubicacion << endl;
		cout << "Precio promedio: " << promedio() << endl;
	}
	VectorProductos* getListaProductos() {
		return listaProductos;
	}

	~SuperMercado() {
		delete listaProductos;
	}
};