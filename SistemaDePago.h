#pragma once
#include <iostream>
#include <string>
#include "VectorClientes.h"
using namespace std;
class SistemaDePago {
private:
	VectorClientes* listaClientes;
public:
	SistemaDePago(int tamanioClientes) {
		this->listaClientes = new VectorClientes(tamanioClientes);
	}
	void registrarClientes(Cliente* nuevoCliente) {
		listaClientes->agregarCliente(nuevoCliente);
	}
	void agregarPagoCliente(int ci, Pago* nuevoPago) {
		Cliente* auxCliente = listaClientes->existeCI(ci);
		if (auxCliente == nullptr) {
			cout << "Error, no existe ese Cliente" << endl;
			return;
		}
		auxCliente->agregarPago(nuevoPago);
	}
	void procesarTransacciones() {
		listaClientes->procesarPagosClientes();
	}
	void mostrarClientes() {
		listaClientes->mostrarVectorClientes();
	}
	double totalProcesado() {
		return listaClientes->sumarPagosClientes();
	}
};