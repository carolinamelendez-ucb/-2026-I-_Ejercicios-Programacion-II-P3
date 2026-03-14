#pragma once
#include <iostream>
#include <string>
#include "Funcion.h"
using namespace std;

class FuncionVector {
private:
	Funcion** funciones;
	int indice;
	int tamanio;
public:
	FuncionVector(int tamanio) {
		this->funciones = new Funcion * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregarFuncion(Funcion* newFuncion) {
		funciones[indice] = newFuncion;
		indice++;
	}
	Funcion* getFuncion(int i) {
		return funciones[i];
	}
	void mostrarFunciones() {
		for (int i = 0; i < indice; i++) {
			cout << "== FUNCION " << i + 1 << " ==" << endl;
			funciones[i]->mostrar();
			cout << endl;
		}
	}
	void TotalPorFuncion() {
		for (int i = 0; i < indice; i++) {
			cout << "Funcion " << i + 1 << " Ganancia: " << funciones[i]->ganancia() << endl;
		}
	}
	void TotalPorPelicula(string nombre) {
		float total = 0;
		for (int i = 0; i < indice; i++) {
			if (funciones[i]->getPelicula()->getTitulo() == nombre) {
				total = total + funciones[i]->ganancia();
			}
		}
		cout << "Ganancia total de " << nombre << " : " << total << endl;
	}
};
