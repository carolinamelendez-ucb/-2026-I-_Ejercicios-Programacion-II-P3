#pragma once
#include <iostream>
#include <string>
#include "VectorPagos.h"
using namespace std;

class Cliente {
private:
	string nombre;
	int ci;
	int maxCantidadPagos;
	VectorPago* listaPagos;
public:
	Cliente() = default;

	Cliente(int ci,const string& nombre, int maxCantidadPagos)
		: nombre(nombre), maxCantidadPagos(maxCantidadPagos), ci(ci)
	{
		this->listaPagos = new VectorPago(maxCantidadPagos);
	}

	void agregarPago(Pago * nuevoPago) {

		listaPagos->agregar(nuevoPago);
	}
	void procesarPagos() {
		listaPagos->procesarPagos();
	}
	void mostrar() {
		cout << "Cliente: " << nombre << endl;
		cout<<"__________________________________________"<<endl;
		listaPagos->mostrar();
		
	}
	int getCi() {
		return ci;
	}
	double sumarPagos() {
		return listaPagos->sumarPagos();
	}
};