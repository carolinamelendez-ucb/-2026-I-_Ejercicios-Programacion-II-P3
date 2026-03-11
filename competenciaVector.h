#pragma once
#include <iostream>
#include <string>
#include "competencia.h"
using namespace std;
class competenciaVector {
private:
	Competencia** competencias;
	int tamanio;
	int indice;
public:
	competenciaVector(int tamanio) {
		this->competencias = new Competencia * [tamanio];
		this->tamanio = tamanio;
		this->indice = 0;
	}
	void agregar(Competencia* nueCompetencia) {
		if (indice < tamanio) {
			competencias[indice] = nueCompetencia;
			indice++;
		}
	}
	void mostrarCompetenciaVector() {
		if (indice == 0) {
			cout << "No hay competencias registradas" << endl;
			return;
		}
		for (int i = 0; i < indice; i++) {
			cout << "Competencia " << i + 1 << endl;
			competencias[i]->mostrarCompetencia();
		}
	}
	Competencia* getCompetencia(int posicion) {
		if (posicion >= 0 && posicion < indice) {
			return competencias[posicion];
		}
		return nullptr;
	}
	int getIndice() {
		return indice;
	}
	};