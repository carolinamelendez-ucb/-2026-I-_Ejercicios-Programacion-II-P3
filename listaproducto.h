#pragma once
#pragma once
#include <iostream>
#include<string>
#include"Producto.h"
using namespace std;
class ListaDeProductos {
private:
	Producto** lista;
	int cantidad;
	int tamanio;
public:
	ListaDeProductos(int tam) {
		this->cantidad = 0;
		this->tamanio = 0;
		this->lista = new Producto * [tamanio];
	}
	void AgregarProducto(Producto* NuevoProducto) {
		if (cantidad < tamanio) {
			lista[cantidad++] = NuevoProducto;
		}
	}
	void mostrarRango(float min, float max) {
		for (int i = 0; i < cantidad; i++) {
			float precio = lista[i]->calcularpreciofinal();
			if (precio >= min && precio <= max) {
				cout << lista[i]->getNombre() << "Precio: " << precio << endl;
			}
		}
	}
	float promedio() {
		if (cantidad == 0)return 0;
		float suma = 0;
		for (int i = 0; i < cantidad; i++) {
			suma += lista[i]->calcularpreciofinal();
		}
		return suma / cantidad;
	}
};