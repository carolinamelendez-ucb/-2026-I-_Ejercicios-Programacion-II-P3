#pragma once
#include <iostream>
#include <string>
#include "Producto.h"

using namespace std;

class ListaProductos
{
private:
	Producto** listaProductos;
	int tamanio;
	int cantidad;
public:
	ListaProductos(int tamanio)
	{
		this->listaProductos = new Producto * [tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}
	void agregar(Producto* nuevoProducto)
	{
		if (cantidad < tamanio)
		{
			listaProductos[cantidad] = nuevoProducto;
			cantidad++;
		}
	}
	void mostrar()
	{
		for (int i = 0; i < cantidad; i++)
		{
			listaProductos[i]->mostrarInfo();
		}
	}
	void mostrarProductosRango(float minimo, float maximo)
	{
		for (int i = 0; i < cantidad; i++)
		{
			float precioFinal = listaProductos[i]->calcularPreciofinal();
			if (precioFinal >= minimo && precioFinal <= maximo)
			{
				cout << "nombre: " << listaProductos[i]->getNombre() << endl;;
				cout << "precio final: " << precioFinal << endl;
			}
		}
	}
	~ListaProductos()
	{
		for (int i = 0; i < cantidad; i++)
		{
			delete listaProductos[i];
		}
		delete[]listaProductos;
	}
	float calcularPromediosPrecios()
	{
		float suma = 0;
		for (int i = 0; i < cantidad; i++)
		{
			suma = suma + listaProductos[i]->calcularPreciofinal();
		}
		return suma/cantidad;
	}
};

