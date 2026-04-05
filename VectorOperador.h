#pragma once
#include <iostream>
#include <string>
#include "Operador.h"
using namespace std;
class VectorOperador {
private:
	int tamanio;
	int indice;
	Operador** operadores;
public:
	VectorOperador(int tamanio) {
		this->tamanio = tamanio;
		this->indice = 0;
		this->operadores = new Operador * [tamanio];
	}
	void agregar(Operador* nuevoOperador) {
		if (indice < tamanio) {
			operadores[indice] = nuevoOperador;
			indice++;
		}
	}
	void mostrar() {
		for (int i = 0; i < indice; i++)
		{
			operadores[i]->mostrar();
		}
	}
	Operador* existeOperador(Operador* auxOperador) {

		for (int i = 0; i < indice; i++) {
			if (operadores[i]->getCi() == auxOperador->getCi()) {
				return auxOperador;
			}
		}
		return nullptr;
	}
	Operador * buscarCi(int ci) {
		for (int i = 0; i < indice; i++) {
			if (operadores[i]->getCi() == ci) {
				return operadores[i];
			}
		}
		return nullptr;
	}

	float CostoGeneral() {
		float total=0;
		for (int i = 0; i < indice; i++) {
			total = total + operadores[i]->calcularCostoGenerado();
		}
		return total;
	}
	Operador* buscarMenor() {
		Operador* menor = nullptr;
		for (int i = 0; i < indice; i++) {
			if (menor == nullptr || operadores[i]->calcularCostoGenerado() < menor->calcularCostoGenerado()) {
				menor = operadores[i];
			}
		}
		return menor;
	}

};