#pragma once
#include "socio.h"
class equipo {
private:
	string nombreEquipo;
	string autorCarrera;
	socio* piloto;
	socio* copiloto;
public:
	equipo(string nombreEquipo, string autorCarrera, socio* p, socio* c) {
		this->nombreEquipo = nombreEquipo;
		this->autorCarrera = autorCarrera,
		this->piloto = p;
		this->copiloto = c;
	}
	void mostrar() {
		cout << "nombre" << nombreEquipo << endl;
		cout << "auto" << autorCarrera << endl;
		cout << "piloto" <<piloto->getNombre() << endl;
		cout << "copiloto" << copiloto->getNombre() << endl;
	}
};
