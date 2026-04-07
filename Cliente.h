#pragma once
#include <iostream>
#include <string>
#include "Pago.h"
#include "ListaPagos.h"
using namespace std;

class Cliente {
private:
	VectoListaPagos* listapagos;
public:
	Cliente(int capacidad) {
		listapagos = new VectoListaPagos(capacidad);
	}

	void agregarPago(Pago* pago) {
		listapagos->agregarLista(pago);
	}

	double procesarPagos() {
		return listapagos->procesarTodo();
	}

};