#pragma once
#include <iostream>
#include <string>
#include "Funcion.h"
using namespace std;
class VectorFunciones {
private:
	Funcion** funciones;
	int indice;
	int tamanio;
public:
	VectorFunciones(int tamanio) : tamanio(tamanio), indice(0) {
		funciones = new Funcion * [tamanio];
	}
	~VectorFunciones() {
		for (int i = 0; i < indice; i++) {
			delete funciones[i];
		}
		delete[] funciones;
	}
	void agregar(Funcion* nueFuncion) {
		if (buscar(nueFuncion->getCodigo()) != nullptr) {
			cout << "Codigo funcion duplicado" << endl;
			delete nueFuncion;
			return;
		}
		if (tamanio < indice) {
			funciones[indice] = nueFuncion;
			indice++;
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
	void mostrarVectorFunciones() {
		for (int i = 0; i < indice; i++) {
			funciones[i]->mostrarFuncion();
			cout << endl;
		}
	}
};