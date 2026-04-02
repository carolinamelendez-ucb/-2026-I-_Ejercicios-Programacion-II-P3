#pragma once
#include <iostream>
#include <string>
#include "Proyecto.h"
using namespace std;

class ProyectoExterno: public Proyecto {
private: 
	float monto;
	float comision;
public:
	ProyectoExterno (int codigo, string nombre, float monto, float comision)
		: Proyecto(nombre, codigo) {
		this->monto = monto;
		this->comision = comision;
	}
	float calcularCosto() {
		return monto + comision;
	}

	void mostrarInformacion() {
		Proyecto::mostrarInformacion();
		cout << "Costo del Proyecto Externo: " << calcularCosto() << endl;
	}


};