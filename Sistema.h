#pragma once
#include <iostream>
#include <string>
#include "VectorClientes.h"
using namespace std;

class Sistema {
private:
	VectorCliente* listaClientes;
public:
	Sistema(int tamanioClientes) {
		this->listaClientes = new VectorCliente(tamanioClientes);
	}
	//
	void registrarClientes(Cliente * nuevoCliente) {
		listaClientes->agregar(nuevoCliente);
	}

	//
	void agregarPagoCliente(int ci, Pago* nuevoPago) {
		Cliente * auxCliente =listaClientes->existeCi(ci);
		if (auxCliente == nullptr) {
			cout << "Error!< no se encontro Cliente" << endl;
			return;
		}
		auxCliente->agregarPago(nuevoPago);
	}
	//
	void ProcesarTransacciones() {
		listaClientes->procesarPagosClientes();
	}

	//
	void mostrarClientes() {
		listaClientes->mostrar();
	}
	//
	double totalProcesado() {
		return listaClientes->sumarPagosClientes();
	}
};