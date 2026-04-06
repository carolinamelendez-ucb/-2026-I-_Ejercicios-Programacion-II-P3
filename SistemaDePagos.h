#pragma once
#include <iostream>
#include <string>
#include "VectorClientes.h"
using namespace std;

class SistemaDePagos
{
private:
	VectorClientes* listaClientes;
public:
	SistemaDePagos(int tamanioClientes)
	{
		listaClientes = new VectorClientes(tamanioClientes);
	}
	void registrarClientes(Cliente* nuevoCliente)
	{
		Cliente* nombreEncontrado = listaClientes->buscarPorNombre(nuevoCliente->getNombre());
		if (nombreEncontrado == nullptr)
		{
			listaClientes->agregar(nuevoCliente);
		}
		
	}
	void mostrarClientes()
	{
		listaClientes->mostrar();
	}
	void registrarPagoClinetes(string nombreCliente, Pago* nuevoPago)
	{
		Cliente* clienteEncontrado = listaClientes->buscarPorNombre(nombreCliente);
		if (clienteEncontrado != nullptr)
		{
			clienteEncontrado->registrarPago(nuevoPago);
		}
	}
	float calcularTotalSistema()
	{
		return listaClientes->calcularTotalGeneral();
	}
	~SistemaDePagos()
	{
		delete listaClientes;
	}


};