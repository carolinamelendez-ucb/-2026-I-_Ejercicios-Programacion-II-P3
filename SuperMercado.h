#pragma once
#include <iostream>
#include <string>
#include "ListaProductos.h"
using namespace std;
class SuperMercado {
private:
	string nombreSupermercado;
	string ubicacionGeografica;
	ListaProductos* listaProductos;
public:
	SuperMercado(string nombre, string ubicacion) {
		nombreSupermercado = nombre;
		ubicacionGeografica = ubicacion;
		listaProductos = new ListaProductos(20);
	}
	void agregarProducto(Producto* producto) {
		listaProductos->agregarProducto(producto);
	}
	bool tienePrecioPromedioMayor(SuperMercado* otro) {
		return listaProductos->calcularPromedioPrecios() > otro->listaProductos->calcularPromedioPrecios();
	}
	void mostrarDatos() {
		cout << "Supermercado: " << nombreSupermercado << endl;
		cout << "Ubicacion: " << ubicacionGeografica << endl;
		cout << endl;
		listaProductos->mostrarTodos();
	}
	void mostrarProductosPorRango(float min, float max) {
		listaProductos->mostrarProductosPorRango(min, max);
	}
};