#pragma once
#include <iostream>
#include<string>
#include"Operador.h"
class VectorOperador {
private:
	Operador** lista;
	int cantidad;
	int tamanio;
public:
	VectorOperador(int tamanio) {
		this->cantidad = 0;
		this->tamanio = tamanio;
		this->lista = new Operador * [tamanio];
	}
	void Agregar(Operador* NuevoOperador) {
		for (int i=0; i < cantidad; i++) {
			if (lista[i]->getCi() == NuevoOperador->getCi()) {
				cout << "El ci esta duplicado" << endl;
				return;
			}
		}
		if (cantidad < tamanio) {
			lista[cantidad] = NuevoOperador;
			cantidad++;
		}
	}
	Operador* buscar(int ci) {
		for (int i = 0; i < cantidad; i++) { 
			if (lista[i]->getCi() == ci) {
				return lista[i];
			}
		}
		return nullptr;
	}
	float totalDecostos() {
		float suma = 0;
		for (int i = 0; i < cantidad; i++) {
			suma = suma + lista[i]->calcularCosto();
		}
		return suma;
	}
	Operador* menorCosto() {
		Operador* menor = nullptr;

		for (int i = 0; i < cantidad; i++) {
			float costo = lista[i]->calcularCosto();
			if (costo > 0) { 
				if (menor == nullptr || costo < menor->calcularCosto()) {
					menor = lista[i];
				}
			}
		}
		return menor;
	}
	void mostrarTodo() {
		for (int i = 0; i < cantidad; i++) {
			lista[i]->mostrar();
		}
	}
};