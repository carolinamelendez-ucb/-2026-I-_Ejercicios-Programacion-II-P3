#pragma once
#include <iostream>
#include <string>
#include "Proyecto.h"

class VectorProyecto {
private:
	int tamanio;
	int indice;
	Proyecto** proyectos;
public:

	VectorProyecto(int tamanio)
		: tamanio(tamanio)
	{
		this->indice = 0;
		this->proyectos = new Proyecto * [tamanio];
	}
	void agregar(Proyecto* nuevoProyecto) {
		if (indice < tamanio) {
			proyectos[indice] = nuevoProyecto;
			indice++;
		}
		else {
			cout << "Ya no se pueden agregar mas proyectos, se alcanzo el limite!" << endl;
		}

	}
	void mostrar() {
		for (int i = 0; i < indice; i++) {
			proyectos[i]->mostrarInformacion();
		}
	}
	Proyecto* buscarProyecto(Proyecto* existeProyecto) {
		for (int i = 0; i < indice; i++) {
			if (proyectos[i]->getCodigo() == existeProyecto->getCodigo()) {
				return proyectos[i];
			}
		}
		return nullptr;
	}

	Proyecto* mayorCosto() {
		Proyecto* mayor = nullptr;
		for (int i = 0; i < indice; i++) {

			if (mayor == nullptr || proyectos[i]->calcularCosto() > mayor->calcularCosto()) {
				mayor = proyectos[i];
			}
		}
		return mayor;
	}

	~VectorProyecto() {
		for (int i = 0; i < indice; i++) {
			delete proyectos[i];
		}
		delete[] proyectos;
	}
};