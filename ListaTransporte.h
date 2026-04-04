#pragma once
#include <iostream>
#include <string>
#include "Transporte.h"
using namespace std;

class listaTransporte {
private:
	int tamanio;
	int cantidad;
	Transporte** listaTrans;
public:
	listaTransporte(int tam) {
		this->cantidad = 0;
		this->tamanio = tam;
		this->listaTrans = new Transporte * [tam];
	}

	void agregar(Transporte* nvoTransporte){
		if (cantidad < tamanio) {
			listaTrans[cantidad] = nvoTransporte;
			cantidad++;
		}
		else {
			cout<<"No se pueden agregar mas vehiculos"<< endl;
		}
	}

	void calcularCostos(double distancia){
		for (int i = 0;i < cantidad;i++) {
			double costo = listaTrans[i]->calcularCosto(distancia);
			cout << listaTrans[i]->getNombre() << " (" << listaTrans[i]->getTipo() << ")" << endl;
			cout << "$"<<costo << endl;
		}
	}

	int getCantidad() {
		return cantidad;
	}



};