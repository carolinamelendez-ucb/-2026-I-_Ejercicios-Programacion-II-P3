#pragma once
#include <iostream>
#include "Repartidor.h"
#include "VectorProductos.h"
using namespace std;

class Pedido {
private:
	int codigo;
	string direccion;
	string zonaDeEntrega;
	float costoEnvio;
	VectorProductos* productos;
	Repartidor* repartidorAsignado;
public:
	Pedido() = default;

	Pedido(int codigo, const string& direccion, const string& zonaDeEntrega, float costoEnvio, int cantidadProductos)
		: codigo(codigo), direccion(direccion), zonaDeEntrega(zonaDeEntrega), costoEnvio(costoEnvio)
	{
		this->productos = new VectorProductos(cantidadProductos);
		this->repartidorAsignado = nullptr;
	}

	void asignarRepartidor(Repartidor* repartidor) {
		this->repartidorAsignado = repartidor;
		if (repartidor != nullptr)
		{
			repartidorAsignado->cambiarEstado();
		}
		
	}

	void agregarProducto(Producto* nuevoProducto) {
		productos->agregar(nuevoProducto);
	}
	float calcularCostoProductos() {
		return productos->calcularCostoTotal();
	}

	void finalizarPedido() {
		if (repartidorAsignado == nullptr) {
			
		}
		else {
			repartidorAsignado->cambiarEstado();
			repartidorAsignado->aumentarNumeroPedidos();
		}
	}

	int getCodigo() { return codigo; }
	string getZonaDeEntrega() { return zonaDeEntrega; }
	float getCostoEnvio() { return costoEnvio; }
};