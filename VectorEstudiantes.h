#pragma once
#include "Estudiante.h"

class VectorEstudiantes {
private:
	int indice;
	int tamanio;
	Estudiante** arrayEstudiantes;
public:
	VectorEstudiantes(int tamanio) {
		this->indice = 0;
		this->tamanio = tamanio;
		this->arrayEstudiantes = new Estudiante * [tamanio];
	}

	void agregar(Estudiante* nuevoEstudiante) {
		if (indice < tamanio) {
			arrayEstudiantes[indice] = nuevoEstudiante;
			indice++;
		}
		else {
			cout << "Curso esta lleno" << endl;
		}
	}

	Estudiante* buscarPorCi(string ciBuscado) {
		for (int i = 0; i < indice; i++) {
			if (arrayEstudiantes[i]->getCi() == ciBuscado) {
				return arrayEstudiantes[i];
			}
		}

		return nullptr;
	}

	void mostrar() {
		for (int i = 0; i < indice; i++) {
			arrayEstudiantes[i]->mostrar();
		}
	}

	Estudiante* estudianteQueMasPaga() {
	
		Estudiante* mayor = nullptr;

		for (int i = 0; i < indice; i++) {
			if (mayor== nullptr || arrayEstudiantes[i]->calcularMatricula() > mayor->calcularMatricula()) {
				mayor = arrayEstudiantes[i];
			}
		}

		return mayor;
	}
	~VectorEstudiantes() {
		for (int i = 0; i < indice; i++) {
			delete arrayEstudiantes[i];
		}
		delete[] arrayEstudiantes;
	}
};