#pragma once
#pragma once
#include <iostream>
#include<string>
#include"Producto.h"
#include"listaproducto.h"
using namespace std;
class Supermercado {
private:
	string nombre;
	string ubicacion;
	ListaDeProductos lista;
public:
	Supermercado(const string& nombre, const string& ubicacion)
		: nombre(nombre), ubicacion(ubicacion), lista(10)
	{
	}
	bool tieneMayorPrecioPromedioQue(Supermercado* otro) {
		return lista.promedio() > otro->lista.promedio();
	}
	void agregarProducto(Producto* p) {
		lista.AgregarProducto(p);
	}
	void mostrarDatos() {
		cout << nombre << " - " << ubicacion << endl;
		cout << "Promedio: " << lista.promedio() << endl;
	}
	void mostrarRango(float min, float max) {
		lista.mostrarRango(min, max);
	}
};