#pragma once
#include <iostream>
#include <string>
#include "ListaProductos.h"

using namespace std;

class Supermercado
{
private:
	string nombre;
	string ubicacion;
	ListaProductos* lista;
public:
	Supermercado(const string& nombre, const string& ubicacion, int tamanioSupermercado)
		: nombre(nombre), ubicacion(ubicacion), lista(lista)
	{
		this->lista = new ListaProductos(tamanioSupermercado);
	}
	Supermercado(const string& nombre, const string& ubicacion, ListaProductos* lista)
		: nombre(nombre), ubicacion(ubicacion), lista(lista)
	{}
	~Supermercado()
	{
		delete lista;
	}
	void registrarProducto(Producto* nuevoProducto)
	{
		lista->agregar(nuevoProducto);
	}
	void mostrarProductosEnRango(float minimo, float maximo)
	{
		cout << "Supermercado: " << nombre << endl;
		cout << "Ubicacion: " << ubicacion << endl;
		cout << "Productos dentro del rango " << minimo << " - " << maximo << endl;
		lista->mostrarProductosRango(minimo, maximo);
	}
	bool mayorPrecioPromedio(Supermercado* otroSuper)
	{
		return lista->calcularPromediosPrecios() > otroSuper->lista->calcularPromediosPrecios();
	}
	void mostrarDatos()
	{
		cout << "Nombre: " << nombre << endl;
		cout << "Ubicacion: " << ubicacion << endl;
		cout << "Precio promedio: " << lista->calcularPromediosPrecios() << endl;
	}
};

