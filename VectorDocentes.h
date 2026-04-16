#pragma once
#include "Docente.h"
#include "TiempoCompleto.h"
#include "MedioTiempo.h"

class VectorDocentes {
private:
	int tamanio;
	int indice;
	Docente** docentes;
public:


	VectorDocentes(int tamanio)
		: tamanio(tamanio), indice(0)
	{
		this->docentes = new Docente * [tamanio];
	}

	void agregarDocente(Docente* nuevoDocente) {
		if (indice < tamanio) {
			docentes[indice] = nuevoDocente;
			indice++;
		}
	}
	Docente* buscarCiDuplicado(int ci) {
		for (int i = 0; i < indice; i++) {
			if (docentes[i]->getCi() == ci) {
				return docentes[i];
			}
		}
		return nullptr;
	}

	void mostrar() {
		for (int i = 0; i < indice; i++) {

			docentes[i]->mostrar();
			cout << endl;
		}
	}
	void actualizarPagosDocentes() {
		for (int i = 0; i < indice; i++) {

			docentes[i]->actualizarTotal();

		}
	}
};