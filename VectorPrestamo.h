#pragma once
#include <iostream>
#include <string>
#include "Prestamo.h"
using namespace std;
class VectorPrestamo {
private:
	int tamanio;
	int indice;
	Prestamo** prestamos;
public:

	VectorPrestamo() = default;

	VectorPrestamo(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->prestamos = new Prestamo * [tamanio];
	}
	void agregar(Prestamo* nuevoPrestamo) {
		if (indice < tamanio) {
			prestamos[indice] = nuevoPrestamo;
			indice++;
		}
		else {
			cout << "No es posible procesar prestamo, Error" << endl;
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			prestamos[i]->mostrar();
		}
	}

	Prestamo* getPrestamo(int ci, int codigo) {
		for (int i = 0; i < indice; i++) {
			if (prestamos[i]->getCiStudent() == ci && prestamos[i]->getCodigoLibro()==codigo) {
				return prestamos[i];
			}
		}
		return nullptr;
	}
	~VectorPrestamo() {
		for (int i = 0; i < indice; i++) {
			delete prestamos[i];
		}
		delete[] prestamos;
	}
};