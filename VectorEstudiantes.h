#pragma once
#include "Estudiante.h"
#include "Pregrado.h"
#include "Postgrado.h"

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
	void agregarEstudiante(Estudiante* nuevoEstudiante) {
		if (indice < tamanio) {
			estudiantes[indice] = nuevoEstudiante;
			indice++;
		}
	}

	Estudiante* buscarCiDuplicado(int ci) {
		for (int i = 0; i < indice; i++) {
			if (estudiantes[i]->getCi() == ci) {
				return estudiantes[i];
			}
		}
		return nullptr;
	}

	void mostrar() {
		for (int i = 0; i < indice; i++) {
			
		estudiantes[i]->mostrar();
		cout << endl;
		}
	}
	void actualizarPagosEstudiantes() {
		for (int i = 0; i < indice; i++) {

			estudiantes[i]->calcularTotal();

		}
	}
	void masPaga() {
		float mayor = estudiantes[0]->getTotal();
		int pos;
		for (int i = 0; i < indice; i++) {
			if (estudiantes[i]->getTotal() > mayor) {
				mayor = estudiantes[i]->getTotal();
				pos = i;
			}
		}
		cout << "El alumno que mas paga es: " << endl;
			estudiantes[pos]->mostrar();
	}
};