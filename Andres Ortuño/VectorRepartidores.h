#pragma once
#include <iostream>
#include "Repartidor.h"
using namespace std;

class VectorRepartidores {
private:
	Repartidor** repartidores;
	int tamanio;
	int indice;
public:
	VectorRepartidores() = default;

	VectorRepartidores(int tamanio)
		: tamanio(tamanio), indice(0)
	{
		this->repartidores = new Repartidor * [tamanio];
	}

	void agregar(Repartidor* nuevoRepartidor){
		this->repartidores[indice] = nuevoRepartidor;
		indice++;
	}

	bool buscarCiDuplicado(int ci){
		for (int i = 0; i < indice; i++) {
			if (repartidores[i]->getCi() == ci) {
				return true;
			}
		}
		return false;
	}

	void mostrarOrdenado() {
		Repartidor** copia = new Repartidor * [indice];
		for (int i = 0; i < indice; i++) {
			copia[i] = repartidores[i];
		}

		//Ordenamiento burbuja
		for (int i = 0; i < indice; i++) {
			for (int j = 0; j < i; j++) {
				if (copia[j]->getCantidadPedidosEntregados() < copia[i]->getCantidadPedidosEntregados()) {
					Repartidor* auxiliar = copia[i];
					copia[i] = copia[j];
					copia[j] = auxiliar;
				}
			}
		}

		cout << "Los repartidores ordenados por cantidad de pedidos son: " << endl;
		for (int i = 0; i < indice; i++) {
			cout << endl;
			copia[i]->mostrar();
		}
	}

	Repartidor* buscarRepartidorPorZona(string zonaABuscar) {
		for (int i = 0; i < indice; i++) {
			if (repartidores[i]->getZonaAsignada() == zonaABuscar && repartidores[i]->getEstado()) {
				return repartidores[i];
			}
		}
		return nullptr;
	}

	Repartidor* buscarRepartidorPorCargaDeTrabajo() {
		int cantidadActual = 0;
		bool encontrado = false;
		//Buscar el mayor numero de pedidos entregados para no tener problemas despues
		for (int i = 0; i < indice; i++) {
			if (repartidores[i]->getCantidadPedidosEntregados() > cantidadActual) {
				cantidadActual = repartidores[i]->getCantidadPedidosEntregados();
			}
		}
		int indiceActual = 0;
		for (int i = 0; i < indice; i++) {
			if (repartidores[i]->getCantidadPedidosEntregados() <= cantidadActual && repartidores[i]->getEstado()) {
				cantidadActual = repartidores[i]->getCantidadPedidosEntregados();
				indiceActual = i;
				encontrado = true;
			}
		}
		if (encontrado) {
			return repartidores[indiceActual];
		}
		else {
			return nullptr;
		}
	}
};

