#pragma once
#include <iostream>
#include <string>
#include "Estudiante.h"

using namespace std;

class VectorEstudiantes {
private:
	int tamanio;
	int indice;
	Estudiante** estudiantes;
public:
	VectorEstudiantes(int tamanio)
		: tamanio(tamanio), indice(0)
	{
		this->estudiantes = new Estudiante * [tamanio];
	}

	void agregar(Estudiante* estudianteNuevo) {
		if (indice > tamanio) {
			cout << "No se pueden agregar mas" << endl;
		}
		else {
			estudiantes[indice] = estudianteNuevo;
			indice++;
		}
	}

	Estudiante* buscar(int ci) {
		for (int i = 0;i != indice;i++) {
			if (ci == estudiantes[i]->getCi()) {
				return estudiantes[i];
			}
		}
		return nullptr;
	}

	void mostrarPorLibro(int codigo) {
		for (int i = 0;i != indice;i++) {
			if (codigo == estudiantes[i]->getCodigoLibro()) {
				estudiantes[i]->mostrar();
			}
		}
	}
};
