#pragma once
#include <iostream>
#include "VectorRepartidores.h"
#include "VectorPedidos.h"

class Sistema {
private:
	VectorRepartidores* repartidores;
	VectorPedidos* pedidos;
public:
	Sistema(int tamRepartidores, int tamPedidos) {
		this->repartidores = new VectorRepartidores(tamRepartidores);
		this->pedidos = new VectorPedidos(tamPedidos);
	}

	void agregarRepartidor(Repartidor* nuevoRepartidor) {
		if (repartidores->buscarCiDuplicado(nuevoRepartidor->getCi())) {
			cout << endl << "Ya existe un empleado con el Ci: " << nuevoRepartidor->getCi() << endl;
		}
		else {
			repartidores->agregar(nuevoRepartidor);
		}
	}

	void agregarPedido(Pedido* nuevoPedido) {
		if (pedidos->buscarCodigoDuplicado(nuevoPedido->getCodigo())) {
			cout << endl << "Ya existe un pedido con el codigo: " << nuevoPedido->getCodigo() << endl;
		}
		else {
			if (repartidores->buscarRepartidorPorZona(nuevoPedido->getZonaDeEntrega()) == nullptr) {
				cout << endl << "No se encontro a un repartidor de la misma zona para el pedido " << nuevoPedido->getCodigo() << ", asignando un repartidor con menor carga de trabajo" << endl;
				if (repartidores->buscarRepartidorPorCargaDeTrabajo() == nullptr) {
					cout << endl << "No se encontro un repartidor libre para el pedido "<<nuevoPedido->getCodigo()<<", el pedido queda sin repartidor" << endl;
					nuevoPedido->asignarRepartidor(nullptr);
				}
				else {
					cout << "Al pedido con codigo: " << nuevoPedido->getCodigo() << " se le asigno el repartidor: " << endl;
					repartidores->buscarRepartidorPorCargaDeTrabajo()->mostrar();
					nuevoPedido->asignarRepartidor(repartidores->buscarRepartidorPorCargaDeTrabajo());
				}
			}
			else {
				cout << endl << "Al pedido con codigo: " << nuevoPedido->getCodigo() << " se le asigno el repartidor: " << endl;
				repartidores->buscarRepartidorPorZona(nuevoPedido->getZonaDeEntrega())->mostrar();
				nuevoPedido->asignarRepartidor(repartidores->buscarRepartidorPorZona(nuevoPedido->getZonaDeEntrega()));
			}
			pedidos->agregar(nuevoPedido);
		}
	}

	void mostrarRepartidoresOrdenados() {
		repartidores->mostrarOrdenado();
	}

	void agregarProductoAPedido(int codigo, Producto* nuevoProducto) {
		pedidos->agregarProductoAPedido(codigo, nuevoProducto);
	}

	void calcularCostoTotalDelPedido(int codigo) {
		cout << "El costo total del pedido: " << codigo << " es: " << pedidos->calcularCostoTotalDelPedido(codigo) << endl;
	}

	void finalizarPedido(int codigo) {
		pedidos->terminarPedidoCodigo(codigo);
	}

	void calcularCostoTodosPedidos() {
		cout << "El costo total de todos los pedidos es: " << pedidos->calcularCostoTotalProductos();
	}
};