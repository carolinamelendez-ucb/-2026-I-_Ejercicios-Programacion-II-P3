#pragma once
#include <iostream>
#include <string>
#include "VectorPagos.h"
using namespace std;

class Cliente
{
private:
	string nombre;
	VectorPagos* listaPagos;
public:
	Cliente(const string& nombre,int tamanioPagos)
		: nombre(nombre)
	{
		this->listaPagos = new VectorPagos(tamanioPagos);
	}
	Cliente(const string& nombre, VectorPagos* listaPagos)
		: nombre(nombre), listaPagos(listaPagos)
	{}
	string getNombre()
	{
		return nombre;
	}
	void registrarPago(Pago* nuevoPago)
	{
		listaPagos->agregar(nuevoPago);
	}
	float calcularTotalCliente()
	{
		return listaPagos->calcularTotal();
	}
	void mostrar()
	{
		cout << "Cliente: " << nombre << endl;
		cout << "----------------------" << endl;
		listaPagos->mostrar();
	}
};

