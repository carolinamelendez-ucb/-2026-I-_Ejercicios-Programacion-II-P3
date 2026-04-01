#pragma once
#include <iostream>
#include "Pedido.h"
using namespace std;

class VectorPedidos {
private:
	Pedido** pedidos;
	int tamanio;
	int indice;
public:
	VectorPedidos() = default;

	VectorPedidos(int tamanio)
		: tamanio(tamanio), indice(0)
	{
		this->pedidos = new Pedido * [tamanio];
	}
	
	void agregar(Pedido* nuevoPedido) {
		this->pedidos[indice] = nuevoPedido;
		indice++;
	}

	bool buscarCodigoDuplicado(int codigo) {
		for (int i = 0; i < indice; i++) {
			if (pedidos[i]->getCodigo() == codigo) {
				return true;
			}
		}
		return false;
	}

	void agregarProductoAPedido(int codigo, Producto* nuevoProducto) {
		for (int i = 0; i < indice; i++) {
			if (pedidos[i]->getCodigo() == codigo) {
				pedidos[i]->agregarProducto(nuevoProducto);
			}
		}
	}

	float calcularCostoTotalDelPedido(int codigo) {
		float total=0;
		for (int i = 0; i < indice; i++) {
			if (pedidos[i]->getCodigo() == codigo) {
				total += pedidos[i]->getCostoEnvio() + pedidos[i]->calcularCostoProductos();
				return total;
			}
		}
	}
	float calcularCostoTotalProductos() {
		float total = 0;
		for (int i = 0; i < indice; i++) {
			total+=pedidos[i]->getCostoEnvio() + pedidos[i]->calcularCostoProductos();
		}
		return total;
	}

	void terminarPedidoCodigo(int codigo) {
		for (int i = 0; i < indice; i++) {
			if (pedidos[i]->getCodigo() == codigo) {
				pedidos[i]->finalizarPedido();
			}
		}
	}
};