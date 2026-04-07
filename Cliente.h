#pragma once
#include <iostream>
#include <string>
#include "VectorPagos.h"
using namespace std;
class Cliente {
private:
	string nombre;
	int ci;
	int maxCantPagos;
	VectorPago* listaPagos;
public:
	Cliente(const string& nombre, int ci, int maxCantPagos)
		: nombre(nombre), ci(ci), maxCantPagos(maxCantPagos)
	{
		this->listaPagos = new VectorPago(maxCantPagos);
	}
	Cliente() = default;
	void agregarPago(Pago* nuevoPago) {
		listaPagos->agregarPago(nuevoPago);
	}
	void procesarPagos() {
		listaPagos->procesarPagos();
	}
	void mostrarCliente() {
		cout << "Cliente: " << nombre << endl;
		cout << "______________________________" << endl;
		listaPagos->mostrarVectorPagos();
	}
	int getCi() {
		return ci;
	}
	double sumarPagos() {
		return listaPagos->sumarPagos();
	}
};