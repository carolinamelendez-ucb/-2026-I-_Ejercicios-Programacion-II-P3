#pragma once
#include<iostream>
#include<string>
#include "Equipo.h"
using namespace std;

class VectorEquipos {
private:
	Equipo** equipos;
	int tamanio;
	int indice; //cantidad
public:
	VectorEquipos(int tamanio) {
		this->equipos = new Equipo * [tamanio];
		this->indice = 0;
		this->tamanio = tamanio;
	}
	void agregar(Equipo* nuevoEquipo) {

		equipos[indice] = nuevoEquipo;
		indice++;
	}

	void registrarEquipo(Socio piloto, Socio copiloto, string nombreEquipo, string autoConQueCompetiran) {

		if (piloto.getCi() == copiloto.getCi()) {
			cout << "Error! UN EQUIPO NO FUE REGISTRADO. Un solo socio tenia el puetso de Piloto y Copiloto" << endl;
			return;
		}
		else {
			Equipo* nuevo = new Equipo(piloto, copiloto, nombreEquipo, autoConQueCompetiran);
			agregar(nuevo);
		}	
	}
	
	void buscarEquiposDeSocio(int ci) {

		for (int i = 0; i < indice; i++) {

			if (equipos[i]->getPiloto().getCi() == ci || equipos[i]->getCopiloto().getCi() == ci) {

				equipos[i]->mostrar();
			}
		}
	}

	void mostrar() {
		for( int i = 0; i < indice;i++ ) {
			cout << "Equipo " << i + 1 << endl;
			equipos[i]->mostrar();
			cout << endl;
		}
	}
	
};