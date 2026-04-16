#pragma once
#include "Persona.h"

class Estudiante : public Persona {
protected:
	int matricula;
	bool estado; //true = pago la matricula
public:
	Estudiante(string nombre, int ci, string tipo,int matricula , bool estado) : Persona(nombre,ci,tipo) {
		this->matricula = matricula;
		this->estado = estado;
	}

	bool getEstado() {
		return estado;
	}

	virtual void calcularTotal() = 0;

	virtual void mostrar() {
		Persona::mostrar();
		cout << "Matricula: " << matricula <<endl;
		cout << "Total:" << total<<endl;
	}
};