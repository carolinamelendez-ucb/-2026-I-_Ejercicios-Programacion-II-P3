#pragma once
#include "Docente.h"


class TiempoCompleto :public Docente {
private:
	int antiguedad;
public:
	TiempoCompleto(string nombre, int ci, int pago, int antiguedad, bool estado) : Docente(nombre, ci, "TiempoCompleto", pago, 0 , estado) {
		this->antiguedad = antiguedad;
	}

	void mostrar() {
		Docente::mostrar();
		cout << "Antiguedad: " << antiguedad << endl;
	}

	void actualizarBono() {
		if (antiguedad >= 0 && antiguedad < 6) {
			bono = 0.05;
			
		}
		if (antiguedad > 5 && antiguedad < 11) {
			bono = 0.15;
			
		}
		if (antiguedad > 10 ) {
			bono = 0.25;
			
		}
	}
	
	void actualizarTotal() {
		actualizarBono();
		total = Pago + (Pago * bono);
	}
};