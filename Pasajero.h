#pragma once
#include "Asiento.h"

class Pasajero {
private:
	int ci;
	string nombre;
	string apellido;
	Asiento* asientoAsignado;
public:
	Pasajero(int ci, string nombre, string apellido) {
		this->ci = ci;
		this->nombre = nombre;
		this->apellido = apellido;
		this->asientoAsignado = nullptr;
	}
	void asignarAsiento(Asiento* asiento) {
		asientoAsignado = asiento;
	}
	int getCi() {
		return ci;
	}
	Asiento* getAsiento() {
		return asientoAsignado;
	}
	void mostrar() {
		cout << ci << " - " << nombre << " " << apellido;
		if (asientoAsignado != nullptr)
			cout << " | Asiento: " << asientoAsignado->getCodigo();
		cout << endl;
	}
};
