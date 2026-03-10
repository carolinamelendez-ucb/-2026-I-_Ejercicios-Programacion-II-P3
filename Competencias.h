#pragma once
#include<iostream>
#include<string>
#include "Equipo.h"
using namespace std;

class Competencia {
private:
	string nombre;
	Equipo** equipos;
	int tamanio;
	int indice;
public: 
	Competencia(string nombre, int tamanio) {
		this->nombre = nombre;
		this->tamanio = tamanio;
		this->indice = 0;
		equipos = new Equipo * [tamanio];
	}
	
	bool socioRepetido(Equipo* nuevoEquipo) {

		for (int i = 0; i < indice; i++) {

			if (equipos[i]->getPiloto().getCi() == nuevoEquipo->getPiloto().getCi() ||
				equipos[i]->getCopiloto().getCi() == nuevoEquipo->getPiloto().getCi() ||
				equipos[i]->getPiloto().getCi() == nuevoEquipo->getCopiloto().getCi() ||
				equipos[i]->getCopiloto().getCi() == nuevoEquipo->getCopiloto().getCi()) {
				return true;
			}
		}
		return false;
	}

	void agregarEquipo(Equipo* nuevoEquipo) {
		if (socioRepetido(nuevoEquipo)) {
			cout << "Error! Un socio ya participa en otro equipo de esta competencia" << endl;
			return;
		}
		equipos[indice] = nuevoEquipo;
		indice++;
	}
	void mostrar() {

		cout << "Competencia: " << nombre << endl;
		for (int i = 0; i < indice; i++) {
			equipos[i]->mostrar();
		}

	}

};