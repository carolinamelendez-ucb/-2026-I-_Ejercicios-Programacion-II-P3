#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
using namespace std;

class VectorPagos
{
private:
	Pago** lista;
	int cantidad;
	int tamanio;
public:
	VectorPagos(int tamanio)
	{
		this->lista = new Pago * [tamanio];
		this->cantidad = 0;
		this->tamanio = tamanio;
	}
	void agregar(Pago* nuevoPago)
	{
		if (cantidad < tamanio)
		{
			lista[cantidad] = nuevoPago;
			cantidad++;
		}
		else
		{
			cout << "no hay espacio para registrar pagos" << endl;
		}
	}
	float calcularTotal()
	{
		float suma = 0;
		for (int i = 0; i < cantidad; i++)
		{
			suma = suma + lista[i]->calcularPago();
		}
		return suma;
	}
	void mostrar()
	{
		for (int i = 0; i < cantidad; i++)
		{
			cout << "Pago " << i + 1 << ":" << endl;
			lista[i]->mostrar();
			cout << endl;
			
		}
	}
	~VectorPagos()
	{
		for (int i = 0; i < cantidad; i++)
		{
			delete lista[i];
		}
		delete[]lista;
	}
};

