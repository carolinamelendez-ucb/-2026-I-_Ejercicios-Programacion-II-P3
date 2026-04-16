#pragma once
#include "Docente.h"


class MedioTiempo :public Docente {
public:
	MedioTiempo(string nombre, int ci, int Pago, int cursoDados, bool estado) : Docente(nombre, ci, "MedioTiempo" , Pago , cursoDados,estado) {

	}
	void mostrar() {
		Docente::mostrar();
	}

	void actualizarBono() {
		if (cursosDados >= 2) {
			bono = 0.10;
		}
	}
	void actualizarTotal() {
		actualizarBono();
		total = Pago+(Pago * bono);

	}
};