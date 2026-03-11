#pragma once
#include "equipo.h"
class Competencia {
private:
	Equipo** equipos;
	int indice;
	int maxEquipos;
public:
	Competencia(int maxEquipos) {
		this->equipos = new Equipo * [maxEquipos];
		this->maxEquipos = maxEquipos;
		this->indice = 0;
	}
	bool socioRepetido(Equipo* nuevo) {
		for (int i = 0; i < indice; i++) {
			if (equipos[i]->getPiloto() == nuevo->getPiloto() || equipos[i]->getPiloto() == nuevo->getCopiloto() || equipos[i]->getCopiloto() == nuevo->getPiloto() || equipos[i]->getCopiloto() == nuevo->getCopiloto()) {
				return true;
			}
		}
		return false;
	}
	void agregarEquipo(Equipo* equipo) {
		if (indice >= maxEquipos) {
			cout << "Competencia a tope" << endl;
			return;
		}
		if (socioRepetido(equipo)) {
			cout << "Un socio ya participa con otro equipo" << endl;
			return;
		}
		equipos[indice] = equipo;
		indice++;
	}
	void mostrarCompetencia() {
		for (int i = 0; i < indice; i++) {
			cout << "Equipo: " << i + 1 << endl;
			equipos[i]->mostrarEquipo();
			cout << endl;
		}
	}
};