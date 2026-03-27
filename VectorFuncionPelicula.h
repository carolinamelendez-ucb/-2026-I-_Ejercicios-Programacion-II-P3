#pragma once
#include <iostream>
#include <string>
#include "FuncionPelicula.h"

using namespace std;

class VectorFuncionPelicula {
private:
	int tamanio;
	int indice;
	FuncionPelicula** funciones;
public:

	VectorFuncionPelicula() = default;

	VectorFuncionPelicula(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->funciones = new FuncionPelicula * [tamanio];
	}


	void agregar(FuncionPelicula *nuevoFuncion) {
		if (indice < tamanio) {
			funciones[indice] = nuevoFuncion;
			indice++;
		}
		else {
			cout << "Ya no se pueden registrar mas Funciones" << endl;
		}
	}
	void mostrar() {
		for (int i = 0;i < indice; i++) {
			funciones[i]->mostrar();
		}
	}

	bool buscarCodigoExistente(int codigo) {
		for (int i = 0; i < indice; i++) {
			if (funciones[i]->getCodigo() == codigo) {
				return true;
			}
		}
		return false;
	}

	FuncionPelicula* getFuncion(int codigo) {

		for (int i = 0; i < indice; i++) {
			if (funciones[i]->getCodigo() == codigo) {
				return funciones[i];
			}
		}
		return nullptr ;
	}
	~VectorFuncionPelicula() {
		for (int i = 0; i < indice; i++) {
			delete funciones[i];
		}
		delete[]funciones;
	}

};