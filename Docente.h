#pragma once
#include "Persona.h"

class Docente : public Persona {
protected:
	int Pago;
	int cursosDados;
	bool estado; //true = Paso las entrevistas
	float bono;
	int total;
public:
	Docente(string nombre, int ci, string tipo, int Pago , int cursoDados , bool estado) : Persona(nombre, ci, tipo) {
		this->Pago = Pago;
		this->cursosDados = cursoDados;
		this->estado = estado;
		this->bono = 0;
		this->total = 0;
	}
	bool getEstado() {
		return estado;
	}
	void actualizarCursos() {
		cursosDados++;
	}
	virtual void actualizarTotal() = 0;
	
	virtual void mostrar() {
		Persona::mostrar();
		cout << "Pago: " << Pago << endl;
		cout << "Cursos Dados: " << cursosDados << endl;
		cout << "Bonos : " << bono << endl;
		cout << "Total : " << total << endl;
		
	}
};