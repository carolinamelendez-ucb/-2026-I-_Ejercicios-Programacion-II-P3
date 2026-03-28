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
		this->tamanio = tamanio;
		this->indice = 0;
		this->funciones = new Funcion * [tamanio];
	}
	void agregar(Funcion* newFuncion) {
		for (int i = 0; i < indice; i++) {
			if (funciones[i]->getCodigo() == newFuncion->getCodigo()) {
				cout << "La funcion tiene el codigo duplicado" << endl;
				return;
			}
		}
		if (indice < tamanio) {
			funciones[indice] = newFuncion;
			indice++;
		}
		else {
			cout << "No hay espacio" << endl;
		}
	}
	Funcion* buscar(int codigo) {
		for (int i = 0; i < indice; i++) {
			if (funciones[i]->getCodigo() == codigo) {
				return funciones[i];
			}
		}
		return nullptr; 
	}
};
