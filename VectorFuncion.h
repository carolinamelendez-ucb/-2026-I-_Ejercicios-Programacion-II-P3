#pragma once
#include <iostream>
#include <string>
#include "Funcion.h"
using namespace std;
class VectorFuncion {
private:
	int tamanio;
	int indice;
	Funcion** funciones;
public:
	VectorFuncion() = default;

	VectorFuncion(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->funciones = new Funcion * [tamanio];
	}
	void agregar(Funcion* nuevaFuncion) {
		if (indice < tamanio) {
			this->funciones[indice] = nuevaFuncion;
			indice++;
		}
		else {
			cout << "Ya no hay espacio para agregar mas funciones" << endl;
		}
		
	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			funciones[i]->mostrar();
		}
	}
	Funcion* getFuncion() {
		return funciones[indice-1];
	}
	void mostrarGananciaFun() {
		for (int i = 0; i < indice; i++) {
			cout<<"Ganacia de Funcion "<<funciones[i]->getId()<<" es: "<< funciones[i]->getGananciaFuncion()<< " bs"<<endl;
			cout << endl;
		}
	}
	//pelicula 
	int ganaciaPeli(Pelicula * peli) {
		int montoGanado=0;
		for (int i = 0; i < indice; i++) {
			if (funciones[i]->getPelicula()->getId() == peli->getId()) {
				montoGanado = montoGanado + funciones[i]->getGananciaFuncion();
			}
			
		}
		return montoGanado;
	}
	Funcion* buscarFuncion(int id) {
		for (int i = 0; i < indice; i++) {
			if (funciones[i]->getId() == id) {
				return funciones[i];
			}
		}
		return nullptr;
	}
	
};
